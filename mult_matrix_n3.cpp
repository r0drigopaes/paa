/*
Multiplicação de Matrizes em n^3
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

struct matrix
{
	int **data;

	matrix(int l, int c)
	{
		data.resize(l);
		for (int i=0; i< c; ++i)
	}
};

/*
Pré-condições:
As matrizes tem pelo menos 1 linha e 1 coluna. 

a.size()>0
a[0].size()>0

b.size()>0
b[0].size()>0

Além disso, o número de colunas de a é igual ao número de linhas de b
*/
int mult_matrix(matrix a, matrix b)
{
	if (a)
}

int main()
{
	return 0;
}