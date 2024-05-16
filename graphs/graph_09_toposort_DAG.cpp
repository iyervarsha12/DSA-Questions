/*
	Do topological sort on a graph: order vertices by decreasing time of departure for topo sort.
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

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
	
	void dfs_visit(int s, vector <int > &times, int &time)
	{
		for(int v: adj[s])
		{
			if(parent.find(v)==parent.end())
			{
				//times[v].first = time++;
				cout<<v<<"-->";
				parent[v]=s;
				dfs_visit(v,times,time);
				times[v] = time++;
			}
		}
	}
	
	void dfs()
	{
		vector <int > times((int)adj.size());
		int time=0;
		parent.clear();
		cout<<"\nDFS paths are: ";
		for(int s=0;s<adj.size();s++)
		{
			if(parent.find(s)==parent.end())
			{
				parent[s]=-1;
				//times[s].first = time++;
				cout<<"\n"<<s<<"-->";
				dfs_visit(s,times,time);
				times[s] = time++;
			}
		}
		
		
		cout<<endl<<"\nTimes of departure: ";
		for(int i=0;i<adj.size();i++)
			cout<<"\n"<<i<<":\t"<<times[i];
		
		toposort(times);
	}
	
};

int main()
{
	vector<pair<int,int> > edges =
	{
		{0, 6}, {1, 2}, {1, 4}, {1, 6}, {3, 0}, {3, 4},
		{5, 1}, {7, 0}, {7, 1}
	};

	// Number of nodes in the graph
	int N = 8;
	graph g(edges,N,true);
	g.dfs();
	
	return 0;
}