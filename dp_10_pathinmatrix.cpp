/*
	Given a cost matrix cost[][] and a position (M, N) in cost[][], write a function that returns cost of 
	minimum cost path to reach (M, N) from (0, 0). 
	Each cell of the matrix represents a cost to traverse through that cell. 

	Done via dynamic programming.

*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector <vector<int> > arr(n,vector<int>(n));
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            int temp;
	            cin>>temp;
	            arr[i][j]=temp;
	        }
	    }
	    vector <vector<int> > dp(n,vector<int>(n,0));
	    
	    for(int i=n-1;i>=0;i--)
	    {
	        for(int j=n-1;j>=0;j--)
	        {
	            dp[i][j]=arr[i][j];
	            if(i+1<n)
	            {
	                if(j<n && dp[i][j]< dp[i+1][j]+arr[i][j])
	                    dp[i][j]=dp[i+1][j]+arr[i][j];
	               
	                if(j-1>=0 && j-1<n && dp[i][j]< dp[i+1][j-1]+arr[i][j])
	                     dp[i][j]=dp[i+1][j-1]+arr[i][j];
	               
	                if(j+1<n && dp[i][j]< dp[i+1][j+1]+arr[i][j])
	                     dp[i][j]=dp[i+1][j+1]+arr[i][j];
	            }
	        }
	    }
	    
	    int max=dp[0][0];
	    for(int i=1;i<n;i++)
	        if(max<dp[0][i])
	            max=dp[0][i];
	   
	   cout<<max<<endl;
	}
	return 0;
}