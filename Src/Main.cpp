#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

struct Edge
{
    v_i deston, dist;
    int deep, parent, pos, head, w, stc = 1, heavy = -1;
    bool vis;
};

int t, N, lfs, l, pos;

vector <Edge> graph;
vector <int> tree;

void Init()
{
    scanf("%d", &N);
    graph.resize(N + 10);
    lfs = 1 << int(log2(N - 1) + 1);
    l = lfs - 1;
    tree.resize(lfs * 2);
    for (int i = 0; i < (N - 1); ++i)
    {
        int v, u, w;
        scanf("%d%d%d", &v, &u, &w);
        graph[v].deston.pb(u);
        graph[v].dist.pb(w);
        
        graph[u].deston.pb(v);
        graph[u].dist.pb(w);
    }
}

void Insert(int x, int v)
{
    tree[v] = x;
    while (v /= 2)
        tree[v] = tree[v * 2] + tree[(v * 2) + 1];
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
        return max(Query(q_a, q_b, t_a, mid, v * 2), Query(q_a, q_b, mid + 1, t_b, (v * 2) + 1));
    }
}

void Solve()
{
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
    {
        Init();
        string qr;
        int a, b;
        while (qr != "DONE")
        {
            cin >> qr;
            scanf("%d%d", &a, &b);
            if (qr == "QUERY")
            {
            }
            else if (qr == "CHANGE")
            {
            }
        }
    }
}

int main()
{
    Init();
    Solve();

    return 0;
}
