#include <bits/stdc++.h>
using namespace std;

/* n>=0 */
long long int fib(int n)
{
    if (n <= 1) return n;
    long long int f1, f2, f;

    f1 = 0;
    f2 = 0;

    for (int i = 2; i <= n; ++i)
    {
        f = f1 + f2;
        f2 = f1;
        f1 = f;
    }

    return f;
}

int main()
{
    int n;

    scanf("%d",&n);
    printf("%lld\n", fib(n));

    return 0;
}
