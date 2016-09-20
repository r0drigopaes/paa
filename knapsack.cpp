/*
Problema da Mochila
Huxley 790

Rodrigo Paes
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 10000
#define MAX_M 100

int memo[MAX_N+1][MAX_M+1];
int p[MAX_N];
int w[MAX_N];
int c, n;


int dp_bottom_up()
{
	for (int rc=0; rc <= c; ++rc)
	{
		for (int i=n; i >=0; --i)
		{
			if (rc==0 || i==n)
			{
				memo[i][rc] = 0;
			}
			else if (w[i] > rc)
			{
				memo[i][rc] = memo[i+1][rc];
			}
			else
			{
				memo[i][rc] = max( p[i] + memo[i+1][rc-w[i]], memo[i+1][rc] );
			}

		}
	}
	for (int i=0; i<=n; ++i)
	{
		for (int j=0; j<=c; ++j)
		{
			printf("%d ",memo[i][j]);
		}
		printf("\n");
	}
	return memo[0][c];
	
}

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

	// printf("%d\n", dp(0,c));
	printf("%d\n", dp_bottom_up());


	return 0;
}