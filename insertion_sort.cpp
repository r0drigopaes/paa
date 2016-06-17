#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int a[], int n)
{
	int key, i;
	for (int j=1; j < n; ++j)
	{
		key = a[j];

		i = j-1;
		while (i >= 0 && a[i] > key)
		{
			a[i+1] = a[i];
			i--;
		}
		a[i+1] = key;
	}
}

int main()
{
	int x[] = {3,2,46,34,5};
	insertion_sort(x,5);
	for (int i=0; i< 5; ++i)
	{
		printf("%d ",x[i]);
	}
	printf("\n");
	return 0;
}