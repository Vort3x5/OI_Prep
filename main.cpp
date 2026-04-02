#include <bits/stdc++.h>

#define nol nums_of_lfs
#define ll long long

using namespace std;

struct lf
{
    ll indx, val;
};

auto cmp = [](lf l, lf r)
    { return (l.val != r.val ? l.val < r.val : l.indx < r.indx); };

struct Node
{
    set <lf, decltype(cmp)> lfs{cmp};
};

struct Query
{
    ll a, b, x;
};

int n, q, nums_of_lfs;

vector <ll> arr;
vector <Node> tree;

void Insert(int node, int val)
{
    int v = node + nol;
    while (v > 0)
    {
        auto to_del = tree[v].lfs.find({node, arr[node]});
        tree[v].lfs.erase(to_del);
        tree[v].lfs.insert({node, val});
        v /= 2;
    }
}

void Init()
{
    cin >> n;
    arr.resize(n);
    nol = (1 << int((log2(n)) + 1));
    tree.resize(2 * nol);
    for (auto &v : arr)
    {
        static int node = 0;
        cin >> v;
        Insert(node, v);
        ++node;
    }
    cin >> q;
}

int Qr(Query qr, int a = 1, int b = nol, int v = 1)
{
    if (a > qr.b || b < qr.a)
    {
        return 0;
    }
    else if (a >= qr.a && b <= qr.b)
    {
        return 
            (arr.size() - upper_bound(tree[v].lfs.begin(), tree[v].lfs.end(), qr.x) -> indx);
    }
    else
    {
        int mid = (a + b) / 2;
        return max(Qr(qr, a, mid, v * 2), Qr(qr, mid + 1, b, (v * 2) + 1));
    }
}

void Solve()
{
    for (int i = 0; i < q; ++i)
    {
        Query qr;
        cin >> qr.a >> qr.b >> qr.x;
        cout << Qr(qr) << '\n';
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
