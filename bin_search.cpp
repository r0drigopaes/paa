#include <bits/stdc++.h>
using namespace std;

/*
Left inclusivo
right exclusivo
*/
int find_x(int *a, int left, int right, int x)
{
    if (left == right)
    {
        if (x == a[left]) return left;
        else return -1;
    }
    int mid = (left + right) / 2;

    if (a[mid] == x) return mid;
    else if (x < a[mid]) return find_x(a, left, mid, x);
    else return find_x(a, mid+1, right, x);
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
    printf("%d\n", find_x(a,0,n,x));

    return 0;
}
