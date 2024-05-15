/*
	Given a digraph (Directed Graph), find the total number of routes to reach the
	destination from given source that have exactly m edges.

*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class graph
{
	vector <vector<int> > adj;
	map <int,int> level;
	map <int,int> parent;
	
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
	
	void bfs(int s,int reachable, int m )
	{
		vector <int> frontier = {s}; //next vertex to visit
		level.clear();
		parent.clear();
		parent[s]=-1;
		level[s] = -1;
		int i=1;
		int noofways;
		while(!frontier.empty())
		{
			vector <int> next;
			for(int u: frontier)
			{
				for(int v: adj[u])
				{
					//if(level.find(v)==level.end())
					//{
						level[v]=i;
						parent[v]=u;
						if(i==m && v==reachable)
						{
							noofways++;
						}
						
						if(i>m)
							break;
						
						next.push_back(v);
					//}
					
				}
			}
			i++;
			frontier=next;
		}
		
		cout<<"\nNumber of ways = "<<noofways;
	}
	
};

int main()
{
	vector<pair<int,int> > edges =
	{
		{0, 6}, {0, 1}, {1, 6}, {1, 5}, {1, 2}, {2, 3}, {3, 4},
		{5, 2}, {5, 3}, {5, 4}, {6, 5}, {7, 6}, {7, 1}
	};

	// Number of nodes in the graph
	int N = 8;

	// create a graph from edges
	graph g(edges, N);
	g.bfs(3,4,3);
	
	g.bfs(0,3,4);

	return 0;
}