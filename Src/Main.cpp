#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

#define stc sub_tree_count

struct Edge
{
    vector <p_i> dest;
};

int t, N, curr_pos, res;

vector <Edge> graph;
v_i parent, depth, heavy, head, pos;

void Init()
{
    scanf("%d", &N);
    graph.resize(N + 10);
    parent = v_i(N + 10, 0);
    depth = v_i(N + 10, 0);
    heavy = v_i(N + 10, -1);
    head = v_i(N + 10, 0);
    pos = v_i(N + 10, 0);
    curr_pos = 0;
    for (int i = 1; i < N; ++i)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        graph[a].dest.pb({b, c});
        graph[b].dest.pb({a, c});
    }
}

int Dfs(int v = 1)
{
    int size = 1, max_node_size = 0;
    for (auto node : graph[v].dest)
    {
        if (node.first != parent[v])
        {
            parent[node.first] = v, depth[node.first] = depth[v] + 1;
            int node_size = Dfs(node.first);
            size += node_size;
            if (node_size > max_node_size)
                max_node_size = node_size, heavy[v] = node.first;
        }
    }
    return size;
}

void Decompose(int v = 1, int h = 1)
{
    head[v] = h, pos[v] = curr_pos++;
    if (heavy[v] != -1)
        Decompose(heavy[v], h);
    for (auto node : graph[v].dest)
    {
        if (node.first != parent[v] && node.first != heavy[v])
            Decompose(node.first, node.first);
    }
}

int HldQr(int v, int u)
{
    res = 0;
    for (; head[v] != head[u]; u = parent[head[u]])
    {
        if (depth[head[v]] > depth[head[u]])
            swap(v, u);
        // res = max(res, Query(pos[head[u]], pos[u]))
    }
    if (depth[v] > depth[u])
        swap(v, u);
    // res = max(res, Query(pos[v], pos[u]));
    return res;
}

void Solve()
{
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
    {
        Init();
        Dfs();
        Decompose();
    }
}

int main()
{
    Init();
    Solve();

    return 0;
}
