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

#define stc sub_tree_count

s32 n, k, curr = 1;

vector <v32> graph;
bitset <1000010> vand;
v32 sub_tree_count, res, sres, vis;

void Init()
{
    cin >> n >> k;
    graph.resize(n + 10);
    res.resize(n + 10);
    sres.resize(n + 10);
    vis.resize(n + 10);
    stc.resize(n + 10, 1);
    for (s32 i = 0; i < (n - 1); ++i)
    {
        s32 src, dest;
        cin >> src >> dest;
        graph[src].pb(dest);
        graph[dest].pb(src);
    }
    res[0] = 1;
}

s32 InitDFS(s32 v = 1, s32 dist = 0)
{
    vis[v] = curr;
    for (s32 &e : graph[v])
    {
        if (vis[e] != curr && !vand[e])
            stc[v] += InitDFS(e, dist + 1);
    }
    return stc[v];
}

s32 FindCentroid(s32 v)
{
    vis[v] = curr;
    for (s32 &e : graph[v])
    {
        if (vis[e] != curr && !vand[e] && stc[e] > (stc[v] / 2))
        {
            stc[v] -= stc[e];
            stc[e] += stc[v];
            return e;
        }
    }
    return v;
}

void All(s32 v, s32 dist = 0)
{
    res[dist] += (bool)dist;
    vis[v] = curr;
    for (s32 &e : graph[v])
        if (!vand[e] && vis[e] != curr)
            All(e, dist + 1);
}

void Sub(s32 v, s32 dist = 0)
{
    ++sres[dist + 1];
    --res[dist + 1];
    vis[v] = curr;
    for (s32 &e : graph[v])
        if (vis[e] != curr && !vand[e])
            Sub(e, dist + 1);
}

s32 Decomp(s32 v, s32 r = 0)
{
    s32 centroid = FindCentroid(v);
    ++curr;
    vand[centroid] = true;
    All(centroid);
    ++curr;
    for (s32 &e : graph[centroid])
    {
        if (!vand[e])
        {
            Sub(e);
            ++curr;
            for (s32 i = 1; i <= k; ++i)
                r += sres[i] * res[k - i];
            fill(sres.begin(), sres.end(), 0);
        }
    }
    for (s32 &e : graph[centroid])
        if (!vand[e])
            r += Decomp(e);
    return r;
}

void Solve()
{
    InitDFS();
    ++curr;
    cout << Decomp(1) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}

