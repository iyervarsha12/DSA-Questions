#include <iostream>
#include <vector>
#include <map>

using namespace std;

class graph
{
	vector <vector<int> > adj;
	map <int,int> level;
	map <int,int> parent;
	int s;
	
	public:
	graph(vector<pair<int,int> > edges, int N)
	{
		adj.resize(N);
		for(auto p: edges)
		{
			int u = p.first;
			int v = p.second;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}	
	}
	
	bool bfs_cycledetection(int s)
	{
		//cout<<"\nNew parent is "<<s;
		this->s = s;
		vector <int> frontier = {s}; //next vertex to visit
		level.clear();
		parent.clear();
		
		parent[s]=-1;
		level[s] = -1;
		int i=1;
		
		while(!frontier.empty())
		{
			vector <int> next;
			for(int u: frontier)
			{
				for(int v: adj[u]) //u-->v
				{
					if(level.find(v)==level.end()) //if v hasn't been found yet
					{
						level[v]=i;
						parent[v]=u;
						next.push_back(v);
					}
					//cross edge pointing to previously discovered vertex 
					//that is neither ancestor nor descendant of current vertex
					/*
					THIS IS UNDIRECTED GRAPH. 
					if v has been found but it is not parent of u, means crossedge
					so z---u---v---z
					*/
					else if(v!=parent[u]) //means there is a crossedge
						return true; 
				}
			}
			i++;
			frontier=next;
		}
		return false;
	}
	
};

int main()
{
	vector<pair<int,int> > edges =
	{
		{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9},
		{5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}, {6,10}
		// edge (6->10) introduces a cycle in the graph
	};

	// Number of nodes in the graph
	int N = 13;
	graph g(edges,N);
	
	cout<<g.bfs_cycledetection(1);
	return 0;
}