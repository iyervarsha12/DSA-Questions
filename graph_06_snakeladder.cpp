/*
	Snake and ladder: given a map of ladder and snake positions, 
	Find the minimum number of moves to reach the finish line (at 100).
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
	int moves;
	
	public:
	graph(vector<pair<int,int> > edges, int N) //directed
	{
		adj.resize(N);
		for(auto p: edges)
		{
			int u = p.first;
			int v = p.second;
			adj[u].push_back(v);
		}
		
	}
	
	void bfs(int s, int reachable)
	{
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
						if(v==reachable)
							min_dist(reachable,s);
						
						next.push_back(v);
					}
				}
			}
			i++;
			frontier=next;
		}
		//min_dist(reachable,s);
	}
	
	void min_dist(int reachable, int s)
	{
		moves=0;
		cout<<"\n"<<reachable<<" <-- ";
		while(parent[reachable]!=-1)
		{
			cout<<parent[reachable]<<" <-- ";
			moves++;
			reachable = parent[reachable];
		}
		cout<<endl;
		
		
	}
	
	int returnmoves()
	{
		return moves;
	}
};

void transform_snakeladder(int n, map <int,int> ladder, map<int,int> snake)
{
	vector <pair<int,int> > edges;
	//from 0(isolated node) to 100, graph n=101
	//edge from i to i+1,i+2,i+3,i+4,i+5,i+6
	//if ladder[i+1/i+2/...]=somewhere then edge from i to somewhere instead
	//if snake[i+1/i+2/...]=somewhere then edge from i to somewhere instead
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=6 && i+j<=n;j++)
		{
			int src = i;
			//since map[i] init to 0 by default
			//if ladder[i+j] or snake[i+j] exist, go to those (both can't exist simult in one location)
			int dest = (ladder[i+j] || snake[i+j])? (snake[i+j] + ladder[i+j]): (i+j);
			edges.push_back(make_pair(src,dest));
		}
	}
	graph g(edges,n+1);
	g.bfs(1,n);
	cout<<"\nMinimum number of moves: "<<g.returnmoves();
}


int main()
{
	// snakes and ladders are represented using a map
	map<int, int> ladder, snake;

	// insert ladders into the map
	ladder[1] = 38;
	ladder[4] = 14;
	ladder[9] = 31;
	ladder[21] = 42;
	ladder[28] = 84;
	ladder[51] = 67;
	ladder[72] = 91;
	ladder[80] = 99;

	// insert snakes into the map
	snake[17] = 7;
	snake[54] = 34;
	snake[62] = 19;
	snake[64] = 60;
	snake[87] = 36;
	snake[93] = 73;
	snake[95] = 75;
	snake[98] = 79;

	transform_snakeladder(100,ladder, snake);
	return 0;
}