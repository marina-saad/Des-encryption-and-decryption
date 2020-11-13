
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
	//int i=0;
	string hexa="";
	vector<string>binaryInVec;
	for(long long i=0;i<binary.length();)
	{
		string h=binary.substr(i,4);
		
	
	//for(int i=0;i<binaryInVec.size();i++)
    {
	//	cout<<binaryInVec[i]<<endl;
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
	//cout<<theValue<<endl;
	//string theValueINHEX=BinToHEX(theValue);
	//long long outputINdec=BinToDec(theValue);
	string result=BinToHEX(theValue);//outputINdec<<endl;

	//cout<<result<<endl;
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

void keyGeneration(string key64)
{	string key64INbin=HexToBin(key64);
	string test=PC1(key64INbin);
	//cout<<test<<endl;
	string PC1outINbin=HexToBin(test);
	vector<string> leftout;
	string leftshift1,leftshift2,temp=PC1outINbin;
	int Rotations[16]= { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };
	          string half1_28,half2_28;
			   half1_28=temp.substr(0,28);
			   half2_28=temp.substr(28,28);
			   
	for(int i=0;i<16;i++)
	{
		//cout<<"Round:  "<<i+1<<endl;
		//cout<<"NO of rotation: "<<Rotations[i]<<endl;
		   
		for(int h=0;h<Rotations[i];h++)
		{
			//cout<<"half1_28 "<<half1_28<<endl;
			leftshift1="",leftshift2="";
			for(int j=0;j<half1_28.size();j++)
		   {
			   
			   if(j==half1_28.size()-1)
				   leftshift1+=half1_28.substr(0,1);

			   leftshift1+=half1_28.substr(j+1,1);   
		   } 
			//cout<<leftshift1<<endl;
            //cout<<"half2_28 "<<half2_28<<endl;
			for(int j=0;j<half2_28.size();j++)
			{
			if(j==half2_28.size()-1)
				   leftshift2+=half2_28.substr(0,1);

			   leftshift2+=half2_28.substr(j+1,1);
			}
			//cout<<leftshift2<<endl;
			half1_28=leftshift1;
			half2_28=leftshift2;
		//	cout<<leftshift1+leftshift2<<endl;
			//   leftshift="";
		}
		leftout.push_back(leftshift1+leftshift2);

		//cout<<leftshift<<endl;
	}
	vector<string>afterSHIFTtoPC2;
	vector<string>result;
	for(int i=0;i<leftout.size();i++)
	{
		//cout<<leftout[i]<<endl;
		//afterSHIFTtoPC2.push_back(BinToHEX(leftout[i]));
		//string test=PC2(leftout[i]);
	result.push_back(PC2(leftout[i]));
		cout<<result[i]<<endl;

	}
}

int main()
{
	string key64;
	cin>>key64;
	keyGeneration(key64);
//	cout<<PC1outINbin<<endl;

	
	
	return 0;
}
