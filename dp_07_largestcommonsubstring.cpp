/*
	Given two strings, find the length longest common substring present in both strings.
	Done using dynamic programming. 

	Input:
	2
	6 6
	ABCDGH
	ACDGHR

	3 2
	ABC
	AC

	Output:
	4
	1

	Example:
	Testcase 1: CDGH is the longest substring present in both of the strings.
	Testcase 2: 'A' or 'C' are the longest common substring. 
*/

#include <iostream>
#include <vector>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n1,n2;
	    string s1{},s2{};
	    cin>>n1>>n2;
	    cin>>s1;
	    cin>>s2;
	    
	    vector <vector<int> > dp (n1+1,vector<int> (n2+1,0));
	    
	    int result = 0;
	    for(int i=n1-1;i>=0;i--)
	    {
	        for(int j=n2-1;j>=0;j--)
	        {
	            if(s1[i]==s2[j])
	                {
	                    dp[i][j]=dp[i+1][j+1] + 1;
	                    result = (result>dp[i][j])? result: dp[i][j];
	                }
	            else 
	            {
	                dp[i][j]=0;
	            }
	        }
	    }
	    //cout<<dp[0][0];
	    cout<<result<<endl;
	}
	return 0;
}