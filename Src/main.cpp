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

};

vector <Edge> graph;
stack <int> roots;

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

void Solve()
{
    for (int v = 1; v <= n; ++v)
    {
        if (!graph[v].parents)
            roots.push(v);
    }

    if (roots.empty()) // or a cycle is found
        cout << "IMPOSSIBLE\n";

    while (!roots.empty())
    {
        Bfs();
        roots.pop();
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
