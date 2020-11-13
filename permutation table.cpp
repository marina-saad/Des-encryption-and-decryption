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

string DecToBin(long long number)
{
    if ( number == 0 ) return "0";
    if ( number == 1 ) return "1";

    if ( number % 2 == 0 )
        return DecToBin(number / 2) + "0";
    else
        return DecToBin(number / 2) + "1";
}
int BinToDec(string number)
{
    long long result = 0, pow = 1;
	for ( long long i = number.length() - 1; i >= 0; --i, pow <<= 1 )
        result += (number[i] - '0') * pow;

    return result;
}
void StraightPermutation (vector<long long> Permu,string PlainINbin)
{
	string theValue;
	vector <string> out;
	for(long long i=0;i<Permu.size();i++)
	{
		long long perm;
		perm=Permu[i];
		theValue += PlainINbin.substr(perm-1,1);
	
	}
	
	long long outputINdec=BinToDec(theValue);
	

		
	std::stringstream stream;
	stream << std::hex << outputINdec;
    std::string result( stream.str() );
	

	//cout<<outputINdec<<endl;
	for(int i=0;i<result.length();)
	{
		if(result.substr(i,1)=="a")
			result.replace(i,1,"A");
		else if (result.substr(i,1)=="b")
			result.replace(i,1,"B");
		else if (result.substr(i,1)=="c")
			result.replace(i,1,"C");
		else if (result.substr(i,1)=="d")
			result.replace(i,1,"D");
		else if (result.substr(i,1)=="e")
			result.replace(i,1,"E");
		else if (result.substr(i,1)=="f")
			result.replace(i,1,"F");
		else 
			i++;
	}
		cout<<result<<endl;
	
}


string HexToBin(string binary)
{
	//int i=0;
	string hexa;
	vector<string>binaryInVec;
	for(int i=0;i<binary.size()/4;i+4)
	{
		binaryInVec .push_back(binary.substr(i,4));
	}
	for(int i=0;i<binaryInVec.size();i++)
    {
		if(binaryInVec[i]=="0000")
         {
			 hexa+="0";
		 }
		else if(binaryInVec[i]=="0001")
			hexa +="1";
		else if(binaryInVec[i]=="0010")
			 hexa +="2";
		else if(binaryInVec[i]=="0011")
			hexa +="3";
		else if(binaryInVec[i]=="0100")
			hexa +="4";
		else if(binaryInVec[i]=="0101")
			hexa +="5";
		else if(binaryInVec[i]=="0110")
			hexa +="6";
		else if(binaryInVec[i]=="0111")
			 hexa +="7";
		else if(binaryInVec[i]=="1000")
			 hexa +="8";
		else if(binaryInVec[i]=="1001")
			 hexa +="9";
		else if(binaryInVec[i]=="1010")
			 hexa +="A";
		else if(binaryInVec[i]=="1011")
			 hexa +="B";
		else if(binaryInVec[i]=="1100")
			 hexa +="C";
		else if(binaryInVec[i]=="1101")
			 hexa +="D";
		else if(binaryInVec[i]=="1110")
			 hexa +="E";
		else if(binaryInVec[i]=="1111")
			 hexa +="F";
           
         
         
    }
	return hexa;
}

string HexToBin(vector<string> hexaDecimal )
{
	//int i=0;
	string Binary;
	for(int i=0;i<hexaDecimal.size();i++)
    {
         if(hexaDecimal[i]=="0")
         {
			 Binary+="0000";
		 }
		 else if(hexaDecimal[i]=="1")
			 Binary +="0001";
		 else if(hexaDecimal[i]=="2")
			 Binary +="0010";
		 else if(hexaDecimal[i]=="3")
			 Binary +="0011";
         else if(hexaDecimal[i]=="4")
			 Binary +="0100";
		  else if(hexaDecimal[i]=="5")
			 Binary +="0101";
          else if(hexaDecimal[i]=="6")
			 Binary +="0110";
          else if(hexaDecimal[i]=="7")
			 Binary +="0111";
		  else if(hexaDecimal[i]=="8")
			 Binary +="1000";
          else if(hexaDecimal[i]=="9")
			 Binary +="1001";
          else if(hexaDecimal[i]=="A")
			 Binary +="1010";
          else if(hexaDecimal[i]=="B")
			 Binary +="1011";
          else if(hexaDecimal[i]=="C")
			 Binary +="1100";
		  else if(hexaDecimal[i]=="D")
			 Binary +="1101";
          else if(hexaDecimal[i]=="E")
			 Binary +="1110";
          else if(hexaDecimal[i]=="F")
			 Binary +="1111";
           
         
         
    }
	return Binary;
}



	/*
	
int main()
{
	long long S,N,temp;
	vector<long long> PermNums;
	//long long plainTextInHEX;
	vector<string> plainTextInHEX;
	cin>>S;
	for(long long i=0;i<S;i++)
	{
		cin>>temp;
		PermNums.push_back(temp);
	}
	cin>>N;
	string h;
	cin>>hex>>h;
	for(int i=0;i<N/4;i++)
	{
		
	
		plainTextInHEX.push_back(h.substr(i,1));
	}
	
	//cout<<S<<endl;
	/*for(int i=0;i<PermNums.size();i++)
		cout<<PermNums[i]<<"   ";
	cout<<endl<<N<<"     "<<plainTextInHEX<<endl<<endl;*/


//	string plainTextINbin=DecToBin(plainTextInHEX);

	//cout<<plainTextINbin<<endl;

	/*string test=HexToBin(plainTextInHEX);
	//cout<<test<<endl;
		StraightPermutation(PermNums,test);
	
	return 0;
}
	*/