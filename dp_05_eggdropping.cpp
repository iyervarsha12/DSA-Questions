/*
	Egg dropping puzzle (question explained in https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/)
	(Done via dynamic programming). 
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int max(int val1,int val2)
{
    if(val1>val2) return val1;
    else return val2;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n; //no of eggs
	    cin>>n;
	    int k; //no of floors
	    cin>>k;
	    
	    vector <vector<int> > dp(n+1,vector<int>(k+1,0));
	    for(int j=0;j<=k;j++)
	        dp[1][j]=j;
	    
	    for(int i=1;i<=n;i++)
	        dp[i][0]=0;
	   
	   for(int i=2;i<=n;i++)
	   {
	       for(int j=1;j<=k;j++)
	       {
	           if(i>j)
	            dp[i][j]=dp[i-1][j];
	           else
	           {
    	           int min=INT_MAX;
    	           for(int k=1;k<=j;k++)
    	           {
    	               int ans = 1+ max(dp[i-1][k-1],dp[i][j-k]);
    	               if(min>ans)
    	                min=ans;
    	           }
    	           dp[i][j]=min;
	           }
	       }
	   }
	   cout<<dp[n][k]<<endl;
	}
	return 0;
}