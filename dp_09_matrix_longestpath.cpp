/*
	Given a n*n matrix where all numbers are distinct, 
	Find the maximum length path (starting from any cell) such that all cells along the path 
	are in increasing order with a difference of 1.

	Done via dynamic programming.

	Input:  mat[][] = {{1, 2, 9}
	                   {5, 3, 8}
	                   {4, 6, 7}}
	Output: 4
	The longest path is 6-7-8-9. 
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;


map<pair<int,int>,pair<int,int> > parent;

/*
	Subproblem: starting from mat[i][j], longest subpath?
	Guess: which direction to go in, if more than one is there
	Recurrence: dp[i][j] = max dp[i+1][j], dp[i][j+1], dp[i-1][j], dp[i][j-1], 0 
							// only if they are having absolute difference 1. Otherwise ans is 0
	ans: max dp[i][j]
*/
int longestpath( int i, int j,vector <vector<int> > arr,int m, int n, vector <vector<int> > &dp)
{
	if(i>=m || i<0 || j>=n || j<0)
		return 0;
	
	if(dp[i][j]==-1)
	{
		int max=1;
		pair <int,int> next = make_pair(-1,-1);
		
		if(i+1<m && arr[i+1][j]-arr[i][j]==1 )
		{
			int ans2 = 1;
			ans2+= (dp[i+1][j]==-1)? longestpath(i+1,j,arr,m,n,dp): dp[i+1][j];
			if(max<ans2)
			{
				max=ans2;
				next = make_pair(i+1,j);
			}
		}
		
		if(j+1<n && arr[i][j+1]-arr[i][j]==1 )
		{
			int ans2 = 1;
			ans2+= (dp[i][j+1]==-1)?  longestpath(i,j+1,arr,m,n,dp): dp[i][j+1];
			if(max<ans2)
			{
				max=ans2;
				next = make_pair(i,j+1);
			}
		}
		
		if(i-1>=0 && arr[i-1][j]-arr[i][j]==1)
		{
			int ans2 =1;
			ans2+= (dp[i-1][j]==-1)?  longestpath(i-1,j,arr,m,n,dp): dp[i-1][j];
			if(max<ans2)
			{
				max=ans2;
				next = make_pair(i-1,j);
			}
		}
		if(j-1>=0 && arr[i][j-1]-arr[i][j]==1)
		{
			int ans2 = 1;
			ans2+= (dp[i][j-1]==-1)?  longestpath(i,j-1,arr,m,n,dp): dp[i][j-1];
			if(max<ans2)
			{
				max=ans2;
				next = make_pair(i,j-1);
			}
		}
		dp[i][j] = max;
		parent[make_pair(i,j)] = next;
	}
	
	return dp[i][j];
}

int longestpath(vector <vector<int> > arr,int m, int n)
{
	vector <vector<int> > dp(m+1,vector<int> (n+1,-1));
	int max=1;
	pair <int,int> start = make_pair(-1,-1);
	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(dp[i][j]==-1)
				longestpath(i,j,arr,m,n,dp);
			if(max<dp[i][j])
			{
				max=dp[i][j];
				start = make_pair(i,j);
			}
		}
	}
	
	while(start.first!=-1 && start.second!=-1)
	{
		cout<<arr[start.first][start.second]<<"-->";
		start = parent[start];
	}
	cout<<endl;
	return max;
}

int main()
{
	vector<vector<int> > arr = { { 0,0 , 0 }, 
								{ 0, 0, 0}, 
								{ 0, 0, 0 } }; 							
	int m = arr.size();
	int n = arr[0].size();
	cout<<longestpath(arr,m,n);
	return 0;
}