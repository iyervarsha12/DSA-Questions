/*
	Find minimum number of coins/notes (in rupees) to make a given value (Coin Change)
	The indian denominations are: 1, 2, 5, 10, 20, 50, 100, 200, 500 and 2000 rupees.
	Take the input of value to try to find minumum number of coins from.
	(Done via dynamic programming). 
*/

#include <iostream>
#include <climits>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int num;
	    cin>>num;
	    vector <int> coins = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000} ;
	    vector <int> dp(num+1,INT_MAX);
	    dp[0]=0;
	    for(int i=1;i<=num;i++)
	    {
	        for(int j=0;j<coins.size();j++)
	        {
	            int sub_result = INT_MAX;
	            
	            //to take denomination
	            if(coins[j]<=i) //if coin deno is less than amt, can use.
	                sub_result = dp[i-coins[j]];
                else break;	                
	           
	            if(sub_result!=INT_MAX && sub_result + 1 < dp[i])
	           {
	                   dp[i]=sub_result+1;

	           }
	        }
	    }
	    
	    
	    cout<<dp[num]<<endl;

	}
	return 0;
}