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
    bool destroyed = false;
    int dfs_vis;
    int sub_tree_count = 1;
};

int n, k, curr = 1;

vector <Edge> graph;
v_i res;
v_i sres;

void Init()
{
    scanf("%d%d", &n, &k);
    graph.resize(n + 10);
    res.resize(n + 10);
    sres.resize(n + 10);
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

void sDfs(int node, int dist = 1)
{
    --res[dist];
    ++sres[dist];
    graph[node].dfs_vis = curr;
    for (auto &v : graph[node].dest)
    {
        if (graph[v].dfs_vis != curr)
            Dfs(v, dist + 1);
    }
}

int CentroidDfs(int v)
{
    graph[v].dfs_vis = curr;
    for (auto node : graph[v].dest)
    {
        if (graph[node].dfs_vis != curr && !graph[node].destroyed)
            graph[v].stc += CentroidDfs(node);
    }
    return graph[v].stc;
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

int CentroidDecomposition(int v)
{
    CentroidDfs(v);
    ++curr;
    int centroid = FindCentroid(v);
    int r = 0;
    graph[centroid].destroyed = true;
    Dfs(centroid);
    ++curr;
    for (int i = 0; i < graph[centroid].dest.size(); ++i)
    {
        if (!graph[graph[centroid].dest[i]].destroyed)
        {
            sDfs(graph[centroid].dest[i]);
            for (int i = 1; i <= k; ++i)
            {
                if (!sres[i])
                    break;
                r += sres[i] * res[k - i];
                sres[i] = 0;
            }
        }
    }
    res[0] = 0;
    ++curr;
    for (int i = 0; i < graph[centroid].dest.size(); ++i)
    {
        if (!graph[graph[centroid].dest[i]].destroyed)
            r += CentroidDecomposition(graph[centroid].dest[i]);
    }
    return r;
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
