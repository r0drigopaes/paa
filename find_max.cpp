#include <bits/stdc++.h>
using namespace std;

int find_max(int a[], int n)
{
    int m = a[0];

    for (int i = 1; i < n; ++i)
    {
        if (a[i] > m )
        {
            m = a[i];
        }
    }

    return m;
}

int main()
{
    int x[] = {3, 4, 46, 34, 5};

    printf("%d\n", find_max(x, 5));

    return 0;
}
