#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

struct Node
{
    ll sum, lazy;
};

struct Query
{
    ll type, p, q, v;
};

ll T, N, C, lfs, l;

vector <Node> tree;

void Init()
{
    cin >> N >> C;
    lfs = (1 << ll((log2(N)) + 1));
    tree.clear();
    tree.resize(2 * lfs);
    l = lfs - 1;
}

void GoDown(ll &mid, ll a, ll b, ll v)
{
    mid = (a + b) / 2;
    ll abl = mid - a + 1;
    ll abr = b - mid;
    tree[v * 2].lazy += tree[v].lazy;
    tree[(v * 2) + 1].lazy += tree[v].lazy;
    tree[v * 2].sum += tree[v].lazy * abl;
    tree[(v * 2) + 1].sum += tree[v].lazy * abr;
    tree[v].lazy = 0;
}

void Insert(Query q, ll a = 1, ll b = lfs, ll v = 1)
{
    if (a > q.q || b < q.p)
    {
        return;
    }
    else if (a >= q.p && b <= q.q)
    {
        tree[v].lazy += q.v;
        tree[v].sum += (b - a + 1) * q.v;
    }
    else
    {
        ll mid;
        GoDown(mid, a, b, v);
        Insert(q, a, mid, v * 2);
        Insert(q, mid + 1, b, (v * 2) + 1);
        tree[v].sum = tree[v * 2].sum + tree[(v * 2) + 1].sum;
    }
}

ll Qr(Query q, ll a = 1, ll b = lfs, ll v = 1)
{
    if (a > q.q || b < q.p)
    {
        return 0;
    }
    else if (a >= q.p && b <= q.q)
    {
        return tree[v].sum;
    }
    else
    {
        ll mid, abl, abr;
        GoDown(mid, a, b, v);
        return Qr(q, a, mid, v * 2) +
        Qr(q, mid + 1, b, (v * 2) + 1);
    }
}

void Solve()
{
    cin >> T;
    for (ll i = 0; i < T; ++i)
    {
        Init();
        for (ll j = 0; j < C; ++j)
        {
            Query q;
            cin >> q.type >> q.p >> q.q;
            switch(q.type)
            {
                case 0:
                    cin >> q.v;
                    Insert(q);
                    break;
                
                case 1:
                    cout << Qr(q) << '\n';
                    break;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}
