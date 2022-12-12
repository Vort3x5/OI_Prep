#include <bits/stdc++.h>

#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_back

using namespace std;

typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;
typedef pair <int, int> p_i;
typedef pair <s64, s64> p_ll;
typedef vector <int> v_i;
typedef vector <s64> v_ll;

s32 n, r, q;
u64 dists[1001][1001], curr;
v_i t, vis;
vector <vector <p_i>> graph;
bitset <1000010> is;

void Init()
{
    cin >> n >> r;
    t.resize(n + 10);
    graph.resize(n + 10);
    vis.resize(n + 10);
    for (s32 v = 1; v <= n; ++v)
    {
        cin >> t[v];
        is[t[v]] = true;
    }
    for (s32 i = 1; i < n; ++i)
    {
        s32 src, dest, dist;
        cin >> src >> dest >> dist;
        graph[src].pb({dest, dist});
        graph[dest].pb({src, dist});
    }
}

void Dfs(s32 u, s32 v, s32 dist)
{
    vis[v] = curr;
    dists[u][v] = dist;
    for (p_i &node : graph[v])
    {
        if (vis[node.first] != curr)
            Dfs(u, node.first, dist + node.second);
    }
}

void Sub1()
{
    for (s32 v = 1; v <= n; ++v)
    {
        ++curr;
        Dfs(v, v, 0);
    }
    cin >> q;
    for (s32 qr = 0; qr < q; ++qr)
    {
        s32 pk, qk, sk;
        cin >> pk >> qk >> sk;
        if (!is[sk])
        {
            cout << -1 << '\n';
            continue;
        }
        u64 res = 1000000010;
        for (s32 v = 1; v <= n; ++v)
            if (t[v] == sk)
                res = min(res, dists[pk][v] + dists[qk][v]);
        cout << res << '\n';
    }
}

void Solve()
{
    Sub1();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}

