/*
	Given two strings, find the minimum number of operations to convert one string to another.
	Input:   str1 = "geek", str2 = "gesek"
	Output:  1
	Explanation: We can convert str1 into str2 by inserting a 's'.

	Input:   str1 = "cat", str2 = "cut"
	Output:  1
	Explanation: We can convert str1 into str2 by replacing 'a' with 'u'.

	Input:   str1 = "sunday", str2 = "saturday"
	Output:  3
	Explanation:  Last three and first characters are same.  We basically
	need to convert "un" to "atur".  This can be done using
	three operations. Replace 'n' with 'r', insert t, insert a.

	There are two methods to solve this in dynamic programming, both of which have been done here. 
	One is thinking about the subproblem in the tems of index of the strings (dp_method1).
	The second is to think about the subproblem in terms of lengths of the substrings (dp_method2, recursive).

*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

int min_no(int x, int y, int z)
{
	int min=x;
	int minno=1;
	if(y<x)
	{
		min=y;
		minno=2;
	}
	if(z<min)
	{
		min=z;
		minno=3;
	}		
	return minno;
}

int dp_method1(string x,string y, int m, int n)
{
	vector <vector<int> > dp(m+1,vector<int> (n+1,0));
	//operation 1 for replace, 2 for delete, 3 for insert
	map < pair<int,int>, string> operation;
	map <pair <int,int>, pair<int,int> > parent;
	
	for(int i=m;i>=0;i--)
	{
		for(int j=n;j>=0;j--)
		{
			if(i==m) //if i is at m(end), only way is to insert all remaining j characters 
			{
				dp[i][j] = n-j; 
				
				ostringstream str;
				if(n-j>0)
				{
					str<<"Insert: ";
					for(int t=j;t<n;t++)
						str<<y[t]<<",";
				}
				operation[{i,j}] = str.str();
				parent[{i,j}] = {-1,-1};
			}
			else if(j==n) //if j is at n(end), only way is to delete all remaining x characters
			{
				dp[i][j] = m-i;
				ostringstream str;
				if(m-i>0)
				{
					str<<"Delete: ";
					for(int t=i;t<m;t++)
						str<<x[t]<<",";
				}
				operation[{i,j}] = str.str();
				parent[{i,j}] = {-1,-1};
			}
			
			else if(x[i]==y[j])
			{
				dp[i][j]=dp[i+1][j+1];
				parent[{i,j}] = {i+1,j+1};
			}
			else
			{
				int ans1 = 1 + dp[i+1][j+1]; //replace
				int ans2 = 1 + dp[i+1][j]; //delete
				int ans3 = 1 + dp[i][j+1]; //insert
				int min = (ans1<ans2)? ans1: ans2;
				min = (min<ans3)? min: ans3;
				dp[i][j] = min;
				
				int minno = min_no(ans1,ans2,ans3);
				switch(minno)
				{
					case 1: {
								ostringstream str;
								str<<"Replace "<<x[i]<<" with "<<y[j]<<". ";
								operation[{i,j}] = str.str();
								parent[{i,j}] = {i+1,j+1};
								
							}
							break;
					case 2: {
								ostringstream str;
								str<<"Delete "<<x[i]<<". ";
								operation[{i,j}] = str.str();
								parent[{i,j}] = {i+1,j};
							}
							break; 
					case 3: {
								ostringstream str;
								str<< "Insert "<<y[j]<<". ";
								operation[{i,j}] = str.str();
								parent[{i,j}] = {i,j+1};
							}
							break;
				}
				
			}
			
		}
	}
	cout<<endl;
	pair <int,int> p = make_pair(0,0);
	while(p.first!=-1 && p.second!=-1)
	{
		cout<<operation[p]<<endl;
		p = parent[p];
	}
	
	return dp[0][0];
}


int recursive_method2(string x, string y, int m, int n)
{
	//modifying string x
	
	if(m==0) return n; //if first string empty, need to insert all of second string into first
	if(n==0) return m; //if second string empty, need to delete all of first string 
	if(x[m-1]==y[n-1])
		return recursive_method2(x,y,m-1,n-1);
	
	int ans1 = 1 + recursive_method2(x,y,m-1,n-1); //replace
	int ans2 = 1 + recursive_method2(x,y,m,n-1); //insert 
	int ans3 = 1 + recursive_method2(x,y,m-1,n); //delete 
	int min = (ans1<ans2)? ans1: ans2;
	min = (min<ans3)? min: ans3;
	return min;	
}


int dp_method2(string x, string y, int lengthx, int lengthy)
{
	map <pair<int,int>,int> dp;
	for(int m=0;m<=lengthx;m++)
	{
		for(int n=0;n<=lengthy;n++)
		{
			if(m==0)
				dp[make_pair(m,n)]=n;
			else if(n==0)
				dp[make_pair(m,n)]=m;
			
			else if(x[m-1]==y[n-1])
				dp[make_pair(m,n)]=dp[make_pair(m-1,n-1)];
			else
			{
				int ans1 = 1 + dp[make_pair(m-1,n-1)];
				int ans2 = 1 + dp[make_pair(m,n-1)];
				int ans3 = 1 + dp[make_pair(m-1,n)];
				int min = (ans1<ans2)? ans1: ans2;
				min = (min<ans3)? min: ans3;
				dp[make_pair(m,n)] = min;
			}
		}	
	}
	return dp[make_pair(lengthx,lengthy)];	
}

int main()
{
	string str1 = "hieroglyphology"; 
    string str2 = "michaelangelo"; 
	
	cout<<dp_method1(str1,str2,str1.length(),str2.length())<<endl;
	cout<<dp_method2(str1,str2,str1.length(),str2.length())<<endl;
	
	return 0;
}