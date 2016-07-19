#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000  // 10 elevado a 5
#define MAX_GUESS 1000000000000

typedef long long int lli;

int n;
int a[MAX_N];

bool is_possible(lli k)
{
	lli diff;
	for (int i=0; i<n; ++i)
	{
		if (i==0)
		{
			diff = a[i];
		}
		else
		{
			diff = a[i]-a[i-1];	
		}
		
		if ( diff == k )
		{
			--k;
			if (k<0) return false;
		}
		else if (diff > k)
		{
			return false;
		}		
	}
	return true;
}

lli binary_guess_answer(lli begin, lli end)
{	
	// printf("Guess [%lld, %lld]\n", begin, end);
	if (end == begin)
	{
		return begin;
	}

	lli mid = (begin+end)/2;
	if (is_possible(mid))
	{
		return binary_guess_answer(begin, mid);
	}
	else
	{
		return binary_guess_answer(mid+1, end);
	}
}

int main()
{
	int total;
	lli ans;
	scanf("%d",&total);
	for (int tc=1; tc<=total; ++tc)
	{
		scanf("%d",&n);		
		for (int i=0; i<n; ++i)
		{
			scanf("%d", &a[i]);
		}
		ans = binary_guess_answer( 1, MAX_GUESS );


		printf("Case %d: %lld\n", tc, ans);
	}
}