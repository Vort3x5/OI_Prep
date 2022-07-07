#include <bits/stdc++.h>
using namespace std;

int q, n, lfs, l;

string s, t;
vector <int> tree;

void Init()
{
    scanf("%d", &n);
    cin >> s >> t;
    lfs = 1 << int(log2(n) + 1);
    l = lfs - 1;
    tree.resize(2 * lfs);
}

void Insert(int v, int x)
{
    while (v /= 2)
        tree = tree[v * 2] + tree[(v * 2) + 1];
}

int Query()
{}

void Solve()
{
    scanf("%d", &q);
    for (int i = 0; i < q; ++i)
    {
        Init();
        if (n == 1)
        {
            printf("%s\n", s[0] == t[0] ? "YES" : "NO");
            continue;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}

