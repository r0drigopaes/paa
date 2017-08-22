#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define INF 0x3f3f3f
#define fi first
#define se second
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef tuple<int,int,int> iii;
vvi AdjList;
vector<bool> vstd;
void init(int vertex)
{
	vstd.clear();
	vstd.assign(vertex,false);
	AdjList.clear();
	AdjList.resize(vertex);
}
int bfs( int vertex ,int from , int arrival )
{
	vi dist(vertex);
	dist[from] = 0;
	vstd[from] = true;
	queue<int> p; p.push(from);
	while( !p.empty() )
	{
		int front = p.front(); p.pop();
		for( auto v : AdjList[front] )
			if( !vstd[v] )
			{
				dist[v] = dist[front]+1;
				vstd[v] = true;
				if(v == arrival) return dist[v];
				p.push(v); 
			}
	}
	return -1;
}

int main()
{
	int TC;
	int vertex, edges;
	int from, arrival;
	scanf("%d", &TC);
	while(TC--)
	{
		scanf("%d%d", &vertex, &edges);
		init(vertex);
		for (int i = 0; i < edges; ++i)
		{
			scanf("%d%d", &from, &arrival);
			AdjList[from-1].pb(arrival-1);
			AdjList[arrival-1].pb(from-1);
		}
		printf("%d\n", bfs(vertex,0,vertex-1) );
	}
	return 0;
}