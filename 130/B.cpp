#include <bits/stdc++.h>
using namespace std;

int n, q, res;

vector <int> p;
int used[1000010];

bool cmp(int a, int b) { return a > b; }

void Init()
{
    scanf("%d%d", &n, &q);
    p.resize(n);
    for (int &i : p)
        scanf("%d", &i);
}

void Solve()
{
    sort(p.begin(), p.end(), cmp);
    int x, y;
    for (int i = 0; i < q; ++i)
    {
        scanf("%d%d", &x, &y);
        for (int j = x - 1, z = 0; j >= 0 && z < y; --j, ++z)
            res += (used[p[j]] != i + 1) * p[j], used[p[j]] = i + 1;
        printf("%d\n", res);
        res = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}
