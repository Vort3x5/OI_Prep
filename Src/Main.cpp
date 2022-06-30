#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

struct Edge
{
    v_i deston, id;
    int deg;
    bool vis;
};

int n, m;

vector <Edge> graph;
deque <int> eul_path;
bitset <2000010> e_vis;

void Init()
{
    scanf("%d%d", &n, &m);
    graph.resize(n + 10);
    for (int i = 1; i <= m; ++i)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        graph[v].deston.pb(u);
        graph[v].id.pb(i);

        graph[u].deston.pb(v);
        graph[u].id.pb(i);
    }
}

void CountDegrees(int v)
{
    graph[v].vis = true;
    for (auto node : graph[v].deston)
    {
        ++graph[v].deg;
        if (!graph[node].vis)
            CountDegrees(node);
    }
}

void FindEulPath(int v)
{
    for (int node = 0; node < graph[v].id.size(); ++node)
    {
        if (!e_vis[graph[v].id[node]])
        {
            e_vis[graph[v].id[node]] = true;
            FindEulPath(graph[v].deston[node]);
        }
    }
    eul_path.push_front(v);
}

bool WereVisited()
{
    for (int v = 1; v <= n; ++v)
    {
        for (auto edge : graph[v].id)
            if (!e_vis[edge])
                return false;
    }
    return true;
}

void Solve()
{
    for (int v = 1; v <= n; ++v)
        if (!graph[v].vis)
            CountDegrees(v);
    
    bool cycle = true;
    for (int v = 1; v <= n; ++v)
        if (graph[v].deg % 2)
            cycle = false;
    if (!cycle || graph[1].deston.empty())
    {
        printf("IMPOSSIBLE\n");
        return;
    }
    FindEulPath(1);
    if (!WereVisited() || eul_path.back() != 1)
    {
        printf("IMPOSSIBLE\n");
        return;
    }

    for (auto res : eul_path)
        printf("%d ", res);
    printf("\n");
}

int main()
{
    Init();
    Solve();

    return 0;
}
