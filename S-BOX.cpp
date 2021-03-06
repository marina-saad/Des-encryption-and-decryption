
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <sstream>
#include <cassert>
#include <bitset>
#include <cstdlib>
#include <iomanip>
using namespace std;

string HexToBin(string hexaDecimal )
{
	//int i=0;
	string Binary;
	for(long long i=0;i<hexaDecimal.length();i++)
    {
		string h=hexaDecimal.substr(i,1);
		if(h=="0")
         {
			 Binary+="0000";
		 }
		else if(h=="1")
			 Binary +="0001";
		else if(h=="2")
			 Binary +="0010";
		else if(h=="3")
			 Binary +="0011";
		else if(h=="4")
			 Binary +="0100";
		else if(h=="5")
			 Binary +="0101";
        else if(h=="6")
			 Binary +="0110";
		else if(h=="7")
			 Binary +="0111";
		else if(h=="8")
			 Binary +="1000";
		else if(h=="9")
			 Binary +="1001";
		else if(h=="A")
			 Binary +="1010";
		else if(h=="B")
			 Binary +="1011";
		else if(h=="C")
			 Binary +="1100";
		else if(h=="D")
			 Binary +="1101";
		else if(h=="E")
			 Binary +="1110";
		else if(h=="F")
			 Binary +="1111";
    }
	return Binary;
}

int BinToDec(string number)
{
    long long result = 0, pow = 1;
	for ( long long i = number.length() - 1; i >= 0; --i, pow <<= 1 )
        result += (number[i] - '0') * pow;

    return result;
}

string DecToBin(long long number)
{
    if ( number == 0 ) return "0";
    if ( number == 1 ) return "1";

    if ( number % 2 == 0 )
        return DecToBin(number / 2) + "0";
    else
        return DecToBin(number / 2) + "1";
}

string SBox(string input)
{
		long long Sbox [8][4][16]=
	{
	{{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},{0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
	{4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},{15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}},

	{{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},{3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
	{0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},{13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}},

	{{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},{13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
	{13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},{1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}},

	{{7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},{13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
	{10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},{3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}},

	{{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},{14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
	{4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},{11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}},

	{{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},{10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
	{9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},{4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}},

	{{4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},{13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
	{1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},{6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}},

	{{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},{1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
	{7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},{2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}}
	};
	string inputINbin=HexToBin(input);
	int Swhat=0;
	string output;
	for(long long i=0;i<inputINbin.length();)
	{
		//cout<<i<<endl<<"s "<<Swhat;
		string temp=inputINbin.substr(i,6);
	//	cout<<temp<<endl;
		string temptemp=temp.substr(0,1)+temp.substr(6-1,1);
		int row=BinToDec(temptemp);
		string temptemptemp=temp.substr(1,4);
		int column=BinToDec(temptemptemp);
		long long result;
		
		
		//cout<<temptemp<<"  "<<row<<endl<<temptemptemp<<"  "<<column<<endl;
		//for(int j=0;j<4;j++)
		{
			//for(int m=0;m<16;m++)
			{
				result =Sbox[Swhat][row][column];
			}
		}
		stringstream ss;
		ss<<hex<<result;
		string finalResult(ss.str());
		output+=finalResult;
		Swhat++;
		i=i+6;
		
	}

	for(long long i=0;i<output.length();)
	{
		string h=output.substr(i,1);
			if(h=="a")
			output.replace(i,1,"A");
		else if (h=="b")
			output.replace(i,1,"B");
		else if (h=="c")
			output.replace(i,1,"C");
		else if (h=="d")
			output.replace(i,1,"D");
		else if (h=="e")
			output.replace(i,1,"E");
		else if (h=="f")
			output.replace(i,1,"F");
		else 
			i++;
	}
	return output;
}

int main()
{
	string input;
	cin>>input;
	//cout<<HexToBin(input)<<endl;

	cout<<SBox(input)<<endl;
	return 0;
}
