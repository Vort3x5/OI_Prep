#include <bits/stdc++.h>
using namespace std;

struct Query
{
    int r, a, b, c;
};

struct Node
{
    int val, add, a, b;
};

int n, q, l;
vector <Node> tree;
vector <Query> qs;

void Init()
{
    cin >> n >> q;
    tree.resize((1 << int((log2(n)) + 1)) + 10);
    qs.resize(q);
    l = ((1 << int((log2(n)) + 1)) - pow(n, ceil(log2(n))));
    for (int i = 1; i <= n; ++i)
    {
        cin >> tree[i + l].val;
        for (int node = (i + l); node > 0; node /= 2)
        {
            tree[node / 2].val += tree[node].val;
        }
    }
    for (int i = 0; i < q; ++i)
    {
        cin >> qs[i].r;
        if (qs[i].r == 1)
        {
            cin >> qs[i].a >> qs[i].b >> qs[i].c;
            --qs[i].a, --qs[i].b, --qs[i].c;
        }
        else
        {
            cin >> qs[i].a;
            --qs[i].a;
        }
    }
    tree[1].a = 1; tree[1].b = n;
    for (int node = 1; node < (1 + l); ++node)
    {
        tree[node * 2].a = tree[node].a; 
        tree[node * 2].b = (tree[node].a + tree[node].b) / 2;
        
        tree[(node * 2 + 1)].a = (tree[node].a + tree[node].b) / 2; 
        tree[(node * 2) + 1].b = tree[node].b;
    }
}

int Query(int node, int i, int res = 0)
{
    if (i == (node + l))
    {
        return (res + tree[node].val);
    }
    else
    {
        return (tree[i].b < node ? Query(node, (i * 2) + 1, res + tree[i].add) 
                : Query(node, i * 2, res + tree[i].add));
    }
}

void Insert(int val, int q_a, int q_b, int i)
{}

void Solve()
{
    for (auto qr : qs)
    {
        if (qr.r == 2)
        {
            cout << Query(qr.a, 1) << '\n';
        }
        else
        {
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
