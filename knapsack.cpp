/*
Problema da Mochila
Huxley 790

Rodrigo Paes
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 10
#define MAX_M 1000

int memo[MAX_N+1][MAX_M];
int p[MAX_N];
int w[MAX_N];
int c, n;

int dp(int i, int rc)
{
	if (memo[i][rc]!=-1) return memo[i][rc];
	// printf("[%d][%d]\n", i, rc);

	// parada
	if (i == n) // já olhou todos os elementos
	{
		memo[i][rc] = 0;
	} 
	else if ( rc == 0 )  // a mochila já acabou
	{
		memo[i][rc] = 0;
	}
	else if ( w[i] > rc ) // o item não cabe na mochila, ignora
	{		
		memo[i][rc] = dp(i+1, rc);
	}
	else
	{
		// colocar ou não colocar
		memo[i][rc] = max( p[i] + dp(i+1, rc-w[i]), dp(i+1, rc) );
	}
	return memo[i][rc];

}

int main()
{
	memset(memo, -1, sizeof memo);
	scanf("%d%d", &n, &c);
	for (int i=0; i < n; ++i)
	{
		scanf("%d", &p[i]);
	}
	for (int i=0; i < n; ++i)
	{
		scanf("%d", &w[i]);
	}

	printf("%d\n", dp(0,c));


	return 0;
}