#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

struct Edge
{
    vector <int> deston;
    bool vis;
};

int n, m;

vector <Edge> graph;
vector <vector <int>> rev_g;
stack <int> topo_sort;
vector <int> scc;
bitset <100010> given;

void Init()
{
    scanf("%d%d", &n, &m);
    graph.resize(m * 2);
    rev_g.resize(m * 2);
    scc.resize(m * 2);
    for (int i = 0; i < n; ++i)
    {
        char fst[3], snd[3];
        int p, q;
        scanf("%s%d%s%d", fst, &p, snd, &q);
        given[p] = true;
        given[q] = false;

        if (fst[0] == '+' && snd[0] == '+')
        {
            graph[m + p].deston.pb(q);
            graph[m + q].deston.pb(p);

            rev_g[q].pb(m + p);
            rev_g[p].pb(m + q);
        }
        else if (fst[0] == '+' && snd[0] == '-')
        {
            graph[m + p].deston.pb(m + q);
            graph[q].deston.pb(p);
            
            rev_g[m + q].pb(m + p);
            rev_g[p].pb(q);
        }
        else if (fst[0] == '-' && snd[0] == '+')
        {
            graph[p].deston.pb(q);
            graph[m + q].deston.pb(m + p);
            
            rev_g[q].pb(p);
            rev_g[m + p].pb(m + q);
        }
        else if (fst[0] == '-' && snd[0] == '-')
        {
            graph[p].deston.pb(m + q);
            graph[q].deston.pb(m + p);
            
            rev_g[m + q].pb(p);
            rev_g[m + p].pb(q);
        }
    }
}

void TopoSort(int v)
{
    graph[v].vis = true;
    for (auto node : graph[v].deston)
        TopoSort(node);
    topo_sort.push(v);
}

void InitScc(int v, int i)
{
    graph[v].vis = false;
    scc[v] = i;
    for (auto node : rev_g[v])
        if (graph[node].vis)
            InitScc(node, i);
}

void Solve()
{
    for (int v = 1; v <= m; ++v)
        if (!graph[v].vis)
            TopoSort(v);
    for (int i = 1; !topo_sort.empty();)
    {
        if (graph[topo_sort.top()].vis)
            InitScc(topo_sort.top(), i++);
        topo_sort.pop();
    }
    for (int v = 1; v <= m; ++v)
    {
        if (given[v] && scc[v] == scc[v + m])
        {
            printf("IMPOSSIBLE\n");
            return;
        }
    }
    for (int v = 1; v <= m; ++v)
    {
        if (!given[v] || (scc[v] && scc[v + m]))
            printf("- ");
        else
            printf("+ ");
    }
    printf("\n");
}

int main()
{
    Init();
    Solve();

    return 0;
}
