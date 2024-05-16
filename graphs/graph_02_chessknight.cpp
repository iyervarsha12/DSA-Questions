/*
	Given a chess board, find the shortest distance (minimum number of steps) taken
	by a Knight to reach given destination from given source. 
	Input: N = 8 (8 x 8 board), Source = (7, 0) Destination = (0, 7)
	Output: Prints the path and Minimum number of steps required (6)
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct edge
{
	pair <int,int> u;
	pair <int,int> v;
};


class graph
{
	map <pair<int,int>,int> level;
	map <pair<int,int>,pair<int,int> > parent;
	
	public:
	graph()
	{

	}
	
	void bfs(int n,pair<int,int> s,pair<int,int> reachable)
	{
		vector <int> row = {2, 2, -2, -2, 1, 1, -1, -1 };
		vector <int> col = { -1, 1, 1, -1, 2, -2, 2, -2 };
		//move from (i,j) to (i+row[x],j+row[x])

		vector <pair<int,int> > frontier = {s}; //next vertex to visit
		level.clear();
		parent.clear();
		parent[s]={-1,-1};
		level[s] = -1;
		int i=1;
		
		while(!frontier.empty())
		{
			vector <pair<int,int> > next;
			for(pair<int,int> u: frontier)
			{
				vector <pair<int,int> > adj;
				int i=u.first;
				int j=u.second;
				for(int x=0;x<row.size();x++)
				{
					pair <int,int> add = make_pair(i+row[x],j+col[x]);
					if(add.first>=0 && add.first<n && add.second>=0 && add.second<n)
						adj.push_back(add);
				}
				if(!adj.empty())
				{
					for(pair<int,int> v: adj)
					{
						if(level.find(v)==level.end())
						{
							level[v]=i;
							parent[v]=u;
							if(v.first == reachable.first && v.second == reachable.second)
								shortestpath(s,reachable);
							
							next.push_back(v);
						}
					}
				}
			}
			i++;
			frontier=next;
		}
	}
	
	bool shortestpath(pair<int,int> s,pair<int,int> reachable)
	{
		if(parent.find(reachable)==parent.end())
		{
			cout<<"\n("<<reachable.first<<","<<reachable.second<<") is NOT accessible from ("<<s.first<<","<<s.second<<")";
			cout<<endl;
			return false;
		}
		
		int moves =0;
		cout<<"\n("<<reachable.first<<","<<reachable.second<<") is accessible from ("<<s.first<<","<<s.second<<")";
		cout<<"\n("<<reachable.first<<","<<reachable.second<<") <-- ";
		while(parent[reachable].first!=-1 && parent[reachable].second!=-1)
		{
			cout<<"("<<parent[reachable].first<<","<<parent[reachable].second<<") <-- ";
			moves++;
			reachable = parent[reachable];
		}
		cout<<endl;
		cout<<"\nMinimum number of moves needed: "<<moves;
		return true;
	}
};


int main()
{
	graph g;
	g.bfs(8,make_pair(0,7),make_pair(7,0));
	return 0;
}