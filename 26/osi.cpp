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

s32 n, m, curr = 1;

vector <v32> graph;
v32 vis, low;
bitset <1000010> is_root;

void Init()
{
    cin >> n >> m;
    graph.resize(n + 10);
    vis.resize(n + 10);
    low.resize(n + 10);
    for (s32 i = 0; i < m; ++i)
    {
        s32 src, dest;
        cin >> src >> dest;
        graph[src].pb(dest);
        graph[dest].pb(src);
    }
}

s32 DFS(s32 v = 1, s32 d = 1)
{
    vis[v] = curr;
    low[v] = d;
    depth[v] = d;
    for (s32 node : graph[v])
    {
        if (vis[node] != vis[v])
            low[v] = min(DFS(node, d + 1), low[v]);
    }
}

void Solve()
{
    for (s32 v = 1; v <= n; ++v)
    {
        if (vis[v] != curr)
        {
            is_root[v] = true;
            DFS(v);
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

