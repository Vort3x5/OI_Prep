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
    int dfs_vis;
    int sub_tree_count;
};

int n, k, curr;

vector <Edge> graph;

void Init()
{
    scanf("%d%d", &n, &k);
    graph.resize(n + 10);
    for (int i = 0; i < (n - 1); ++i)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        graph[v].dest.pb(u);
        graph[u].dest.pb(v);
    }
}

int Dfs(int node)
{
    graph[node].dfs_vis = curr;
    graph[node].vis = true;
    for (auto &v : graph[node].dest)
    {
        if (graph[v].dfs_vis != curr && !graph[v].vis)
            graph[v].stc += Dfs(v);
    }
    return graph[node].stc;
}

int FindCentroid(int node)
{
    for (auto &v : graph[node].dest)
    {
        if (graph[v].dfs_vis != curr && (graph[v].stc > (graph[node].stc / 2)))
            return FindCentroid(v);
    }
    return node;
}

void Solve()
{ 
}

int main()
{
    Init();
    Solve();

    return 0;
}
