#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int n, m;
bool start_found;

struct Edge
{
    vector <int> dests;
    bool is_orph = true, bfsd = false;

};

vector <Edge> graph;
stack <int> roots;

void Init()
{
    cin >> n >> m;
    graph.resize(m + 10);
    for (int v = 0; v < m; ++v)
    {
        int src, dest;
        cin >> src >> dest;
        graph[src].dests.push_back(dest);
        graph[dest].is_orph = false;
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
            if (!graph[v].bfsd)
            {
                nodes.push(v);
                graph[v].bfsd = true;
            }
        }
        nodes.pop();
    }
    cout << '\n';
}

void Solve()
{
    for (int v = 1; v <= n; ++v)
    {
        if (graph[v].is_orph)
            roots.push(v);
    }

    if (roots.empty())
        cout << "IMPOSSIBLE\n";

    while (!roots.empty())
    {
        Bfs();
        roots.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}
