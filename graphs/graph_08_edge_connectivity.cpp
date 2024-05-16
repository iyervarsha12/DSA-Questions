/*
	Given an undirected connected graph, check if the graph is 2-edge connected or not. A connected graph is 2-edge-connected if it
	remains connected whenever any edges is removed. A bridge or cut arc is an edge of a graph whose deletion increases its number of
	connected components. i.e. whose removal disconnects the graph. So if any such bridge exists, the graph is not 2-edge-connected.

	a back-edge going out of every sub tree
	there should be no bridges
	x-------x---x
	 bridge |  /
			| /
			x/
			
	When we do a DFS from vertex v in an undirected graph, there could be edges which are going out of the sub tree i.e back edges. We can say
	that the graph is 2-edge connected if and only if for every edge u->v in the graph, there is at-least
	one back-edge that is going out of subtree rooted at v(v and all its descendants) to some ancestor of u. 

	When we backtrack from a vertex v, we need to ensure that there is some back-edge
	from some descendant of v (including v) to some proper ancestor(parent or above) of v


	PRINT OUT ALL THE BRIDGES if the graph is not 2-edge-connected.
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class graph
{
	vector <vector<int> > adj;
	vector <bool> discovered;
	int time;
	
	public:
	graph(vector<pair<int,int> > edges, int N)
	{
		adj.resize(N);
		vector<bool> d(N,false);
		discovered=d;
		time=0;
		for(auto p: edges)
		{
			int u = p.first;
			int v = p.second;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
	
	/*
	if dfs(v) returns smallest arrival time to which there is a backedge from subtree rooted at v
	u is v
	v is w
	*/
	int dfs(int u, int parent, vector<int> arrival)
	{
		arrival[u] = ++time;
		discovered[u]=true;
		int arr=arrival[u];
		for(int v:adj[u])
		{
			if(!discovered[v]) //if v not discovered yet, it is descendant of u
			{
				//discovered[v]=true;
				int dfs_res = dfs(v,u, arrival);
				arr = (arr<dfs_res)? arr:dfs_res; //arr will contain the least of the descendant of u
			}
			else if(v!=parent) //cycle. vertex discovered, has been also discovered by some ancestor of u. --> backedge starting from u
				arr=(arr<arrival[v])? arr:arrival[v]; 
		}
		
		//parent[u]---> u forms bridge: u is not root node and min arr = arr[u]
		if(arr==arrival[u] && parent!=-1)
			cout<<parent<<","<<u<<"\n";
		
		return arr;
	}
};

int main()
{
	vector<pair<int,int> > edges = {
		{0, 2}, {1, 2}, {2, 3}, {2, 4}, {3, 4}, {3, 5}
	};

	// Number of nodes in the graph
	int N = 10;

	// create a graph from edges
	graph g(edges, N);
	vector<int> arrival(N,0);
	g.dfs(0,-1,arrival);
	return 0;
}