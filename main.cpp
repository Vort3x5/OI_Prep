#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

struct Node
{
    int val;
};

struct Query
{
    int type, x, y;
};

int N, M, lfs;

vector <Node> tree;

void Init()
{
    cin >> N;
    lfs = (1 << int((log2(N)) + 1));
    tree.resize(2 * lfs);
    for (int node = 0; node < N; ++node)
    {
        cin >> tree[lfs + node].val;
        for (int v = lfs + node; v >= 1; v /= 2)
        {
            tree[v].val += tree[lfs + node].val;
        }
    }
    cin >> M;
}

void Insert(int node, int prev_x, int x)
{
    tree[node].val += (x - prev_x);
    if (node == 1)
    {
        return;
    }
    Insert(node /= 2, prev_x, x);
}

int Qr()
{
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
                Insert(q.x, tree[lfs + q.x].val, q.y);
                break;
            
            case 1:
                // cout << Qr() << '\n';
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
