#include <bits/stdc++.h>
using namespace std;

struct Node
{
    long long val;
};

struct Qr
{
    int type, a, b, k;
};

int n, q, lfs, l;

vector <Node> tree;

void Insert(int node, bool add)
{
    node /= 2;
    if (node == 0)
    {
        return;
    }
    tree[node].val = add ? ++tree[node].val : --tree[node].val;
    Insert(node, add);
}

void Init()
{
    cin >> n >> q;
    lfs = (1 << int((log2(n)) + 1));
    l = lfs - 1;
    tree.resize(2 * lfs);
    for (int node = 1; node <= n; ++node)
    {
        cin >> tree[node + l].val;
        tree[node + l].val = !(tree[node + l].val);
        if (tree[node + l].val)
        {
            Insert(node + l, true);
        }
    }
}

int Query(int qr_a, int qr_b, int a = 1, int b = lfs, int node = 1)
{
    if (b < qr_a || a > qr_b)
    {
        return 0;
    }
    else if (a >= qr_a && b <= qr_b)
    {
        return tree[node].val;
    }
    else
    {
        int mid = (a + b) / 2;
        return Query(qr_a, qr_b, a, mid, node * 2)
            + Query(qr_a, qr_b, mid + 1, b, (node * 2) + 1);
    }
}

int Find(Qr qr, int node = 1)
{
    if (node > l)
    {
        return (node - l);
    }
    else
    {
        qr.k -= ((tree[node * 2].val < qr.k) * tree[node * 2].val);
        return Find(qr, (node * 2) + (tree[node * 2].val < qr.k));
    }
}

void Solve()
{
    for (int i = 0; i < q; ++i)
    {
        Qr qr;
        cin >> qr.a >> qr.b;
        switch (qr.type)
        {
            case 1:
                if (tree[qr.a + l].val && qr.b)
                {
                    continue;
                }
                Insert(qr.a, tree[qr.a + l].val);
                tree[qr.a + l].val = !qr.b;
                break;
            
            case 2:
                cin >> qr.k;
                qr.k += Query(1, qr.a);
                cout << Find(qr) << '\n';
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
