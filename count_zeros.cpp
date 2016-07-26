/*
http://www.practice.geeksforgeeks.org/problem-page.php?pid=897
Count the Zeros
Divide and Conquer
Rodrigo Paes
*/
#include <bits/stdc++.h>
using namespace std;

int a[30];
int n;

int dq(int b, int e)
{
	if (b == e)
	{
		return b;
	}
	int mid = (b + e) / 2;
	if (a[mid] == 1)
	{
		return dq(mid + 1, e);
	}
	else
	{
		return dq(b, mid);
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
		}		
		
		printf("%d\n", n - dq(0,n));
	}
	return 0;
}