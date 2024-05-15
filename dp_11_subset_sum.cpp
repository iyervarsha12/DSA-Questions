/*
	Given a set of non-negative integers, and a value sum, determine if there is a 
	subset of the given set with sum equal to given sum.
	Done via dynamic programming.

	Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
	Output: True  
	There is a subset (4, 5) with sum 9.

	Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
	Output: False
	There is no subset that add up to 30.
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/*
	Subproblem: i,j whether to include arr[i] or not, given sum till now from 0..i-1 picked = j. can't include if j+arr[i]>s. if j+arr[i]=s, we found subset
	Guess: whether to include arr[i] or not
	Recurrence: dp[i][j] = { if j+arr[i]==s, return true
							if j+arr[i]<s, can include as return dp[i+1][j+arr[i]]
							or exclude, return dp[i+1][j]
	Base cases: dp[i][0] = true //sum=0 means answer always true
				??? dp[0][s] = false //if 
	Topo: i=0...n, j=0...s
	Ans: if there are any dp[i][s]==true
*/
bool subset_sum(vector <int> arr, int s)
{
	int n= arr.size();
	vector <vector<bool> > dp(n+1,vector<bool> (s+1,false));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<s;j++)
		{
			if(j==0)
				dp[i][j] = true;
			else
			{
				bool ans1=false;
				bool ans2=false;
				if(j+arr[i]==s)
				{
					//dp[i][j]=true;
					return true;
				}
				else if(j+arr[i]>s) //cannot be included anyway
				{
					ans1 = dp[i+1][j+arr[i]];
				}
				else
				{
					ans2 = dp[i+1][j+arr[i]] || dp[i+1][j];	
				}
				if(ans1||ans2 == true)
					return true;
			}
		}
	}
	return false;
}

int main()
{
	vector <int> arr = { 3, 34, 4, 12, 5, 2 }; 
	int sum = 10;
	cout<<subset_sum(arr,sum);
	return 0;
}