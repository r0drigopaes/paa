#include <bits/stdc++.h>
using namespace std;


/* n>=0 */
long long int fib(int n)
{
	if (n<=1) return n;

	return fib(n-1) + fib(n-2);
}

int main()
{
	
	int n;
	scanf("%d",&n);
	printf("%lld\n", fib(n));
	return 0;
}