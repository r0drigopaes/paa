/*
Huxley 921 - Coin Change - Minimizar as moedas
Programação Dinâmica
Rodrigo Paes
*/
#include <bits/stdc++.h>
using namespace std;
#define N 7
#define MAX_CHANGE 10000
#define INF MAX_CHANGE*2

int coins[N] = {200, 100, 50, 25, 10, 5, 1};
int memo[MAX_CHANGE+1];

int dp(int change)
{
	if (change < 0)
	{
		return INF; //não é possível operar em um valor negativo
	}

	if (memo[change] != -1)
	{
		return memo[change]; // DP	
	}
	else if (change == 0) 
	{
		memo[change] = 0; // 0 moedas para produzir 0 'dinheiro'
	}
	else
	{
		int minimum = INF;
		for (int i=0; i < N; ++i)
		{
			minimum = min(minimum, 1 + dp( change - coins[i]));
		}
		memo[change] = minimum;
	}
	
	return memo[change];
}

int main()
{
	int change;
	while (scanf("%d", &change) != EOF)
	{
		memset(memo, -1, sizeof memo);
		printf("%d\n", dp(change));
	}
	return 0;
}