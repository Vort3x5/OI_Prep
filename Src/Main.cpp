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

vector <Node> graph, dfs_g, rest;
v_i low, depth;


void Init()
{
    scanf("%d%d", &n, &m);
    graph.resize(n + 10);
    dfs_g.resize(n + 10);
    low.resize(n + 10);
    depth.resize(n + 10);
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
            dfs_g[node.dest].deston.pb({v, dfs_g[v].deston[node.dest].tres});
            BuildDfsTree(node.dest);
        }
        else
            rest[node.dest].deston.pb({v, graph[v].deston[node.dest].tres}), rest[v].deston.pb({node.dest, graph[v].deston[node.dest].tres});
    }
}

void CountLow(int v = 1)
{
    dfs_g[v].vis = true;
    low[v] = depth[v];

    for (Edge node : dfs_g[v].deston)
    {
        if (!dfs_g[node.dest].vis)
        {
            depth[node.dest] = depth[v] + 1;
            CountLow(node.dest);
            low[v] = min(low[v], low[node.dest]);
        }
    }

    for (int node = 0; node < rest[v].deston.size(); ++node)
        low[v] = min(low[v], depth[rest[v].deston[node].dest]);
}

int Find()
{
    return 0;
}

void Union()
{}

bool Res(int v = 1)
{
    graph[v].vis = false;
    for (Edge node : graph[v].deston)
    {
    }
    return false;
}

void Solve()
{
    BuildDfsTree();
    CountLow();
    printf("%s\n", Res() ? "YES" : "NO");
}

int main()
{
    Init();
    Solve();

    return 0;
}
