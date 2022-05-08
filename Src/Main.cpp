#include <bits/stdc++.h>

#define pb push_back
#define pf push_front
#define stc sub_tree_count

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

struct Edge
{
    vector <int> dest;
    bool vis;
    bool destroyed = false;
    int dfs_vis;
    int sub_tree_count = 1;
};

int n, k, curr;

vector <Edge> graph;
v_i res;

void Init()
{
    scanf("%d%d", &n, &k);
    graph.resize(n + 10);
    res.resize(n + 10);
    for (int i = 0; i < (n - 1); ++i)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        graph[v].dest.pb(u);
        graph[u].dest.pb(v);
    }
}

void Dfs(int node, int dist = 0)
{
    ++res[dist];
    graph[node].dfs_vis = curr;
    for (auto &v : graph[node].dest)
    {
        if (graph[v].dfs_vis != curr)
            Dfs(v, dist + 1);
    }
}

int CentroidDfs(int node)
{
    graph[node].dfs_vis = curr;
    graph[node].vis = true;
    for (auto &v : graph[node].dest)
    {
        if (graph[v].dfs_vis != curr && !graph[v].vis)
            graph[v].stc += CentroidDfs(v);
    }
    return graph[node].stc;
}

int FindCentroid(int node)
{
    for (auto &v : graph[node].dest)
    {
        if (graph[v].dfs_vis != curr && (graph[v].stc > (graph[node].stc / 2)))
        {
            graph[node].stc -= graph[v].stc;
            graph[v].stc += graph[node].stc;
        }
    }
    return node;
}

int CentroidDecomposition(int v, int val = k)
{
    CentroidDfs(v);
    ++curr;
    int centroid = FindCentroid(v);
    graph[centroid].destroyed = true;
    for (int i = 0; i < graph[centroid].dest.size(); ++i)
    {
        if (!graph[graph[centroid].dest[i]].destroyed)
            return CentroidDecomposition(graph[centroid].dest[i]);
    }
    return res[k];
}

void Solve()
{
    printf("%d", CentroidDecomposition(1));
}

int main()
{
    Init();
    Solve();

    return 0;
}
