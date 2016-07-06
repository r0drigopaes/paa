#include <bits/stdc++.h>
using namespace std;

vector<int> simple_merge(vector<int> &a, vector<int> &b)
{
    int total, j, k;

    total = a.size() + b.size();
    j = 0;
    k = 0;

    vector<int> c(total);

    a.push_back(INT_MAX);
    b.push_back(INT_MAX);

    for (int i = 0; i < total; i++)
    {
        c[i] = (a[j] < b[k]) ? a[j++] : b[k++];
    }

    a.erase(a.end() - 1);
    b.erase(b.end() - 1);

    return c;
}

int main()
{
    int n1, n2, x;
    vector<int> a, b;

    scanf("%d%d", &n1, &n2);

    for (int i = 0; i < n1; ++i)
    {
        scanf("%d", &x);
        a.push_back(x);
    }

    for (int i = 0; i < n2; ++i)
    {
        scanf("%d", &x);
        b.push_back(x);
    }

    vector<int> result;

    result = simple_merge(a, b);

    for (int i = 0; i < result.size(); ++i)
    {
        printf("%d\n", result[i]);
    }

    return 0;
}
