#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int n, m;

struct Edge
{
    vector <int> dests;
    int parents = 0;
    bool vis;
};

vector <Edge> graph;
stack <int> roots, topo_sort;

void Init()
{
    cin >> n >> m;
    graph.resize(n + 10);
    for (int v = 0; v < m; ++v)
    {
        int src, dest;
        cin >> src >> dest;
        graph[src].dests.push_back(dest);
        ++graph[dest].parents;
    }
}

void Bfs()
{
    queue <int> nodes;
    nodes.push(roots.top());
    while (!nodes.empty())
    {
        cout << nodes.front() << ' ';
        for (auto &v : graph[nodes.front()].dests)
        {
            if (graph[v].parents < 2)
                nodes.push(v);
            else
                --graph[v].parents;
        } 
        nodes.pop();
    }
}

bool Dfs(int v, vector <bool> vis)
{
    if (vis[v])
        return false;
    vis[v] = true;
    for (auto node : graph[v].dests)
        return Dfs(node, vis);
    return true;
}

bool IsCycle(stack <int> nodes)
{
    vector <bool> vis(n + 10);
    while (!nodes.empty())
    {
        if (!Dfs(nodes.top(), vis))
            return true;
    }
    return false;
}

void TopoSort(int v)
{
    graph[v].vis = true;
    for (auto node : graph[v].dests)
        if (!graph[node].vis)
            TopoSort(node);
    topo_sort.push(v);
}

void Solve()
{
    for (int v = 1; v <= n; ++v)
    {
        if (!graph[v].parents)
            roots.push(v);
    }

    if (roots.empty() || IsCycle(roots))
        cout << "IMPOSSIBLE\n";
    
    for (int v = 1; v <= (m * 2); ++v)
        if (!graph[v].vis)
            TopoSort(v);
    
    /*while (!roots.empty())
    {
        Bfs();
        roots.pop();
    }*/
    while (!topo_sort.empty())
    {
        printf("%d ", topo_sort.top());
        topo_sort.pop();
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}
