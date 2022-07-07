#include <bits/stdc++.h>
using namespace std;

int t, n, m, res;

vector <int> arr;

void Init()
{
    scanf("%d%d", &n, &m);
    arr.resize(n);
    res = 0;
    for (int &i : arr)
    {
        scanf("%d", &i);
        res += i;
    }
}

void Solve()
{
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
    {
        Init();
        printf("%d\n", res - m > 0 ? res - m : 0);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}
