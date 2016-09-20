/*
UVA 147 - Coin Change - Contar de quantas maneiras diferentes
Programação Dinâmica
Rodrigo Paes
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define N 11
#define MAX_CHANGE 30000
#define INF MAX_CHANGE*2


int coins[N] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
lli memo[N+1][MAX_CHANGE+1];

/*
Quantas formas diferntes de dar um troco.
*/
lli dp(int i, int change)
{

	if (change < 0)
	{
		return 0; //não é possível operar em um valor negativo
	}
	if (memo[i][change] != -1)
	{
		return memo[i][change]; // DP	
	}
	
	if (change == 0) 
	{
		memo[i][change] = 1; // considerando que não dar nada é uma maneira de dar troco.
	}
	else if ( i == N )
	{
		memo[i][change] = 0; // já considerou todas os tipos de moedas
	}
	else
	{
		// considerar incluir a moeda e ignorar
		memo[i][change] = dp(i, change - coins[i]) + dp( i+1, change);
	}
	// printf("(%d,%d)=%lld\n",i,change, memo[i][change]);
	
	return memo[i][change];
}

int main()
{
	int int_part, frac_part;
	scanf("%d.%d", &int_part, &frac_part);
	while (int_part !=0 || frac_part!=0 )
	{		
		memset(memo, -1, sizeof memo);
		printf("%6.2f%17lld\n", int_part + frac_part/100.0, dp(0, int_part*100 + frac_part));
		scanf("%d.%d", &int_part, &frac_part);
	}
	return 0;
}