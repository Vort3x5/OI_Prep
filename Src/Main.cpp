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

int n, m;

vector <Edge> graph;
deque <int> eul_path;
stack <int> start;
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
    graph[v].vis = false;
    for (int node = 0; node < graph[v].deston.size(); ++node)
    {
        if (graph[graph[v].deston[node]].vis)
        {
            --graph[v].out;
            FindEulPath(graph[v].deston[node]);
        }
    }
    eul_path.push_front(v);
}

void Solve()
{
    for (int v = 1; v <= n; ++v)
        if (!graph[v].vis)
            CountDegrees(v);
    for (int v = 1; v < n; ++v)
    {
        if ((graph[v].out - graph[v].in) == 1)
            start.push(v);
    }
    while (!start.empty())
    {
        if (graph[start.top()].vis)
            FindEulPath(start.top());
        else
        {
            printf("IMPOSSIBLE\n");
            return;
        }
        start.pop();
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
