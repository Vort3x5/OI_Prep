#include <bits/stdc++.h>
using namespace std;

struct Inputs
{
    int n;
    bool wrong = false;
    vector <vector <pair <int, int>>> Tree;
    vector <pair <int, int>> qs;
    vector <bool> vis;
};

int t;

vector <Inputs> arr;
int prims[2] = {2, 5};

void Init()
{
    cin >> t;
    arr.resize(t);
    for (auto &i : arr)
    {
        cin >> i.n;
        i.Tree.resize(i.n);
        i.qs.resize(i.n);
        i.vis.resize(i.n + 10);
        for (int j = 0; j < i.n; ++j)
        {
            int u, v;
            cin >> u >> v;
            i.qs[j].first = u;
            i.qs[j].second = v;
            i.Tree[u].push_back({v, 0});
            i.Tree[v].push_back({u, 0});
            i.wrong = max(i.wrong, (i.Tree[u].size() > 2 || i.Tree[v].size() > 2));
        }
    }
}

void DFS(Inputs obj)
{
    int i = 0;
    for (auto v : obj.Tree)
    {
        i = !i;
    }
}

void Solve()
{
    for (int i = 0; i < t; ++i)
    {
        if (arr[i].wrong)
        {
            cout << -1 << '\n';
            continue;
        }
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
