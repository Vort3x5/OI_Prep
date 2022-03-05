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
    
    Node(ll a)
        : val(a), l(nullptr), r(nullptr) {}
};

struct Query
{
    char lett;
    ll num;
};

ll N, M;
Node *Tree;

void Init()
{
    cin >> N >> M;
}

void Insert(Query q, int a = 1, int b = N, Node *node = Tree)
{
    if (b < q.num || a > N)
    {
        return;
    }
    else if (a >= q.num || b <= N)
    {
        ++(node -> val);
    }
    else
    {
        if ((node -> l) == nullptr)
            node -> l = new Node();
        if ((node -> r) == nullptr)
            node -> r = new Node();
        
        Insert(q, a, b / 2, node -> l);
        Insert(q, (b / 2) + 1, b, node -> l);
    }
}

ll Qr(Query q, Node *node = Tree, ll a = 1, ll b = N)
{
    if (a == b)
    {
        return node -> val;
    }
    else
    {
        int mid = (a + b) / 2;
        return node->val + Qr(
                q, 
                (b / 2) <= q.num ? node -> l : node -> r, 
                (b / 2) <= q.num ? a : (b / 2) + 1,
                (b / 2) <= q.num ? b / 2 : b
                );
    }
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
