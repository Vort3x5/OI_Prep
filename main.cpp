#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

struct Node
{
    int psoms, sum, pref, suf;
};

struct Query
{
    int type, x, y;
};

int N, M, lfs, min_v = -10010;

vector <Node> tree;

void Update(int x, Node &parent, Node l, Node r, bool is_child = false)
{
    if (is_child)
    {
        parent.pref = parent.suf = parent.psoms = parent.sum = x;
    }
    else
    {
        parent.psoms = max(max(l.psoms, r.psoms), l.suf + r.pref);
        parent.suf = max(r.suf, r.sum + l.suf);
        parent.pref = max(l.pref, l.sum + r.pref);
        parent.sum = l.sum + r.sum;
    }
}

void Insert(int node, int x)
{
    while (node > 0)
    {
        Update(x, tree[node], tree[node * 2], tree[(node * 2) + 1]);
        node /= 2;
    }
}

void Init()
{
    cin >> N;
    lfs = (1 << int((log2(N)) + 1));
    tree.resize(2 * lfs);
    for (int node = 0; node < N; ++node)
    {
        int x;
        cin >> x;
        Update(x, tree[node + lfs], tree[node + lfs], tree[node + lfs], true);
        Insert((node + lfs) / 2, x);
    }
    cin >> M;
}

Node Qr(Query q, int a = 1, int b = N, int node = 1)
{
    static Node res;
    if (b < q.x || a > q.y)
    {
        return { min_v, 0, 0, 0 };
    }
    else if (a >= q.x && b <= q.y)
    {
        return tree[node];
    }
    else
    {
        int mid = (a + b) / 2;
        Update(0, res, Qr(q, a, mid, node * 2), Qr(q, mid + 1, b, (node * 2) + 1));
        return res;
    }
}

void Solve()
{
    for (int i = 0; i < M; ++i)
    {
        Query q;
        cin >> q.type >> q.x >> q.y;
        switch (q.type)
        {
            case 0:
                Insert(q.x, q.y + lfs - 1);
                break;
            
            case 1:
                cout << Qr(q).psoms << '\n';
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
