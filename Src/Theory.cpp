#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

struct Edge
{
    int deep, stc = 1, heavy = -1, parent, pos, head, w;
    v_i deston;
    v_i dist;
    bool vis;
};

int n, lfs, l, pos;

vector <Edge> graph;
vector <int> tree;

void Init()
{
    scanf("%d", &n);
    graph.resize(n + 10);
    lfs = 1 << int(log2(n - 1) + 1);
    l = lfs - 1;
    tree.resize(2 * lfs);
    for (int i = 1; i < n; ++i)
    {
        int v, w, u;
        graph[v].deston.pb(u);
        graph[v].dist.pb(w);
        
        graph[u].deston.pb(v);
        graph[u].dist.pb(w);
    }
}

void Insert(int x, int v)
{
    while (v)
    {
        tree[v] += x;
        v /= 2;
    }
}

int Query(int q_a, int q_b, int t_a = 1, int t_b = lfs, int v = 1)
{
    if (t_a > q_b || t_b < q_a)
        return 0;
    else if (t_a >= q_a && t_b <= q_b)
        return tree[v];
    else
    {
        int mid = (t_a + t_b) / 2;
        return Query(q_a, q_b, t_a, mid, v * 2) + Query(q_a, q_b, mid + 1, t_b, (v * 2) + 1);
    }
}

int Dfs(int v, int p, int w, int d = 1)
{
    graph[v].vis = true;
    graph[v].deep = d;
    graph[v].parent = p;
    graph[v].w = w;
    for (int node = 0; node < graph[v].deston.size(); ++node)
    {
        if (!graph[graph[v].deston[node]].vis)
            graph[v].stc += Dfs(graph[v].deston[node], v, graph[v].dist[node], d + 1);
    }
    for (int node : graph[v].deston)
    {
        if (node != p)
        {
            if (graph[v].heavy == -1 || graph[graph[v].heavy].stc <= graph[node].stc)
                graph[v].heavy = node;
            else
                graph[v].heavy = graph[v].heavy;
        }
    }
    return graph[v].stc;
}

void Decompose(int h, int v)
{
    graph[v].pos = pos++;
    Insert(pos + l - 1, graph[v].w);
    graph[v].head = h;
    if (graph[v].heavy == -1)
        return;
    Decompose(h, graph[v].heavy);
    for (int node : graph[v].deston)
    {
        if (node != graph[v].heavy && node != graph[v].parent)
            Decompose(node, node);
    }
}

int HldQr(int a, int b)
{
    int res = 0;
    while (graph[a].head != graph[b].head)
    {
        if (graph[graph[a].head].deep < graph[graph[b].head].deep)
            swap(a, b);
        res += Query(graph[graph[a].head].pos, graph[a].pos);
        a = graph[graph[a].head].parent;
    }
    if (a != b)
        res += Query(graph[a].pos < graph[b].pos ? graph[a].pos : graph[b].pos, graph[a].pos > graph[b].pos ? graph[a].pos - 1 : graph[b].pos - 1);
    return res;
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
