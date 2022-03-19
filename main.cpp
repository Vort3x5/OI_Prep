#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

struct Node
{
    ll val;
    Node *l, *r;
    
    Node(ll v = 0)
        : val(v), l(nullptr), r(nullptr) {}
};

struct Query
{
    char lett;
    ll num;
};

ll N, M;
Node *Tree = new Node();

void Init()
{
    cin >> N >> M;
}

inline bool IsInRange(int a, int b, int v) 
    { return (a <= v && v <= b); }

void Insert(Query q, int a = 1, int b = N, Node *node = Tree)
{
    if (b < q.num)
        return;

    if (a == b)
        ++(node -> val);
    else if (a >= q.num)
        ++(node -> val);
    else
    {
        int mid = (a + b) / 2;

        if (!(node -> l))
            (node -> l) = new Node(node -> val);
        Insert(q, a, mid, node -> l);

        if (!(node -> r))
            (node -> r) = new Node(node -> val);
        Insert(q, mid + 1, b, node -> r);
    }
}

ll Qr(Query q, Node *node = Tree, ll a = 1, ll b = N)
{
    if (b < q.num)
        return 0;

    if (a == b)
        return a + (node -> val);
    
    int mid = (a + b) / 2;
    if (IsInRange(a, mid, q.num))
    {
        if (!(node -> l))
            (node -> l) = new Node(node -> val);
        return (node -> val) + Qr(q, node -> l, a, mid);
    }
    else if (IsInRange(mid + 1, b, q.num))
    {
        if (!(node -> r))
            (node -> r) = new Node(node -> val);
        return (node -> val) + Qr(q, node -> r, mid + 1, b);
    }
    return 0;
}

void Solve()
{
    for (ll i = 0; i < M; ++i)
    {
        Query q;
        cin >> q.lett >> q.num;
        switch (q.lett)
        {
            case 'L':
                cout << Qr(q) << '\n';
                break;

            case 'D':
                Insert(q);
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
