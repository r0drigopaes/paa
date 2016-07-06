/*
Soma máxima: Programação Dinâmica
O(n)
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000
int a[MAX];

/**
A ideia é aplica o principio da otimalidade. Ou seja, a solução ótima é composta de subsoluções ótimas.
Neste caso, se uma soma ficar negativa, ela esse intervalo não pode fazer parte de uma solução ótima, ou seja,
essa subsolução não é ótima e , portanto, pode ser descartada.
*/
int pd(int n)
{
    int first, sum, max_sum, i, j;

    first = sum = max_sum = i = j = 0;

    for (int last = 0; last < n; ++last)
    {
        sum += a[last];
        if (sum > max_sum)
        {
            max_sum = sum;
            i = first;
            j = last;
        }
        else if (sum < 0)
        {
            first = last+1;
            sum = 0;
        }
    }

    return max_sum;
}

int main()
{
    int n;

    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }

        printf("%d\n", pd(n));
    }

    return 0;
}
