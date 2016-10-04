/*
Implementação do Shortest Path Faster Algorithm (SPFA)
Explicação: https://docs.google.com/presentation/d/1_sGF0Z1F3VizJo6wduqek89xkIJK7vViGbZY2FyAimg/edit?usp=sharing

UVA - 558 - Wormholes
*/
#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

vvii adj_list;
vi dist;
int n;

/*
Retorna true caso exista um ciclo negativo, falso caso contrário.
Ao final do algoritmo, o vector dist terá todas as distâncias de s para cada vértice.
*/
bool spfa(int s)
{
	int u, v, w;
	queue<int> q;
	vi counter(n, 0); // usado para evitar o loop
	vector<bool> in_queue(n, false);

	fill(dist.begin(), dist.end(), INF);
	dist[s] = 0;	
	q.push(s);
	counter[s]++;
	in_queue[s] = true;

	while (! q.empty() )
	{
		u = q.front(); q.pop();		
		in_queue[u] = false;		

		for (int j=0; j < adj_list[u].size(); ++j)
		{			
			v = adj_list[u][j].first;
			w = adj_list[u][j].second;
			
			if (dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				
				if ( !in_queue[v] )
				{				
					q.push(v);					
					in_queue[v] = true;
					counter[v]++;
					if (counter[v] > n-1)
					{
						// ciclo negativo encontrado. Pára o algoritimo
						return true;
					}
				}
			}
		}
	}
	return false;
}


int main()
{
	int u, v, w, m, tc;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d%d", &n, &m);

		adj_list = vvii(n);
		dist = vi(n);

		for (int i=0; i < m; ++i)
		{
			scanf("%d%d%d", &u, &v, &w);			
			adj_list[u].push_back(ii(v, w));
		}

		/*
		Como estamos querendo procurar ciclos negativos, podemos procurar
		em qualquer vértice.
		*/
		if (spfa(0))
		{
			printf("possible\n");
		}
		else
		{
			printf("not possible\n");
		}

	}	

	return 0;
}