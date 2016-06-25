#include <bits/stdc++.h>
using namespace std;

/*
n >=1
*/
double powering(double x, int n)
{
	if (n==1) return x;

	double half;
	if (n%2==0)
	{
		half = powering(x, n/2);
		return half * half;
	}
	else
	{
		half = powering(x, (n-1)/2 );
		return half * half * x;
	}
}

int main()
{
	double x;
	int n;
	scanf("%lf%d",&x,&n);
	printf("%.2lf\n", powering(x,n));
	return 0;
}