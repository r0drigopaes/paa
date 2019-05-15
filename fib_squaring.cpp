#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef lli M[2][2];

M m = {{1, 1}, {1, 0}};

void multi_matrix(M a, M b, M c)
{
    c[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    c[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    c[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    c[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
}

void assign(M a, M b)
{
    a[0][0] = b[0][0];
    a[0][1] = b[0][1];
    a[1][0] = b[1][0];
    a[1][1] = b[1][1];
}

/*
n >=1
*/
void powering(M a, M result, int n)
{
    if (n == 1)
    {
        assign(result, a);

        return;
    }

    M half;

    if (n % 2 == 0)
    {
        powering(a, half, n / 2);
        multi_matrix(half, half, result);

        return;
    }
    else
    {
        M temp;

        powering(a, half, (n - 1) / 2);
        multi_matrix(half, half, temp);
        multi_matrix(temp, a, result);

        return;
    }
}

lli fib(int n)
{
    M result;
    powering(m, result, n);

    return result[0][1];
}

int main()
{
    int n;

    scanf("%d", &n);

    if (n == 0)
    {
        cout << "0\n";
    }
    else
    {
        printf("%lld\n", fib(n));
    }

    return 0;
}
