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
int dfs( int from  )
{
	vstd[ from ] = true;
	printf("Vértice %d\n", from);
	for( auto v : AdjList[from] )
		if( !vstd[v] )
			dfs(v);
}

int main()
{
	int TC;
	int vertex, edges;
	int from, arrival;
	scanf("%d%d", &vertex, &edges);
	init(vertex);
	for (int i = 0; i < edges; ++i)
	{
		scanf("%d%d", &from, &arrival);
		AdjList[from].pb(arrival);
		AdjList[arrival].pb(from);
	}
	dfs(0);
	return 0;
}