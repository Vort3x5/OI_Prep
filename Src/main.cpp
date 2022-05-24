#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

struct Edge
{
    vector <int> deston;
    bool vis = false, scc_vis = false;
};

int n, m;

vector <Edge> graph;
vector <vector <int>> rev_g;
vector <vector <int>> scc_g;
stack <int> topo_sort;
vector <int> scc;
vector <int> sum;
vector <int> res;

void Init()
{
    scanf("%d%d", &n, &m);
    graph.resize(n + 10);
    rev_g.resize(n + 10);
    scc_g.resize(n + 10);
    scc.resize(n + 10);
    sum.resize(n + 10);
    res.resize(n + 10);
    for (int e = 0; e < m; ++e)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        graph[v].deston.pb(u);
        rev_g[u].pb(v);
    }
}

void Dfs(int v)
{
    graph[v].vis = true;
    for (auto &node : graph[v].deston)
        if (!graph[node].vis)
            Dfs(node);
    topo_sort.push(v);
}

void SccInitDfs(int v, int i)
{
    graph[v].scc_vis = true;
    scc[v] = i;
    for (auto node : rev_g[v])
        if (!graph[node].scc_vis)
            SccInitDfs(node, i);
}

int SccDfs(int v = 1)
{
    for (auto node : scc_g[v])
        res[v] += SccDfs(node);
    return sum[scc[v]];
}

void Solve()
{
    for (int v = 1; v <= n; ++v)
        if (!graph[v].vis)
            Dfs(v);
    for (int i = 1; !topo_sort.empty();)
    {
        if (!graph[topo_sort.top()].scc_vis)
            SccInitDfs(topo_sort.top(), i++);
        topo_sort.pop();
    }
    for (int v = 1; v <= n; ++v)
    {
        for (auto node : graph[v].deston)
            if (scc[v] != scc[node])
                scc_g[scc[v]].pb(scc[node]);
    }
    for (int v = 1; v <= n; ++v)
        ++sum[scc[v]];
    SccDfs();

    for (int v = 1; v <= n; ++v)
        printf("%d\n", res[scc[v]]);
}

int main()
{
    Init();
    Solve();

    return 0;
}
