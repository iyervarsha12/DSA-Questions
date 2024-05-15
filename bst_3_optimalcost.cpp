 
 /*
 	Find optimal cost of a BST. 
 	Optimal cost: assume each key can repeat several times
 	We are given frequency of each key in order of inorder transversal
 	eg: freq{25,10,20} (key0,1,2) 
	 0 (25*1)
	 \
	  \
	   2 (20*2)
	  /
	 /
	 1 (10*3)   costs 95(lowest)
 
 	Solution: consider each key as root and find optimal soln by recursively finding
 	optimal cost of left and righ subtree, add left and right child cost to current node 
 	cost (frw of key*level of node).
 	If current node cost is optimal, update.
 */
 
 #include <iostream>
 #include <vector>
 #include <climits>
 #include <map>
 using namespace std;
 
 map <vector <int>, int> memo;

 int findoptimalcost(vector <int> freq, int lowindex, int highindex, int level, vector <int> keys)
 {
	 if(highindex<lowindex)
		 return 0;
	 
	//keys from lowi to highi: compute
	int optimalcost=INT_MAX;
	for(int t=lowindex;t<=highindex;t++) //find which as root of subtree has least optimal cost
	{
		//keys keys[t] as root
		int startcost = freq[t]*level;
		int leftsubtreecost, rightsubtreecost;
		
		vector <int> temp = {lowindex,t-1,level+1};
		if(memo.find(temp)==memo.end())
			leftsubtreecost = findoptimalcost(freq,lowindex,t-1,level+1,keys);
		else 
			leftsubtreecost = memo[temp];
		
		
		temp = {t+1,highindex,level+1};
		if(memo.find(temp)==memo.end())
			rightsubtreecost = findoptimalcost(freq,t+1,highindex,level+1,keys);
		else
			rightsubtreecost = memo[temp];
		
		
		startcost+=leftsubtreecost + rightsubtreecost;
		optimalcost = (optimalcost<startcost)? optimalcost:startcost;
		
	}
	vector <int> temp = {lowindex,highindex,level};
	memo[temp] = optimalcost;
	return optimalcost; 
 }
 
 
 /*
 //from keys i to j in vector "keys"
 int findoptimalcost(vector <int> freq, int i, int j, int level, vector<int> keys)
 {
	 if(j<i)
		 return 0;
	 int optimalcost=INT_MAX;
	 
	 for(int t=i;t<=j;t++)
	 {
		 int k = keys.at(t);
		 int leftoptcost = findoptimalcost(freq,i,t-1,level+1,keys);
		 int rightoptcost = findoptimalcost(freq,t+1,j,level+1,keys);
		 
		 int cost=(freq.at(t))*level + leftoptcost + rightoptcost;
		 
		 
		 optimalcost = ((optimalcost<cost)? optimalcost:cost ); 
	 }
	 
	 return optimalcost;
 }
 */
 

 int main()
 {
	 vector <int> freq = {34,8,50};
	 vector <int> keys = {10,12,20};
	 
	 cout<<findoptimalcost(freq,0,keys.size()-1,1,keys);
	 
	 return 0;
 }
 