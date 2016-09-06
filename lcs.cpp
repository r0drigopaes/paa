#include <bits/stdc++.h>
using namespace std;


typedef vector<int> vi;

// usado para as versões top_down e bottom_up, mas não é usado para a versão com economia de memória
vector<vi> memo; 
string a, b;

int lcs_bottom_memory_trick(int i , int j)
{
	vector<vi> small_memo(2);
	for (int k=0; k <2; ++k)
	{
		small_memo[k].resize(j+1, 0);
	}	

	for (int k=0; k <2; ++k)
	{
		for (int x=0; x <= j; ++x)
		{
			printf("[%d] ", small_memo[k][x]);
		}
		printf("\n");
	}
	
	int prev = 0, curr = 1;
	for (int n=1; n <= i; ++n)
	{
		for (int m=1; m <= j; ++m)
		{
			if (a[n-1] == b[m-1])
			{
				small_memo[curr][m] = 1 + small_memo[prev][m-1];
			}
			else
			{
				small_memo[curr][m] = max (small_memo[curr][m-1], small_memo[prev][m]);
			}
		}
		for (int k=0; k <2; ++k)
		{
			for (int x=0; x <= j; ++x)
			{
				printf("[%d] ", small_memo[k][x]);
			}
			printf("\n");
		}
		printf("\n");

		prev = curr;
		curr = (curr + 1) %2;

	}
	return small_memo[1][j];
}

/*
Bottom up sem economia de memória
*/
int lcs_bottomup(int i, int j)
{
	for (int k=0; k < i; ++k)
	{
		memo[k][0] = 0;
	}
	for (int k=0; k < j; ++k)
	{
		memo[0][k] = 0;
	}

	for (int n=1; n <= i; ++n)
	{
		for (int m=1; m <= j; ++m)
		{
			if (a[n-1] == b[m-1])
			{
				memo[n][m] = 1 + memo[n-1][m-1];
			}
			else
			{
				memo[n][m] = max (memo[n][m-1], memo[n-1][m]);
			}
		}
	}
	return memo[i][j];
}

/*
Top down sem economia de memória
*/
int lcs_topdown(int i, int j)
{	

	if (memo[i][j] != -1)
	{		
		return memo[i][j];
	}
	if (i==0 || j==0)
	{	
		memo[i][j] = 0;
	}
	else
	{
		if (a[i-1] == b[j-1])
		{	
			memo[i][j] = 1 + lcs_topdown(i-1, j-1);
		}
		else
		{		
			memo[i][j] = max(lcs_topdown(i, j-1), lcs_topdown(i-1, j));
		}	
	}
	
	return memo[i][j];
}

int main()
{

	cin >> a >> b;
	// Trecho para as versões sem economia de memória
	memo.resize(a.length()+1);
	for (int i=0; i <= a.length(); ++i)
	{
		memo[i].resize(b.length()+1, -1);
	}

	printf("%d\n", lcs_topdown(a.length(), b.length()) );
	// printf("%d\n", lcs_bottomup(a.length(), b.length()) );
	// printf("%d\n", lcs_bottom_memory_trick(a.length(), b.length()) );

	return 0;
}