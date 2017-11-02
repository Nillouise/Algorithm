#include<bits/stdc++>
using namespace std;
//边是有附带信息的，不能用这种简单的结构了
vector<int> G[10000];
int dist[10000];
int col[10000];
int n1,n2;
const int INF = 100000000;
int bfs()
{
	queue<int> Q;
	
	Q.push(n2);
	dist[n2] = 0;
	while(!Q.empty())
	{
		int n = Q.front();
		Q.pop();
		for(auto a:G[n])
		{
			if(dist[a]>dist[n]+1)
			{
				dist[a] = dist[n]+1;
				Q.push(a);
			}
		}
		if(dist[n1]<INF)
		{
			break;
		}
	}
	
	return 0;
}


int main()
{
	ios::sync_with_stdio(false);
	int edges,ve;
	while(cin>>ve>>edges)
	{
		for(int i=0;i<10000;i++)
		{
			G[i].clear();
		}
		fill(dist,dist+10000,INF);
		fill(col,col+10000,INF);
		n1 = 1;
		n2 = ve;
		for(int i=0;i<edges;i++)
		{
			int u,v,c;
			cin>>u>>v>>c;
			G[u].push_back(v);
			G[v].push_back(u);
			col[i] = c;
		}
		
		bfs();
		cout<<dist[n1]<<endl;
		int n =n1;
		
		while(n!=n2)
		{
			int MIN = INF;
			int color = 1000;
			for(auto a:G[n])
			{
				if(MIN ==dist[a])
				{
					if(col[a]<color)
					{
						color = col[a];
					}
				}
				
				if(MIN>dist[a])
				{
					MIN = dist[a];
					color = col[a];
				}
			}
			if(n!=n1)
			{
				cout<<" ";
			}
			cout<<color;
			
			
		}
		
		
	}
	
	
	
	
	
	
}
