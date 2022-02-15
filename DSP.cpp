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

void Init()
{
    cin >> n >> q;
    lfs = (1 << int((log2(n)) + 1));
    l = lfs - 1;
    tree.resize(2 * lfs);
    for (int v = 1; v <= n; ++v)
    {
        unsigned long long x;
        cin >> x;
        for (int node = v + l; node > 0; node /= 2)
            tree[node].val += x;
    }
}

void Insert(Qr qr)
{
    long long add_b = qr.b;
    long long add_a = tree[qr.a + l].val;
    for (int node = qr.a + l; node > 0; node /= 2)
    {
        tree[node].val -= add_a;
        tree[node].val += add_b;
    }
}

unsigned long long Query(Qr qr)
{
    long long a = qr.a + l;
    long long b = qr.b + l;
    long long sum = a != b * tree[b].val + tree[a].val;
    while(a / 2 != b / 2)
    {
        if (!(a % 2))
        {
            sum += tree[a + 1].val;
        }
        if (b % 2)
        {
            sum += tree[b - 1].val;
        }
        a /= 2, b /= 2;
    }
    return sum;
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
