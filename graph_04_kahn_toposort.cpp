/*
	Implementation of Kahn's topological sort algorithm, which works by finding vertices 
	which have no incoming edges and removing all outgoing edges from these vertices.
	It also mentions if the topological sort does not exist.

*/


#include <iostream>
#include <vector>
#include <map>

using namespace std;

class graph
{
	vector <vector<int> > adj;
	vector <int> indegree;
	
	
	public:
	graph(vector<pair<int,int> > edges, int N)
	{
		adj.resize(N);
		vector <int> temp(N,0);
		indegree = temp;
		
		for(auto p: edges)
		{
			int u = p.first;
			int v = p.second;
			adj[u].push_back(v);
			indegree[v]++;
		}
	}
	
	
	bool kahn_topo_sort(vector <int> &L)
	{
		vector <int> S;
		for(int i=0;i<indegree.size();i++)
			if(indegree[i]==0)
				S.push_back(i);
		
		while(!S.empty())
		{
			int n=S.back();
			S.pop_back();
			L.push_back(n);
			for(int m: adj[n])
			{
				indegree[m]--; //remove that edge
				if(indegree[m]==0)
					S.push_back(m);
			}
		}
		
		for(int i=0;i<indegree.size();i++)
		{
			if(indegree[i]!=0)
				return false;
		}
		return true;
	}
};

int main()
{
	vector<pair<int,int> > edges =
	{
		{ 0, 6 }, { 1, 2 }, { 1, 4 }, { 1, 6 }, { 3, 0 }, { 3, 4 },
		{ 5, 1 }, { 7, 0 }, { 7, 1 }
	};

	// Number of nodes in the graph
	int N = 8;
	graph g(edges,N);
	vector <int> L;
	if(g.kahn_topo_sort(L))
	{
		cout<<"\nTopological sort using Kahn is: ";
		for(int i=0;i<L.size();i++)
			cout<<L[i]<<" ";
	}
	else cout<<"\nNo topological sort exists";

	return 0;
}