#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

vvii adj_list;
priority_queue<ii> pq;
vi taken;

void process(int u)
{
	taken[u] = 1;
	int tam = (int) adj_list[u].size();
	for (int i=0; i < tam; ++i)
	{
		ii v = adj_list[u][i];
		if (!taken[v.first]) pq.push( ii(-v.second, -v.first) );
	}
}

int mst(int v, int a)
{
	int mst_cost = 0;
	int u, w;

	process(v);
	while (!pq.empty())
	{
		ii front = pq.top(); pq.pop();
		u = -front.second;
		w = -front.first;
		if (!taken[u])
		{
			/*
				Antes de usar a aresta, é preciso verificar se não seria 
				mais barato simplesmente construir um aeroporto para chegar no 
				vértice u.
				Se for, então a gente considera que o componente construído até
				então irá acessar o próximo através do aeroporto ao invés das
				arestas
			*/

			if (a <= w)
			{
				// limpa a lista de arestas que saem desse componente.
				// na prática, desconecta esse componente do restante do grafo, pois a conexão será via aeroporto			
				while (!pq.empty()) pq.pop();
				break;	
			}
			else
			{
				// escolhe ir de rodovia
				mst_cost += w;
			}			
			
			process(u);
		}

	}
	return mst_cost;
}


int main()
{
	int tc, n, m, a, u, v, w;
	int total_cost, counter, airports;

	scanf("%d", &tc);
	for (int j=1; j<= tc; ++j)
	{
		scanf("%d%d%d", &n, &m, &a);

		// inicializações
		pq = priority_queue<ii>();
		adj_list.clear();
		taken.clear();
		total_cost = 0;
		counter = 0;

		adj_list.resize(n+1);
		taken.resize(n+1, 0);

		for (int i=0; i < m; ++i)
		{
			scanf("%d%d%d", &u, &v, &w);
			adj_list[u].push_back( ii(v, w) );
			adj_list[v].push_back( ii(u, w) );
		}

		// Podem existir vários componentes no grafo
		for (int i=1; i <= n; ++i)
		{
			if (!taken[i])
			{
				total_cost += mst(i, a) + a;				
				counter++;
			}
		}

		printf("Case #%d: %d %d\n", j, total_cost, counter);
	}

	return 0;
}