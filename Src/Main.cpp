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

int t, N, curr_pos, res, l, lfs;

vector <Edge> graph;
v_i parent, depth, heavy, head, pos, tree, dist;

void Init()
{
    scanf("%d", &N);
    lfs = 1 << int(log2(N) + 1);
    l = lfs - 1;
    graph.resize(N + 10);
    tree = v_i(2 * lfs, 0);
    parent = v_i(N + 10, 0);
    dist = v_i(N + 10, 0);
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

int Dfs(int w, int v = 1)
{
    int size = 1, max_node_size = 0;
    dist[v] = w;
    for (auto node : graph[v].dest)
    {
        if (node.first != parent[v])
        {
            parent[node.first] = v, depth[node.first] = depth[v] + 1;
            int node_size = Dfs(node.second, node.first);
            size += node_size;
            if (node_size > max_node_size)
                max_node_size = node_size, heavy[v] = node.first;
        }
    }
    return size;
}

void Insert(int v, int x)
{
    tree[v] = x;
    for (v /= 2; v; v /= 2)
        tree[v] = max(tree[v * 2], tree[(v * 2) + 1]);
}

int Query(int q_a, int q_b, int v = 1, int t_a = 1, int t_b = lfs)
{
    if (t_a > q_b || t_b < q_a)
        return 0;
    else if (t_a >= q_a && t_b <= q_b)
        return tree[v];
    else
    {
        int mid = (t_a + t_b) / 2;
        return max(Query(q_a, q_b, v * 2, t_a, mid), Query(q_a, q_b, (v * 2) + 1, mid + 1, t_b));
    }
}

void Decompose(int v = 1, int h = 1)
{
    head[v] = h, pos[v] = curr_pos++;
    Insert(curr_pos + l, dist[v]);
    if (heavy[v] != -1)
        Decompose(heavy[v], h);
    for (p_i node : graph[v].dest)
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
    res = max(res, Query(pos[head[u]] + 1, pos[u] + 1));
    }
    if (depth[v] > depth[u])
        swap(v, u);
    res = max(res, Query(pos[v] + 1, pos[u] + 1));
    return res;
}

void Solve()
{
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
    {
        Init();
        Dfs(0);
        Decompose();
        string qr;
        int a, b;
        cin >> qr;
        while (qr != "DONE")
        {
            scanf("%d%d", &a, &b);
            
            if (qr == "CHANGE")
                Insert(a + l, b);
            
            else if (qr == "QUERY")
                printf("%d\n", HldQr(a, b));
            cin >> qr;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Solve();

    return 0;
}
