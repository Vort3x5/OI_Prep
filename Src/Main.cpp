#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

struct Edge
{
    int dest;
    bool tres;
};

struct Node
{
    vector <Edge> deston;
    bool vis;
};

int n, m, src, dest;

vector <Node> graph, dfs_g, rev_dfs_g, scc_g;
stack <int> topo_sort;
v_i scc;


void Init()
{
    scanf("%d%d", &n, &m);
    graph.resize(n + 10);
    dfs_g.resize(n + 10);
    rev_dfs_g.resize(n + 10);
    scc.resize(n + 10);
    for (int i = 0; i < m; ++i)
    {
        int v, u, art;
        scanf("%d%d%d", &v, &u, &art);
        
        graph[v].deston.pb({u, (bool)art});
        graph[u].deston.pb({v, (bool)art});
    }
    scanf("%d%d", &src, &dest);
}

void BuildDfsTree(int v = 1)
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

void TopoSort(int v = 1)
{
    dfs_g[v].vis = true;
    for (Edge node : dfs_g[v].deston)
        if (!dfs_g[node.dest].vis)
            TopoSort(node.dest);
    topo_sort.push(v);
}

void InitScc(int v, int i)
{
    dfs_g[v].vis = false;
    scc[v] = i;
    for (Edge node : rev_dfs_g[v].deston)
        if (dfs_g[node.dest].vis)
            InitScc(node.dest, i);
}

bool SccDfs(int v = scc[src])
{
    graph[v].vis = false;
    for (Edge node : graph[v].deston)
    {
        if (node.tres && scc[src] == scc[node.dest])
            return true;
        else if (graph[node.dest].vis)
            return SccDfs(node.dest);
    }
    return false;
}

bool Res()
{
    return (SccDfs() && scc[src] == scc[dest]);
}

void Solve()
{
    BuildDfsTree();
    TopoSort();
    for (int i = 1; !topo_sort.empty();)
    {
        if (dfs_g[topo_sort.top()].vis)
            InitScc(topo_sort.top(), i++);
        topo_sort.pop();
    }
    printf("%s\n", Res() ? "YES" : "NO");
}

int main()
{
    Init();
    Solve();

    return 0;
}
