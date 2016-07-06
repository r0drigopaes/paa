#include <bits/stdc++.h>
using namespace std;

vector<int> merge_sort(const vector<int> &data)
{
    if (data.size() <= 1) {
        return data;
    }

    int middle = data.size() / 2;
    vector<int> left(data.begin(), data.begin()+middle);
    vector<int> right(data.begin()+middle, data.end());

    left = merge_sort(left);
    right = merge_sort(right);

    vector<int> result(data.size());

    merge(left.begin(), left.end(),
          right.begin(), right.end(),
          result.begin());

    return result;
}

int main()
{
    int n, x;
    vector<int> a;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d",&x);
        a.push_back(x);
    }

    vector<int> result = merge_sort(a);
    for (int i = 0; i < result.size(); ++i)
    {
        printf("%d\n", result[i]);
    }

    return 0;
}
