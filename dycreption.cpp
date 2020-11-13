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

string BinToHEX(string binary)
{
	string hexa="";
	vector<string>binaryInVec;
	for(long long i=0;i<binary.length();)
	{
		string h=binary.substr(i,4);
    {
		if(h=="0000")
			 hexa+="0";
		else if(h=="0001")
			hexa +="1";
		else if(h=="0010")
			 hexa +="2";
		else if(h=="0011")
			hexa +="3";
		else if(h=="0100")
			hexa +="4";
		else if(h=="0101")
			hexa +="5";
		else if(h=="0110")
			hexa +="6";
		else if(h=="0111")
			 hexa +="7";
		else if(h=="1000")
			 hexa +="8";
		else if(h=="1001")
			 hexa +="9";
		else if(h=="1010")
			 hexa +="A";
		else if(h=="1011")
			 hexa +="B";
		else if(h=="1100")
			 hexa +="C";
		else if(h=="1101")
			 hexa +="D";
		else if(h=="1110")
			 hexa +="E";
		else if(h=="1111")
			 hexa +="F";   
		i=i+4;   
	}}
	return hexa;
}

long long BinToDec(string number)
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

static inline unsigned int value(char c)
{
    if (c >= '0' && c <= '9') { return c - '0';      }
    if (c >= 'a' && c <= 'f') { return c - 'a' + 10; }
    if (c >= 'A' && c <= 'F') { return c - 'A' + 10; }
    return -1;
}

std::string str_xor(std::string const & s1, std::string const & s2)
{
    assert(s1.length() == s2.length());

    static char const alphabet[] = "0123456789ABCDEF";

    std::string result;
    result.reserve(s1.length());

    for (std::size_t i = 0; i != s1.length(); ++i)
    { 
        unsigned int v = value(s1[i]) ^ value(s2[i]);

        assert(v < sizeof alphabet);

        result.push_back(alphabet[v]);
    }

    return result;
}

string IP (string PlainINbin)
{
	long long Permu[64] 
	= { 58, 50, 42, 34, 26, 18, 10, 2, 
		60, 52, 44, 36, 28, 20, 12, 4, 
		62, 54, 46, 38, 30, 22, 14, 6, 
		64, 56, 48, 40, 32, 24, 16, 8, 
		57, 49, 41, 33, 25, 17, 9, 1, 
		59, 51, 43, 35, 27, 19, 11, 3, 
		61, 53, 45, 37, 29, 21, 13, 5, 
		63, 55, 47, 39, 31, 23, 15, 7 };
	string theValue;
	vector <string> out;
	for(long long i=0;i<64;i++)
	{
		long long perm;
		perm=Permu[i];
		theValue += PlainINbin.substr(perm-1,1);
	
	}
	string result=BinToHEX(theValue);
	return result;	
}

string InversePermu (string PlainINbin)
{
	long long Permu[64] 
	= {40, 8, 48, 16, 56, 24, 64, 32, 
	   39, 7, 47, 15, 55, 23, 63, 31, 
	   38, 6, 46, 14, 54, 22, 62, 30, 
	   37, 5, 45, 13, 53, 21, 61, 29, 
	   36, 4, 44, 12, 52, 20, 60, 28, 
	   35, 3, 43, 11, 51, 19, 59, 27, 
	   34, 2, 42, 10, 50, 18, 58, 26, 
	   33, 1, 41, 9, 49, 17, 57, 25};
	string theValue;
	vector <string> out;
	for(long long i=0;i<64;i++)
	{
		long long perm;
		perm=Permu[i];
		theValue += PlainINbin.substr(perm-1,1);
	
	}
	string result=BinToHEX(theValue);
	return result;	
}

string PC1 (string PlainINbin)
{
	long long Permu[56] 
	= { 57, 49, 41, 33, 25, 17, 9, 1,
		58, 50, 42, 34, 26, 18, 10, 2, 
		59, 51, 43, 35, 27, 19, 11, 3, 
		60, 52, 44, 36, 63, 55, 47, 39, 
		31, 23, 15, 7, 62, 54, 46, 38, 
		30, 22, 14, 6, 61, 53, 45, 37, 
		29, 21, 13, 5, 28, 20, 12, 4 };
	string theValue;
	vector <string> out;
	for(long long i=0;i<56;i++)
	{
		long long perm;
		perm=Permu[i];
		theValue += PlainINbin.substr(perm-1,1);
	
	}
	string result=BinToHEX(theValue);
	return result;	
}

string PC2 (string PlainINbin)
{
	long long Permu[48] =  { 14, 17, 11, 24, 1, 5, 3, 28, 
		                     15, 6, 21, 10, 23, 19, 12, 4, 
							 26, 8, 16, 7, 27, 20, 13, 2, 
							 41, 52, 31, 37, 47, 55, 30, 40, 
							 51, 45, 33, 48, 44, 49, 39, 56, 
							 34, 53, 46, 42, 50, 36, 29, 32 };
	string theValue;
	vector <string> out;
	for(long long i=0;i<48;i++)
	{
		long long perm;
		perm=Permu[i];
		theValue += PlainINbin.substr(perm-1,1);
	
	}

	string result=BinToHEX(theValue);

	return result;
	
}

vector<string> keyGeneration(string key64)
{	string key64INbin=HexToBin(key64);
	string test=PC1(key64INbin);
	string PC1outINbin=HexToBin(test);
	vector<string> leftout;
	string leftshift1,leftshift2,temp=PC1outINbin;
	int Rotations[16]= { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };
	          string half1_28,half2_28;
			   half1_28=temp.substr(0,28);
			   half2_28=temp.substr(28,28);
			   
	for(int i=0;i<16;i++)
	{   
		for(int h=0;h<Rotations[i];h++)
		{
			leftshift1="",leftshift2="";
			for(int j=0;j<half1_28.size();j++)
		   {
			   
			   if(j==half1_28.size()-1)
				   leftshift1+=half1_28.substr(0,1);

			   leftshift1+=half1_28.substr(j+1,1);   
		   } 

			for(int j=0;j<half2_28.size();j++)
			{
			if(j==half2_28.size()-1)
				   leftshift2+=half2_28.substr(0,1);

			   leftshift2+=half2_28.substr(j+1,1);
			}
			half1_28=leftshift1;
			half2_28=leftshift2;
		}
		leftout.push_back(leftshift1+leftshift2);
	}
	vector<string>afterSHIFTtoPC2;
	vector<string>result;
	for(int i=0;i<leftout.size();i++)
	{
	result.push_back(PC2(leftout[i]));
	//	cout<<result[i]<<endl;
	}
	return result;
}

string EP (string PlainINbin)
{
	long long Permu[48] 
	= {32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9, 8, 9,
	   10, 11, 12, 13, 12, 13, 14, 15, 16, 17, 16, 
	   17, 18, 19, 20, 21,20, 21, 22, 23, 24, 25, 
	   24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1};
	string theValue;
	vector <string> out;
	for(long long i=0;i<48;i++)
	{
		long long perm;
		perm=Permu[i];
		theValue += PlainINbin.substr(perm-1,1);
	}
	string result=BinToHEX(theValue);
	return result;
	
}

string SP (string PlainINbin)
{
	long long Permu[32] = {16, 7, 20, 21, 29, 12, 28, 17, 1, 
		                   15, 23, 26, 5, 18, 31, 10, 2, 8, 
						   24, 14, 32, 27, 3, 9, 19, 13, 30,
						   6, 22, 11, 4, 25 };
	string theValue;
	vector <string> out;
	for(long long i=0;i<32;i++)
	{
		long long perm;
		perm=Permu[i];
		theValue += PlainINbin.substr(perm-1,1);
	}
	string result=BinToHEX(theValue);
	return result;
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

		{
				result =Sbox[Swhat][row][column];
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



string DesFunc(string right,string left,vector <string>keysGenerated)
{
	int lastTOfirst=15;
		for(int j=0;j<16;j++)
		{
	//		cout<<"j "<<j<<endl;
	//		cout<<"right "<<right<<endl<<"left "<<left<<endl;
		string ExpantionOUT=EP(right);
	//	cout<<"EXPANTION "<<HexToBin(ExpantionOUT)<<endl<<keysGenerated[j]<<endl;
		string XorOUT=str_xor(ExpantionOUT,keysGenerated[lastTOfirst]);
	//	cout<<"1st XOR "<<HexToBin(XorOUT)<<endl;
		string SBoxOUT=SBox(XorOUT);
//		cout<<"S_BOX "<<HexToBin(SBoxOUT)<<endl;
		string permutaionOUT=SP(HexToBin(SBoxOUT));
	//	cout<<"PERMUTATION BEFOR THE 2ND XOR "<<HexToBin(permutaionOUT)<<endl;
		string left_perm_XOR=str_xor(permutaionOUT,BinToHEX(left));
	//	cout<<"the 2nd XOR "<<HexToBin(left_perm_XOR)<<endl;
		left=right;
		right=HexToBin(left_perm_XOR);
		lastTOfirst--;
		}
		string output=right+left;
		string InversOUT=InversePermu(output);
		return InversOUT;
}
int main()
{
	string key64;
	cin>>key64;
	vector<string> keysGenerated=keyGeneration(key64);
/*	for(int i=0;i<keysGenerated.size();i++)
	{
		cout<<keysGenerated[i]<<endl;
	}*/
	string plainText;
	cin>>plainText;
	string plainTextINbin=HexToBin(plainText);
	string InitialPermutationOUT=IP(plainTextINbin);
	//cout<<InitialPermutationOUT<<endl;
	long long NoOFrounds;
	cin>>NoOFrounds;
    string InversOUT;

   string test=InitialPermutationOUT;
   string left=HexToBin(InitialPermutationOUT).substr(0,32);
//	cout<<"left  "<<left<<endl;
	string right=HexToBin(InitialPermutationOUT).substr(32,32);
//	cout<<"right "<<right<<endl;
	if(NoOFrounds==0)
		cout<<plainText<<endl;
	else{
		for(long long i=0;i<NoOFrounds;i++)
	{
	//	cout<<"i "<<i<<endl;
	
	
		
	test=DesFunc(right,left,keysGenerated);
          
	string inversINbin=HexToBin(test);
	string again=IP(inversINbin);
	//	  cout<<inversINbin<<endl;
		//if()
	//	
		left= HexToBin(again).substr(0,32);
		right=HexToBin(again).substr(32,32);
		
	}
	cout<<test<<endl;
	}
	
	return 0;
}
