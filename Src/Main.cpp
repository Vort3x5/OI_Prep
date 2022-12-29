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
    { return (lhs.second < rhs.second); }

s32 n, m;
u64 res;

vector <p32> parent;
vector <vector <p32>> graph, mst;
priority_queue <p32, vector <p32>, decltype(&cmp)> trl;
bitset <1000010> vis;

void Init()
{
    cin >> n >> m;
    graph.resize(m + 10);
    mst.resize(m + 10);
    parent.resize(n + 10);
    for (s32 i = 0; i < m; ++i)
    {
        s32 src, dest, w;
        cin >> src >> dest >> w;
        graph[src].pb({ dest, w });
    }
    for (s32 v = 1; v <= n; ++v)
        parent[v] = v;
}

inline s32 Find(s32 v)
    { return (parent[v] == v ? v : v = Find(parent[v])); }

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
    p32 p = trl.top();
    mst[v].pb(p);
    mst[p.first].pb({ v, p.second });
    Union(v, p.first);
    trl = priority_queue <p32, vector <p32>, decltype(&cmp)> ();
    BFS(p.first);
}

void MstDfs(s32 v)
{
    vis[v] = false;
    for (p32 &edge : mst[v])
    {
        if (vis[edge.first])
            MstDfs(edge.first);
        else
        {
            for (p32 &e : graph[v])
            {
            }
        }
    }
}

void MST(s32 v)
{
}

void DFS(s32 v)
{
    vis[v] = true;
    for (p32 &edge : mst[v])
    {
        if (!vis[edge.first])
        {
            res += edge.second;
            DFS(edge.first);
        }
    }
}

void Solve()
{
    for (s32 v = 1; v <= n; ++v)
    {
        if (!vis[v])
            BFS(v);
        trl = priority_queue <p32, vector <p32>, decltype(&cmp)> ();
    }
    MST(1);
    DFS(1);
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}

