#include <bits/stdc++.h>
using namespace std;

struct Qr
{
    int r, a, b, c;
};

struct Node
{
    long long val, add, a, b;
};

int n, q, l, lfs;
vector <Node> tree;

void Init()
{
    cin >> n >> q;
    lfs = (1 << int((log2(n)) + 1));
    tree.resize(2 * lfs);
    l = lfs - 1;
    for (int i = 1; i <= n; ++i)
    {
        cin >> tree[i + l].val;
    }
    tree[1].a = 1, tree[1].b = lfs;
    for (int node = 1; node < (1 + l); ++node)
    {
        tree[node * 2].a = tree[node].a;
        tree[node * 2].b = (tree[node].a + tree[node].b) / 2;
        
        tree[(node * 2) + 1].a = (tree[node].a + tree[node].b) / 2 + 1;
        tree[(node * 2) + 1].b = tree[node].b;
    }
}

bool IsInRange(long long v, long long node)
{
    return ((tree[v].b >= node && node >= tree[v].a) || node == (v - l));
}

long long Query(long long node, long long v = 1, long long res = 0)
{
    if (v == (node + l))
    {
        return (res + tree[node + l].val + tree[node + l].add);
    }
    else
    {
        return (IsInRange(v * 2, node) ? Query(node, v * 2, res + tree[v].add) 
                : Query(node, (v * 2) + 1, res + tree[v].add));
    }
}

void Insert(Qr &q, long long v = 1)
{
    if (tree[v].b < q.a || tree[v].a > q.b)
    {
        return;
    }
    else if (tree[v].a >= q.a && tree[v].b <= q.b)
    {
        tree[v].add += q.c;
    }
    else
    {
        Insert(q, v * 2);
        Insert(q, (v * 2) + 1);
    }

}

void Solve()
{
    for (int i = 0; i < q; ++i)
    {
        Qr q;
        cin >> q.r;
        switch (q.r)
        {
            case 1:
                cin >> q.a >> q.b >> q.c;
                Insert(q);
                break;

            case 2:
                cin >> q.a;
                cout << Query(q.a) << '\n';
                break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}
