/*
	Optimal strategy for a game (problem explained in https://www.geeksforgeeks.org/optimal-strategy-for-a-game-dp-31/)
	Done via dynamic programming.
*/

#include <iostream>
#include <vector>
using namespace std;

/*
	Auxiliary function to find out the maximum of two integers.
*/
int max(int val1,int val2)
{
    if(val1>val2)
        return val1;
    else return val2;
}

/*
	Auxiliary function to find out the minimum of two integers.
*/
int min(int val1,int val2)
{
    if(val1<val2)
        return val1;
    else return val2;
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector <int> arr(n);
	    for(int i=0;i<n;i++)
	    {
	        int temp;
	        cin>>temp;
	        arr[i]=temp;
	    }
	    
	    int dp[n][n];
	   
	    for(int gap=0;gap<n;gap++)
	    {
	        for(int i=0,j=gap;i<n && j<n;i++,j++)
	        {
	            if(i==j)    dp[i][j]=arr[i];
	            else if(i==j+1) dp[i][j]=max(arr[i],arr[j]);
	            else
	            {
	                int x = (i+2<=j)? dp[i+2][j]:0;
	                int y = (i+1<=j-1)? dp[i+1][j-1]:0;
	                int z = (i<=j-2)? dp[i][j-2]:0;
	                
	                dp[i][j]=max( (arr[i]+min(x,y)) , (arr[j]+min(y,z)) );
	            }
	        }
	    }
	    cout<<dp[0][n-1]<<endl;
	    
	}
	return 0;
}