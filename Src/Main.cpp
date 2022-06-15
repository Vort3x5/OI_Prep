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
    int deep;
};

int n, m, src, dest;

vector <Node> graph;
vector <Node> dfs_g;

void Init()
{
    scanf("%d%d", &n, &m);
    graph.resize(n + 10);
    dfs_g.resize(n + 10);
    for (int i = 0; i < m; ++i)
    {
        int v, u, art;
        scanf("%d%d%d", &v, &u, &art);
        
        graph[v].deston.pb({u, (bool)art});
        graph[u].deston.pb({v, (bool)art});
    }
    scanf("%d%d", &src, &dest);
}

void CountDeep(int v = 1, int d = 1)
{
    dfs_g[v].vis = false;
    dfs_g[v].deep = d;
    for (auto node : dfs_g[v].deston)
    {
        if (dfs_g[node.dest].vis)
            CountDeep(node.dest, d + 1);
    }
}

void BuildDfsTree(int v = 1)
{
    graph[v].vis = true;
    for (auto node : graph[v].deston)
    {
        if (!graph[node.dest].vis)
        {
            dfs_g[v].deston.pb(node);
            BuildDfsTree(node.dest);
        }
        else
            dfs_g[node.dest].deston.pb({v, graph[v].deston[node.dest].tres});
    }
}

void Solve()
{
    BuildDfsTree();
    CountDeep();
}

int main()
{
    Init();
    Solve();

    return 0;
}
