/*
	Given an array arr[] of size N, the task is to find the length of the Longest Increasing Subsequence
	i.e., the longest possible subsequence in which the elements of the subsequence are sorted in increasing order.

	Done via dynamic programming.
	Input: arr[] = {3, 10, 2, 1, 20}
	Output: Length of LIS = 3
	The longest increasing subsequence is 3, 10, 20

	Input: arr[] = {3, 2}
	Output: Length of LIS = 1
	The longest increasing subsequences are {3} and {2}

	Input: arr[] = {50, 3, 10, 7, 40, 80}
	Output: Length of LIS = 4
	The longest increasing subsequence is {3, 7, 40, 80}
*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int increasingss2(vector <int> arr)
{
	map <int,int> dp;
	map <int,int> ancestor;
	
	for(int i=arr.size()-1;i>=0;i--)
	{
		vector <pair<int,int> > choices = {make_pair(1,-1)}; //(dp, ancestor)
		for(int j=i+1;j<arr.size() ;j++)
		{
			if(arr[j]>arr[i])
				choices.push_back({dp[j]+1, j});
		}
		int max = choices[0].first;
		int index = -1; //i's ancestor is j
		for(int x=1;x<choices.size();x++)
		{
			//max = (max>choices[x])? max: choices[x];
			if(max<choices[x].first)
			{
				max = choices[x].first;
				index = choices[x].second;
			}	
		}
		
		dp[i] = max;
		ancestor[i]=index;
	}
	
	int max = 0;
	int index =-1 ;
	for(int i=0;i<dp.size();i++)
	{

		if(max<dp[i])
		{
			max=dp[i];
			index = i;
		}
	}
	while(index!=-1)
	{
		cout<<arr[index]<<" ";
		index = ancestor[index];
	}
	cout<<endl;
	return max;
}



int main()
{
	vector <int> arr = {50, 3, 10, 7, 40, 80,2,6,90};
	//vector <int> arr = {3, 2};
	//vector <int> arr = {3, 10, 2, 1, 20};
	cout<<increasingss2(arr);
	return 0;
}