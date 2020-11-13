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


void InversePermu(vector<long long>permu,long long S)
{
	vector<long long>setOFnum,Inv;
	for(long long i=0;i<S;i++)
		setOFnum.push_back(i+1);

	for(long long i=0;i<setOFnum.size();i++)
	{
		for(long long j=0;j<permu.size();j++)
		{
			if(permu[j]==setOFnum[i])
			{	
				Inv.push_back(j+1);
				

			}
		
		}
	
	}
	for(long long i=0;i<Inv.size();i++)
		cout<<Inv[i]<<" ";
	cout<<endl;
}


int main()
{
	long long S,temp;
	vector<long long> PermNums;

	cin>>S;
	for(long long i=0;i<S;i++)
	{
		cin>>temp;
		PermNums.push_back(temp);
	}
	bool check;
	vector<long>setOFnum;
	for(long long i=0;i<S;i++)
		setOFnum.push_back(i+1);
	/*
	for(int i=0;i<setOFnum.size();i++)
	{
	if ( std::find_if(PermNums.begin(), PermNums.end(), setOFnum[i]) != PermNums.end() )
		
		check=1;
        else
            { 
				check=0;
	         }
	
	}
	*/
	for(long long i=0;i<PermNums.size();i++)
	{
		
		long long j;
		for(j=0;j<setOFnum.size();j++)
		{
			if(PermNums[i]==setOFnum[j]&&i<setOFnum.size())
			{
				check=1;
				break;
			}
			else 
			{check=0; }//break;}
		}
		if(check==0&&j>setOFnum.size())
			break;
		//while(i<PermNums.size())
		if(i+1<PermNums.size()&&PermNums[i+1]==PermNums[i])
			{check=0; break;}
	}
	//cout<<check;
	if(check==1)
	InversePermu(PermNums,S);
	else
		cout<<"IMPOSSIBLE"<<endl;
	return 0;
}





