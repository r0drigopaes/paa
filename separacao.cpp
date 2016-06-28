/**
Este programa separa todos negativos dos positivos em um array.
*/

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

/*
Separa um array colocando todos os negativos antes de j e os positivos depois d de j
Mas essa função não garante que todos os elementos após e antes de j estejam ordenados.
*/
void sep(vi &a, int b, int e, int *j)
{
	*j = b;
	for (int i=b; i <= e ; ++i)
	{
		if (a[i] < 0)
		{
			swap(a[*j], a[i]);
			(*j)++;
		}
	}

}

int main()
{

	
	int n, j;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i=0; i<n; ++i)
	{
		scanf("%d", &a[i]);
	}
	
	sep(a, 0, n-1, &j);
	printf("j=%d\n",j);
	for (int i=0; i<n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}