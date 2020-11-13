#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <sstream>
#include <cassert>
#include <bitset>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
using namespace std;
void invers(vector<int> setOFnums,int pIN,vector<int>permutaionNums)
{
	vector<int> ss,sss;
	for(int i=0;i<pIN;i++)
	{
		setOFnums.push_back(i+1);
	}
	for(int i=0;i<setOFnums.size();i++)
	{
		for(int j=0;j<permutaionNums.size();j++)
		{
			if(permutaionNums[j]==setOFnums[i])
			{
				ss.push_back(j+1);
			}
		}
	}

//	for(int i=0;i<ss.size();i++)
	//	cout<<ss[i]<<" ";
	//cout<<endl;
	for(int i=0;i<ss.size();i++)
	{
		if(i<ss.size()-1)
		{
			if(permutaionNums[ss[i]-1]==permutaionNums[ss[i+1]-1])
				{
					//sss.push_back(ss[i]);
					//ss.erase(ss.begin()+i);
					ss.erase(ss.begin()+i+1);
					//i++;
			    }
			
				//	
			
		}
	//	else if(i==ss.size()-1)
		//		ss.push_back(ss[i]);
	}
	//cout<<endl;
	//sort(ss.begin(),ss.end());
	for(int i=0;i<ss.size();i++)
		cout<<ss[i]<<" ";
	cout<<endl;
}
int main()
{
	int pIN,pOUT;bool check=NULL;
	vector<int> permutaionNums,setOFnums,ss,sss;
	cin>>pIN>>pOUT;
	for(int i=0;i<pOUT;i++)
	{
		int temp;
		cin>>temp;
		permutaionNums.push_back(temp);
	}

	if(pOUT<pIN)
		{
			cout<<"IMPOSSIBLE"<<endl;
			return 0;
	}
	
	for(long long i=0;i<permutaionNums.size();i++)
	{
		
		long long j;
		for(j=0;j<setOFnums.size();j++)
		{
			if(permutaionNums[i]==setOFnums[j]&&j<setOFnums.size())
			{
				check=1;
				break;
			}
			else 
			{check=0; break;}
		}
		if(i+1<permutaionNums.size()&&permutaionNums[i+1]==permutaionNums[i])
			{check=1; break;}
		if(check==0&&j>setOFnums.size())
			break;
		//while(i<PermNums.size())
		
	}
	//cout<<check;
	if(check==1)
		invers(setOFnums,pIN,permutaionNums);
	else if(check==0 )//|| pOUT<pIN)
		cout<<"IMPOSSIBLE"<<endl;

	/*
	cout<<endl;
	bool check =NULL;

	for(long long i=0;i<permutaionNums.size();i++)
	{
		
		long long j;
		for(j=0;j<setOFnums.size();j++)
		{
			if(permutaionNums[i]==setOFnums[j]&&i<setOFnums.size())
			{
				check=1;
				break;
			}
			else //if(permutaionNums[i]!=setOFnums[j])
			{check=0; cout<<" ggg ";
			}//break;}
			
		}
		if(check==0&&j>setOFnums.size())
			break;
		//while(i<PermNums.size())
		if(i+1<permutaionNums.size()&&permutaionNums[i+1]==permutaionNums[i])
			{check=1; }
	}
	
	if(check==1)
		invers(setOFnums,pIN,permutaionNums);
	else
		cout<<"IMPOSSIBLE"<<endl;*/
	return 0;
}