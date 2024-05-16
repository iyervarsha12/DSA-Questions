/*
	Given a value and three segments of length allowed to be inputted, maximize the total number of cut segments and output it.
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector <int> cuts(3);
	    for(int i=0;i<3;i++)
	    {
	        int temp;
	        cin>>temp;
	        cuts[i]=temp;
	    }
	    sort(cuts.begin(),cuts.end());
	    vector <int> dp(n+1,INT_MIN);
	    dp[0]=0;
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=0;j<cuts.size();j++)
	        {
	            int sub_res = INT_MIN;
	            if(cuts[j]<=i)
	                sub_res = dp[i-cuts[j]];
	            else break;
	            
	            if(sub_res!=INT_MAX && sub_res+1>dp[i])
	                dp[i] = sub_res+1;
	        }
	    }
	    cout<<dp[n]<<endl;
	}
	return 0;
}