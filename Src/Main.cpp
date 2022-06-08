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
    int in, out;
    bool vis;
};

int n, m, start, s_end;

vector <Edge> graph;
vector <int> akt;
deque <int> eul_path;
bitset <2000010> e_vis;

void Init()
{
    scanf("%d%d", &n, &m);
    graph.resize(n + 10);
    akt.resize(n + 10);
    for (int i = 1; i <= m; ++i)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        graph[v].deston.pb(u);
        graph[v].id.pb(i);
    }
}

void CountDegrees(int v)
{
    graph[v].vis = true;
    for (auto node : graph[v].deston)
    {
        ++graph[v].out;
        ++graph[node].in;
        if (!graph[node].vis)
            CountDegrees(node);
    }
}

void FindEulPath(int v)
{
    while (akt[v] < graph[v].id.size())
    {
        int node = akt[v];
        ++akt[v];
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
    {
        switch (graph[v].out - graph[v].in)
        {
            case 0:
                break;

            case 1:
                cycle = false;
                if (!start)
                    start = v;
                else
                {
                    printf("IMPOSSIBLE\n");
                    return;
                }
                break;
            
            case -1:
                cycle = false;
                if (!s_end)
                    s_end = v;
                else
                {
                    printf("IMPOSSIBLE\n");
                    return;
                }
                break;
            
            default:
                cycle = false;
                break;
        }
    }
    if (!cycle && (!start || !s_end))
    {
        printf("IMPOSSIBLE\n");
        return;
    }

    if (cycle)
        start = 1;
    FindEulPath(start);
    
    if (!WereVisited() || eul_path.back() != n)
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
