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

s32 t, n, curr = 1;
bool fnd;

vector <vector <p32>> graph;
vector <p32> id;
v32 vis;

void Init()
{
    cin >> n;
    graph.resize(n + 10);
    id.resize(n + 10);
    vis.resize(n + 10);
    for (s32 i = 0; i < (n - 1); ++i)
    {
        s32 src, dest, w;
        cin >> src >> dest >> w;
        graph[src].pb({dest, w});
        graph[dest].pb({src, w});
        id[i] = { src, dest };
    }
}

void Insert(p32 edge, s32 val)
{
    for (s32 i = 0; i < graph[edge.first].size(); ++i)
        if (graph[edge.first][i].first == edge.second)
            graph[edge.first][i].second = val;
}


s32 Query(s32 a, s32 b, s32 r = 0)
{
    vis[a] = curr;
    if (a == b)
    {
        fnd = true;
        return r;
    }
    for (p32 &e : graph[a])
    {
        if (vis[e.first] != curr)
        {
            s32 buff = Query(e.first, b, e.second); 
            if (fnd)
                return max(buff, r);
        }
    }
    return r;
}

void Solve()
{
    cin >> t;
    for (s32 qr = 0; qr < t; ++qr)
    {
        Init();
        string q;
        s32 x, y;
        cin >> q >> x >> y;
        while (q != "DONE")
        {
            if (q == "CHANGE")
                Insert(id[x - 1], y);
            else if (q == "QUERY")
            {
                cout << Query(x, y) << '\n';
                ++curr, fnd = false;
            }
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

