#include "../../pch.h"

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

struct Edge
{
    vector <int> dest;
    int weight[20];
    int parent[20];
    int pre, pos;
};

struct Node
{
    int val;
};

int t, N, Q, lfs, l, root, mx_val = 1010, s_time;

vector <Edge> graph;
vector <int> found;
vector <int> pre;
vector <Node> tree;

void Init()
{
    scanf("%d", &N);
    graph.resize(N + 10);
    pre.resize(N + 10);
    graph.clear();
    found.clear();
    tree.clear();
    for (int v = 1; v <= N; ++v)
    {
        int M;
        scanf("%d", &M);
        root += !root * v;
        for (int j = 0; j < M; ++j)
        {
            int q;
            scanf("%d", &q);
            graph[v].dest.pb(q);
        }
    }
}

void Insert(int node, int v)
{
    tree[v].val = node;
    while(v)
    {
        tree[v].val = min(tree[v * 2].val, tree[(v * 2) + 1].val);
        v /= 2;
    }
}

void BuildTree()
{
    lfs = 1 << int(log2(found.size()) + 1);
    l = lfs - 1;
    for (int v = 1; v <= found.size(); ++v)
        Insert(found[v], v + l);
}

void Dfs(int v, int par = 1)
{
    graph[v].parent[0] = par;
    // graph[v].weight[0] = graph[v].w;
    for (int i = 1; i < 20; ++i)
    {
        graph[v].parent[i] = graph[graph[v].parent[i - 1]].parent[i - 1];
        graph[v].weight[i] = graph[v].weight[i - 1] + graph[graph[v].parent[i - 1]].weight[i - 1];
    }
    found.pb(graph[v].pre);
    graph[v].pre = ++s_time;
    pre[graph[v].pre] = v;
    for (auto node : graph[v].dest)
    {
        Dfs(node, v);
        found.pb(graph[v].pre);
    }
    graph[v].pos = ++s_time;
}

bool IsAnc(int a, int b)
{
    return graph[a].pre < graph[b].pre && graph[a].pos > graph[b].pos;
}

int Lca(int a, int b)
{
    if (IsAnc(a, b))
        return a;
    else if (IsAnc(b, a))
        return b;
    else
    {
        for (int i = 20 - 1; i >= 0; --i)
        {
            if (!IsAnc(graph[a].parent[i], b))
                a = graph[a].parent[i];
        }
        return graph[a].parent[0];
    }
}

int Query(int q_a, int q_b, int a = 1, int b = lfs, int v = 1)
{
    if (b < q_a || a > q_b)
        return mx_val;
    else if (q_a <= a || b <= q_b)
        return tree[v].val;
    else
    {
        int mid = (a + b) / 2;
        return min(
                Query(q_a, q_b, a, mid, v * 2), 
                Query(q_a, q_b, mid + 1, b, (v * 2) + 1));
    }
}

void Solve()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i)
    {
        Init();
        scanf("%d", &Q);
        Dfs(root);
        printf("Case %d:\n", i);
        for (int i = 0; i < Q; ++i)
        {
            int v, q;
            scanf("%d%d", &v, &q);
            printf(
                "%d\n", pre[Query(
                            graph[v].pre <= graph[q].pre ? graph[v].pre : graph[q].pre,
                            graph[v].pre <= graph[q].pre ? graph[q].pre : graph[v].pre)]);
        }
    }
}

int main()
{
    Solve();

    return 0;
}
