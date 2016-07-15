#include <bits/stdc++.h>
using namespace std;

int find_x(int *a, int n, int x)
{
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int *a;
    int n, x;

    scanf("%d",&n);

    a = (int *) malloc(sizeof(int) * n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }

    scanf("%d", &x);

    printf("%d\n", find_x(a,n,x));

    return 0;
}
