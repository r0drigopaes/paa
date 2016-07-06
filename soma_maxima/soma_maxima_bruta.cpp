/*
Força Bruta
O(n^3)
*/

#include <bits/stdc++.h>
#define MAX 1000000

int main()
{
    int a[MAX];
    int max_sum, sum;
    int begin, end;
    int n;

    while (scanf("%d", &n) != EOF)
    {
        max_sum = 0;
        begin = end = -1;

        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }

        for (int first = 0; first < n; ++first)
        {
            for (int last= first; last < n; ++last)
            {
                sum = 0;
                for (int k = first; k <= last; ++k)
                {
                    sum += a[k];
                }

                if (sum > max_sum)
                {
                    max_sum = sum;
                    begin = first;
                    end = last;
                }
            }
        }

        printf("%d %d %d\n", max_sum, begin, end);
    }
}
