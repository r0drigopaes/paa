#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

/*
lo e hi são inclusivos
*/
int partition(vi &a, int lo, int hi)
{
    int pivot = a[hi];
    /*
      O i vai demarcar o final da partição daqueles
      que são menores que o pivô
    */
    int i = lo - 1;

    for (int j = lo; j < hi; ++j)
    {
        if (a[j] <= pivot)
        {
            // temos que crescer a partição dos menores
            ++i;
            swap(a[i], a[j]);
        }
    }

    // coloca o pivô logo depois da partição dos menores
    swap(a[i + 1], a[hi]);
    return i + 1; // índice do pivô
}

/*
lo e hi são inclusivos
*/
void quick_sort(vi &a, int lo, int hi)
{
    if (lo < hi)
    {
        int pos;

        pos = partition(a, lo, hi);

        quick_sort(a, lo, pos - 1);
        quick_sort(a, pos + 1, hi);
    }
}

int main()
{
    int n, j;

    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }

    quick_sort(a, 0, n - 1);

    for (int i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    return 0;
}
