#include <bits/stdc++.h>
using namespace std;

struct Qr
{
    int type, a, b;
};

struct Node
{
    unsigned long long val; 
};

int n, q, l, lfs;
vector <Node> tree;

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

void Init()
{
    cin >> n >> q;
    lfs = (1 << int((log2(n)) + 1));
    l = lfs - 1;
    tree.resize(2 * lfs);
    for (int v = 1; v <= n; ++v)
    {
        cin >> tree[v + l].val;
    }
}

unsigned long long Query(Qr qr, int a = 1, int b = lfs, int v = 1)
{
    if (b < qr.a || a > qr.b)
    {
        return 0;
    }
    else if (a >= qr.a && b <= qr.b)
    {
        return tree[v].val;
    }
    else
    {
        int mid = (a + b) / 2;
        return Query(qr, a, mid, v * 2) + Query(qr, mid + 1, b, (v * 2) + 1);
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
