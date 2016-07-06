/*
Soma máxima: dividir e conquistar
O(n log(n))
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000
int a[MAX];

int divide_and_conquer(int left, int right)
{
    // condição de parada: um único elemento
    if (left == right)
    {
        // verifica se o valor é positivo
        if (a[left] > 0)
        {
            return a[left];
        }
        else
        {
            return 0;
        }
    }
    else
    {
    int sum = 0;
    int mid = (left + right) / 2;

    // soma parte esquerda
    int max_left = 0;
    for (int k = mid; k >= left; --k)
    {
        sum += a[k];
        if (sum > max_left)
        {
            max_left = sum;
        }
    }

    // soma parte direita
    int max_right = 0;
    sum = 0;
    for (int k = mid + 1; k <= right; ++k)
    {
        sum += a[k];
        if (sum > max_right)
        {
            max_right = sum;
        }
    }

    return max(
            max(
              divide_and_conquer(left, mid),
              divide_and_conquer(mid+1, right)
             ),
              max_left + max_right
          );
    }
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

        printf("%d\n", divide_and_conquer(0, n - 1));
    }

    return 0;
}
