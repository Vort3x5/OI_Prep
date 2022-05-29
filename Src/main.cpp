#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

struct Edge
{
    vector <int> childern;
    int pos;
};

struct Node
{
    int val;
};

int t, N, Q, lfs, l, root, mx_val = 1010;

vector <Edge> graph;
deque <int> found;
vector <Node> tree;

void Init()
{
    scanf("%d", &N);
    graph.resize(N + 10);
    graph.clear();
    found.resize(0);
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
            graph[v].childern.pb(q);
        }
    }
}

void Insert(int node, int v)
{
    tree[v].val = node;
    v /= 2;
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
    tree.resize(lfs * 2);
    for (int v = 0; v < found.size(); ++v)
        Insert(found[v], v + lfs);
}

void Dfs(int v, int i = 1)
{
    graph[v].pos += !graph[v].pos * i;
    found.pb(graph[v].pos);
    for (auto node : graph[v].childern)
    {
        Dfs(node, ++i);
        found.pb(graph[v].pos);
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
        BuildTree();
        printf("Case %d:\n", i);
        for (int i = 0; i < Q; ++i)
        {
            int v, q;
            scanf("%d%d", &v, &q);
            printf(
                "%d\n", Query(
                            graph[v].pos <= graph[q].pos ? graph[v].pos : graph[q].pos,
                            graph[v].pos <= graph[q].pos ? graph[q].pos : graph[v].pos));
        }
    }
}

int main()
{
    Solve();

    return 0;
}
