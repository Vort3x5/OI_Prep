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
    ll lett, num;
};

ll N, M;
Node *Tree;

void BuildTree(Node *node = Tree, ll a = 1, ll b = N)
{
    if (a == b)
    {
        node = new Node(a);
    }
    else if (a > b)
    {
        return;
    }
    else
    {
        node = new Node(0);
        BuildTree(node -> l, a, b / 2);
        BuildTree(node -> r, (b / 2) + 1, b);
    }
}

void Init()
{
    cin >> N >> M;
    BuildTree();
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
        Insert(q, a, b / 2, node -> l);
        Insert(q, (b / 2) + 1, b, node -> l);
    }
}

ll Qr(Query q, Node *node = Tree, ll a = 1, ll b = N)
{
    if (a == b)
    {
        return node->val;
    }
    else
    {
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
