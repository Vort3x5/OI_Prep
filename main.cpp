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

int N, M, lfs, l, min_v = -10010;
Node res;

vector <Node> tree;

void Update(Node &parent, Node l, Node r)
{
    parent.psoms = max(max(l.psoms, r.psoms), l.suf + r.pref);
    parent.suf = max(r.suf, r.sum + l.suf);
    parent.pref = max(l.pref, l.sum + r.pref);
    parent.sum = l.sum + r.sum;
}

void Insert(int node)
{
    while (node > 0)
    {
        Update(tree[node], tree[node * 2], tree[(node * 2) + 1]);
        node /= 2;
    }
}

void Init()
{
    cin >> N;
    lfs = (1 << int((log2(N)) + 1));
    l = lfs - 1;
    tree.resize(2 * lfs);
    for (int node = 1; node <= N; ++node)
    {
        int x;
        cin >> x;
        Node &v = tree[node + l];
        v.sum = v.pref = v.suf = v.psoms = x;
        Insert((node + l) / 2);
    }
    cin >> M;
}

Node Qr(Query q, int a = 1, int b = lfs, int node = 1)
{
    if (b < q.x || a > q.y)
    {
        return { min_v, min_v, min_v, min_v };
    }
    else if (a >= q.x && b <= q.y)
    {
        return tree[node];
    }
    else
    {
        int mid = (a + b) / 2;
        Update(res, Qr(q, a, mid, node * 2), Qr(q, mid + 1, b, (node * 2) + 1));
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
                tree[q.x + l].sum = tree[q.x + l].pref = tree[q.x + l].suf = 
                    tree[q.x + l].psoms = q.y;
                Insert((q.x + l) / 2);
                break;
            
            case 1:
                res = {min_v, 0, 0, 0};
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
