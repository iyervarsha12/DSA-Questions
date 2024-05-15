/*
	Given that a person can move 1,2 or 3 steps at a time, find the different number of ways they can move distance 'n'.
	
	Example: 
	Input: n = 3
	Output: 4
	Explanation:
	Below are the four ways
	 1 step + 1 step + 1 step
	 1 step + 2 step
	 2 step + 1 step
	 3 step

	Input: n = 4
	Output: 7
	Explanation:
	Below are the 7 ways
	 1 step + 1 step + 1 step + 1 step
	 1 step + 2 step + 1 step
	 2 step + 1 step + 1 step 
	 1 step + 1 step + 2 step
	 2 step + 2 step
	 3 step + 1 step
	 1 step + 3 step

	 (Done via dynamic programming). 
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int ways(int n)
{
	vector <int> dp(n+1,0); //dp[i]: number of ways to move to i using "1,2 or 3 step"
	dp[0]=1; //1 way to move 0 step
	dp[1]=1; //1 step
	dp[2]=2; //1 1, 2; so two ways
	dp[3]=4; //1 1 1, 2 1, 1 2, 3; so 4 ways
	
	for(int i=4;i<=n;i++)
	{
		// To reach position i, a person has to jump either from i-1, i-2 or i-3 position where i is the starting position
		dp[i]=dp[i-1]+dp[i-2]+dp[i-3]; // person can only move by 1, 2 or 3 steps
	}
	return dp[n];
}

int main()
{
	int n;
	cin>>n;
	cout<<ways(n);
	return 0;
}