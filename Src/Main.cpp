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
typedef pair <int, int> p32;
typedef pair <s64, s64> p64;
typedef vector <s32> v32;
typedef vector <s64> v64;

bool cmp(p32 lhs, p32 rhs)
    { return (lhs.second > rhs.second); }

s32 n, m;

vector <s32> parent;
vector <p32> dist;
vector <vector <p32>> graph, mst;
priority_queue <p32, vector <p32>, decltype(&cmp)> trl(cmp);
bitset <1000010> vis;

void Init()
{
    cin >> n >> m;
    graph.resize(m + 10);
    mst.resize(m + 10);
    parent.resize(n + 10);
    dist.resize(n + 10, {0, 1000010});
    for (s32 i = 0; i < m; ++i)
    {
        s32 src, dest, w;
        cin >> src >> dest >> w;
        graph[src].pb({ dest, w });
        graph[dest].pb({ src, w });
    }
    for (s32 v = 1; v <= n; ++v)
        parent[v] = v;
}

inline s32 Find(s32 v)
    { return (parent[v] == v ? v : parent[v] = Find(parent[v])); }

void Union(s32 v, s32 u)
{
    v = Find(v);
    u = Find(u);
    if (v != u)
        parent[u] = v;
}

void BFS(s32 v)
{
    vis[v] = true;
    for (p32 &edge : graph[v])
        if (!vis[Find(edge.first)])
            trl.push(edge);
    if (trl.empty())
        return;
    p32 e = trl.top();
    mst[v].pb(e);
    mst[e.first].pb({ v, e.second });
    Union(Find(v), e.first);
    trl = priority_queue <p32, vector <p32>, decltype(&cmp)> ();
    if (!vis[e.first])
        BFS(e.first);
}

void MST()
{
    bool merged = false;
    while (!merged)
    {
        for (s32 v = 1; v <= n; ++v)
        {
            for (p32 &edge : graph[v])
                if (Find(v) != Find(edge.first) && edge.second < dist[Find(v)].second)
                    dist[Find(v)] = edge;
        }
        for (s32 v = 1; v <= n; ++v)
        {
            if (dist[Find(v)].first)
            {
                Union(Find(v), Find(dist[Find(v)].first));
                mst[v].pb(dist[Find(v)]);
            }
        }
        dist.resize(n + 10, {0, 1000010});
        s32 allfather = Find(1);
        merged = true;
        for (s32 v = 2; v <= n; ++v)
        {
            if (Find(v) != allfather)
            {
                merged = false;
                break;
            }
        }
    }
}

u64 DFS(s32 v = 1, u64 res = 0)
{
    vis[v] = false;
    for (p32 &edge : mst[v])
        if (vis[edge.first])
            res += edge.second + DFS(edge.first);
    return res;
}

void Solve()
{
    for (s32 v = 1; v <= n; ++v)
    {
        if (!vis[v])
            BFS(v);
        trl = priority_queue <p32, vector <p32>, decltype(&cmp)> ();
    }

    MST();
    cout << DFS() << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}

