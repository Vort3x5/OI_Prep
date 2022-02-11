#include <bits/stdc++.h>

#define nol nums_of_lfs

using namespace std;

struct lf
{
    int indx, val;
};

bool operator<(lf l, lf r)
    { return (l.val != r.val ? l.val < r.val : l.indx < r.indx); }

struct Node
{
    set <lf> lfs;
};

struct Query
{
    int a, b, x;
};

int n, q, nums_of_lfs;

vector <int> arr;
vector <Node> tree;

void FillTree(int lvl_l = nol / 2, int node = nol / 2)
{
    tree[node].lfs = tree[node * 2].lfs;
    tree[node].lfs.insert(
            tree[(node * 2 ) + 1].lfs.begin(), 
            tree[(node * 2) + 1].lfs.end()
            );

    if (node == 1)
    {
        return;
    }
    else
    {
        FillTree(
                node - lvl_l == lvl_l - 1 ? lvl_l / 2 : lvl_l, 
                node - lvl_l == lvl_l - 1 ? lvl_l / 2 : node + 1\
                );
    }
}

void Init()
{
    cin >> n >> q;
    arr.resize(n);
    nol = (1 << int((log2(n)) + 1));
    tree.resize(2 * nol);
    for (auto &v : arr)
    {
        static int node = 0;
        cin >> v;
        tree[node + nol].lfs.insert({node, v});
        ++node;
    }
    FillTree();
}

void Insert(int node, int val)
{
    static int v = node + nol;
    auto to_del = tree[v].lfs.find({node, arr[node]});
    tree[v].lfs.erase(to_del);
    tree[v].lfs.insert({node, val});
    if (v == 1)
    {
        return;
    }
    v /= 2;
    Insert(node, val);
}

int Qr(int a, int b, int x)
{
    static set <lf> range;
    int this_a = a + nol;
    int this_b = b + nol;

    range.insert(tree[this_a].lfs.begin(), tree[this_a].lfs.end());
    range.insert(tree[this_b].lfs.begin(), tree[this_b].lfs.end());
    while (this_a != this_b)
    {
        if (!(this_a % 2))
        {
            range.insert(tree[this_a].lfs.begin(), tree[this_a].lfs.end());
        }
        if (!(this_b % 2))
        {
            range.insert(tree[this_b].lfs.begin(), tree[this_b].lfs.end());
        }
        this_a /= 2, this_b /= 2;
    }
    return upper_bound(range.begin(), range.end(), x) -> indx;
}

void Solve()
{
    for (int i = 0; i < q; ++i)
    {
        Query qr;
        cin >> qr.a >> qr.b;
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
