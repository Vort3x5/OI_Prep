#include <bits/stdc++.h>
using namespace std;

struct Qr
{
    int type, a, b;
};

struct Node
{
    long long val, a, b;
};

int n, q, l, lfs;
vector <Node> tree;

void Init()
{
    cin >> n >> q;
    lfs = (1 << int((log2(n)) + 1));
    l = lfs - 1;
    tree.resize(2 * lfs);
    for (int v = 1; v <= n; ++v)
    {
        cin >> tree[v + l].val;
        for (int node = v + l; node > 0; node /= 2)
        {
            tree[node].val += tree[v + l].val;
        }
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

int Query(Qr qr, int v = 1)
{
    if (qr.a == 1 && qr.b == n)
    {
        return tree[1].val;
    }
    if (tree[v].a > qr.b || tree[v].b < tree[v].a)
    {
        return 0;
    }
    else if (tree[v].a >= qr.a && tree[v].b <= qr.b)
    {
        return tree[v].val;
    }
    else
    {
        return (Query(qr, v * 2) + Query(qr, (v * 2) + 1));
    }
}

void Insert(Qr qr)
{
    int add_b = qr.b;
    int add_a = tree[qr.a + l].val;
    for (int node = qr.a + l; node > 0; node /= 2)
    {
        tree[node].val -= add_a;
        tree[node].val += add_b;
    }
}

void Solve()
{
    for (int i = 0; i < q; ++i)
    {
        Qr qr;
        cin >> qr.type >> qr.a >> qr.b;
        switch(qr.type)
        {
            case 1:
                Insert(qr);
                break;

            case 2:
                cout << Query(qr) << '\n';
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
