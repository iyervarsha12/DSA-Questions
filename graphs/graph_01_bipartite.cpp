/*
	Check if given graph is bipartite of not. A bipartite graph (or bigraph) is a graph whose vertices can be
	divided into two disjoint sets U and V such that every edge connects a vertex in U to one in V.
	Graphs are represented using a vector of edges, which we convert into an adjacency vector.
	Solution: the graph must be two-colorable, and should not be containing an odd cycle. 
	This can be done via BFS or DFS. 
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
	int s;
	
	public:
	graph(vector<pair<int,int> > edges, int N, bool directed)
	{
		adj.resize(N);
		for(auto p: edges)
		{
			int u = p.first;
			int v = p.second;
			adj[u].push_back(v);
			if(!directed)
				adj[v].push_back(u);
		}
		
	}
	
	bool bfs_bipartite(int s)
	{
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
				for(int v: adj[u])
				{
					if(level.find(v)==level.end())
					{
						level[v]=i;
						parent[v]=u;
						next.push_back(v);
					}
					else if (level[v]==level[u])
						return false;
				}
			}
			i++;
			frontier=next;
		}
		return true;
	}
	
	bool dfs_visit(int s,vector <int> &color)
	{
		for(int v: adj[s])
		{
			if(parent.find(v)==parent.end())
			{
				//cout<<v<<"-->";
				color[v]=!(color[s]);
				parent[v]=s;
				if(!dfs_visit(v,color))
					return false;
			}
			else if(color[v]==color[s])
				return false;
			
		}
		return true;
	}
	
	bool dfs_bipartite()
	{
		parent.clear();
		vector <int> color(adj.size());
		for(int s=0;s<adj.size();s++)
		{
			if(parent.find(s)==parent.end())
			{
				parent[s]=-1;
				color[s]=0;
				if(dfs_visit(s,color)==false)
					return false;
			}
		}
		return true;

	}

};

int main()
{
	vector<pair<int,int> > edges = {
		{1, 2}, {2, 3}, {2, 8}, {3, 4}, {4, 6}, {5, 7},
		{5, 9}, {8, 9},{2,4}
		// if we add 2->4 edge, graph is becomes non-Bipartite
	};
	int N = 10;

	graph g(edges,N,true);
	cout<<g.bfs_bipartite(1);
	cout<<endl<<g.dfs_bipartite();
	return 0;
}