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

s32 t, n, curr = 1, l, lfs, pre = 1;

vector <vector <p32>> graph;
v32 vis, sub_tree_count, head, depth, tree, pos, parent, id;

void Init()
{
    cin >> n;
    lfs = (1 << (int(log2(n + 1)) + 1));
    l = lfs - 1;
    graph.resize(n + 10);
    vis.resize(n + 10);
    id.resize(n + 10);
    stc.resize(n + 10, 1);
    head.resize(n + 10);
    parent.resize(n + 10);
    depth.resize(n + 10);
    pos.resize(n + 10);
    tree.resize(lfs * 2);
    for (s32 i = 0; i < (n - 1); ++i)
    {
        s32 src, dest, w;
        cin >> src >> dest >> w;
        graph[src].pb({dest, w});
        graph[dest].pb({src, w});
        id[i] = dest;
    }
    parent[1] = 1;
    stc[0] = 0;
}

inline void Insert(s32 node, s32 val)
{
    tree[node] = val;
    while (node /= 2)
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

s32 Query(s32 qa, s32 qb, s32 ta = 1, s32 tb = lfs, s32 node = 1)
{
    if (ta > qb || tb < qa)
        return 0;
    else if (ta >= qa && tb <= qb)
        return tree[node];
    else
    {
        s32 mid = (ta + tb) / 2;
        return max(Query(qa, qb, ta, mid, node * 2), Query(qa, qb, mid + 1, tb, node * 2 + 1));
    }
}

s32 InitCount(s32 v = 1, s32 d = 1, s32 w = 0)
{
    vis[v] = curr;
    depth[v] = d;
    pos[v] = pre++;
    Insert(pos[v] + l, w);
    for (p32 &e : graph[v])
    {
        if (vis[e.first] != curr)
        {
            stc[v] += InitCount(e.first, d + 1, e.second);
            parent[e.first] = v;
        }
    }

    return stc[v];
}

void Decomp(s32 v = 1, s32 h = 1)
{
    head[v] = h;
    vis[v] = curr;
    s32 heavy = 0;
    for (p32 &e : graph[v])
        if (vis[e.first] != curr && stc[heavy] < stc[e.first])
            heavy = e.first;

    for (p32 &e : graph[v])
    {
        if (vis[e.first] != curr && e.first == heavy)
            Decomp(e.first, h);
        else if (vis[e.first] != curr)
            Decomp(e.first, e.first);
    }
}

s32 HldQr(s32 a, s32 b)
{
    s32 res = 0;
    while (head[a] != head[b])
    {
        if (depth[head[a]] > depth[head[b]])
        {
            res = max(res, Query(pos[head[a]], pos[a]));
            a = parent[head[a]];
        }
        else
        {
            res = max(res, Query(pos[head[b]], pos[b]));
            b = parent[head[b]];
        }
    }
    if (pos[a] < pos[b])
        res = max(res, Query(pos[a], pos[b]));
    else
        res = max(res, Query(pos[b], pos[a]));
    return res;
}

void Solve()
{
    cin >> t;
    for (s32 qr = 0; qr < t; ++qr)
    {
        Init();
        InitCount();
        ++curr;
        Decomp();
        string q;
        s32 x, y;
        cin >> q;
        if (q != "DONE")
            cin >> x >> y;
        while (q != "DONE")
        {
            if (q == "CHANGE")
                Insert(pos[id[x - 1]] + l, y);

            else if (q == "QUERY")
                cout << HldQr(x, y) << '\n';

            cin >> q;
            if (q != "DONE")
                cin >> x >> y;
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

