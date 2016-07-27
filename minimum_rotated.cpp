/*
http://www.practice.geeksforgeeks.org/problem-page.php?pid=819	
Minimum element in a sorted and rotated array
Divide and Conquer
Rodrigo Paes
*/
#include <bits/stdc++.h>
using namespace std;

#define MAX_N 500
int a[MAX_N];
int n;

int dq(int b, int e)
{
	// printf("(%d, %d)\n", b, e);
	if (e - b == 2)
	{
		return min(a[b], a[e-1]);
	}
	else if (e - b == 1)
	{
		return a[b];
	}

	int mid = (b + e) / 2;
	// printf("a[%d]=%d\n", mid, a[mid]);
	/*
	Se o elemento do final do intervalo é maior que o atual, 
	significa que todos os elementos entre eles são maiores que o mid.
	Logo a resposta só pode ser o próprio mid ou então alguém do lado esquerdo.
	*/
	if (a[mid] < a[e-1])
	{
		return dq(b, mid+1); // lado esquerdo. Perceba que incluí o próprio mid
	}
	else
	{
		return dq(mid + 1, e);
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		// printf("\n\n####\n");
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
		}		
		
		printf("%d\n", dq(0,n));
	}
	return 0;
}