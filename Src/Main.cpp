#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

struct Edge
{
    ll dest;
    bool tres;
};

struct Node
{
    vector <Edge> deston;
    bool vis;
};

ll n, m, src, dest, tres_scc;

vector <Node> graph, dfs_g, rev_dfs_g, scc_g;
stack <ll> topo_sort;
v_i scc;


void Init()
{
    cin >> n >> m;
    graph.resize(n + 10);
    dfs_g.resize(n + 10);
    rev_dfs_g.resize(n + 10);
    scc.resize(n + 10);
    scc_g.resize(n + 10);
    for (ll i = 0; i < m; ++i)
    {
        ll v, u, art;
        cin >> v >> u >> art;
        
        graph[v].deston.pb({u, (bool)art});
        graph[u].deston.pb({v, (bool)art});
    }
    cin >> src >> dest;
}

void BuildDfsTree(ll v = 1)
{
    graph[v].vis = true;
    for (Edge node : graph[v].deston)
    {
        if (!graph[node.dest].vis)
        {
            dfs_g[v].deston.pb(node);
            rev_dfs_g[node.dest].deston.pb({v, dfs_g[v].deston[node.dest].tres});
            BuildDfsTree(node.dest);
        }
        else
            dfs_g[node.dest].deston.pb({v, graph[v].deston[node.dest].tres}), rev_dfs_g[v].deston.pb({node.dest, graph[v].deston[node.dest].tres});
    }
}

void TopoSort(ll v = 1)
{
    dfs_g[v].vis = true;
    for (Edge node : dfs_g[v].deston)
        if (!dfs_g[node.dest].vis)
            TopoSort(node.dest);
    topo_sort.push(v);
}

void InitScc(ll v, ll i)
{
    dfs_g[v].vis = false;
    scc[v] = i;
    for (Edge node : rev_dfs_g[v].deston)
        if (dfs_g[node.dest].vis)
            InitScc(node.dest, i);
}

void TresScc(ll v = 1)
{
    graph[v].vis = false;
    for (Edge node : graph[v].deston)
    {
        if (graph[v].deston[node.dest].tres && scc[v] == scc[node.dest])
            tres_scc = scc[v];
        if (graph[node.dest].vis)
            TresScc(node.dest);
    }
}

bool Res(ll v = scc[src], bool found = false)
{
    scc_g[v].vis = true;
    if (v == scc[dest])
        return found;
    for (Edge node : scc_g[v].deston)
    {
        if (tres_scc == scc[node.dest] || node.tres)
            found = true;
        if (!scc_g[node.dest].vis)
            return Res(node.dest, found);
    }
}

void Solve()
{
    BuildDfsTree();
    TopoSort();
    for (ll i = 1; !topo_sort.empty();)
    {
        if (dfs_g[topo_sort.top()].vis)
            InitScc(topo_sort.top(), i++);
        topo_sort.pop();
    }
    for (ll v = 1; v <= n; ++v)
    {
        for (Edge node : graph[v].deston)
            if (scc[v] != scc[node.dest])
                scc_g[scc[v]].deston.pb({scc[node.dest], node.tres});
    }
    TresScc();
    cout << ((scc[src] == scc[dest] && scc[src] == tres_scc) || Res() ? "YES" : "NO") << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}
