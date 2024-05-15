/*
	Find if a graph is strongly connected or not.
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class graph
{
	vector <vector<int> > adj;
	public:
	graph(vector<pair<int,int> > edges, int N)
	{
		adj.resize(N);
		for(auto p: edges)
		{
			int u = p.first;
			int v = p.second;
			adj[u].push_back(v);

		}	
	}
	
	void dfs_2traversal(int u, vector <bool> &visited)
	{
		visited[u]=true;
		for(int v:adj[u])
		{
			if(!visited[v])
			{
				dfs_2traversal(v,visited);
			}
			
		}
		
	}
	bool strongly_connected_2traversal() 
	{
		vector<bool> visited(adj.size(),false);
		dfs_2traversal(0,visited);
		for(int i=0;i<visited.size();i++)
			if(!visited[i])
				return false;
		
		return true;
	}
	
	
	
	
};

int main()
{
	vector<pair <int,int> > edges = {
		{0, 4}, {1, 0}, {1, 2}, {2, 1}, {2, 4},
		{3, 1}, {3, 2}, {4, 3}
	};

	// Number of nodes in the graph
	int N = 5;

	// create a graph from given edges
	graph g(edges, N);
	cout<<g.strongly_connected_2traversal();
	return 0;
}