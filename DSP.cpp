#include <bits/stdc++.h>
using namespace std;

struct Qr
{
    int type, a, b;
};

struct Node
{
    int val, a, b;
};

int n, q, l, lfs;
vector <Node> tree;
vector <Qr> qs;

void Init()
{
    cin >> n >> q;
    lfs = (1 << int((log2(n)) + 1));
    l = lfs - 1;
    tree.resize(2 * lfs);
    qs.resize(q);
    for (int v = 1; v <= n; ++v)
    {
        cin >> tree[v + l].val;
        for (int node = v + l; node > 0; node /= 2)
        {
            tree[node].val += tree[v + l].val;
        }
    }
    for (int i = 0; i < q; ++i)
    {
        cin >> qs[i].type >> qs[i].a >> qs[i].b;
    }
}

int Query(Qr q, int v = 1)
{
    if (tree[v].a > q.b || tree[v].b < tree[v].a)
    {
        return 0;
    }
    else if (tree[v].a >= q.a && tree[v].b <= q.b)
    {
        return tree[v].val;
    }
    else
    {
        return (Query(q, v * 2) + Query(q, (v * 2) + 1));
    }
}

void Insert(Qr q)
{
    int add_b = tree[q.b + l].val;
    int add_a = tree[q.a + l].val;
    for (int node = q.a + l; node > 0; node /= 2)
    {
        tree[node].val -= add_a;
        tree[node].val += add_b;
    }
    for (int node = q.b + l; node > 0; node /= 2)
    {
        tree[node].val -= add_b;
        tree[node].val += add_a;
    }
}

void Solve()
{
    for (auto q : qs)
    {
        switch(q.type)
        {
            case 1:
                Insert(q);
                break;

            case 2:
                cout << Query(q) << '\n';
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
