/*
	Transitive closure of a graph: form a connectivity matrix for a graph. 
	Connectivity graph: if there is a path between i and j (need not be directly connected) , a[i][j] is true
*/


#include <iostream>
#include <vector>
#include <map>

using namespace std;

class graph
{
	vector <vector<int> > adj;
	vector<vector<bool> > c;
	
	public:
	graph(vector<pair<int,int> > edges, int N)
	{
		adj.resize(N);
		vector <bool> temp(N,false);
		for(int i=0;i<N;i++)
			c.push_back(temp);
		
		
		for(auto p: edges)
		{
			int u = p.first;
			int v = p.second;
			adj[u].push_back(v);
		}
	}
	
	/*
		what is happening is:
		For each dfs, going through each vertex: 
		dfs_visit checks all adjacent vertices of the descendant and makes sure that the root it came from is shown as connected to it too.
	*/
	
	void dfs_visit(int root,int descendant) //path exists from root->descendant is the invariant
	{
		for(int adjtodesc: adj[descendant])
		{
			if(!c[root][adjtodesc]) 
			{
				c[root][adjtodesc]=true;
				//c[descendant][adjtodesc]=true is taken care of by the fact that you go through each vertex in dfs.
				dfs_visit(root,adjtodesc);
			}
		}
	}
	
	void dfs()
	{
		for(int s=0;s<adj.size();s++)
		{
			c[s][s]=true;
			dfs_visit(s,s);
		}
	}
	
	void printc()
	{
		cout<<"\nConnectivity matrix: \n";
		for(int i=0;i<adj.size();i++)
		{
			for(int j=0;j<adj.size();j++)
				cout<<c[i][j]<<" ";
			cout<<endl;	
		}
	}
};

int main()
{
	vector <pair<int,int> > edges = {{0,2},{1,0},{3,1}};
	int N=4;
	graph g(edges,N);
	g.dfs();
	g.printc();
	return 0;
}