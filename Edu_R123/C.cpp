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

int t, n, x, lfs, l;
p_i mx;

vector <Node> tree;

void Update(Node &parent, Node l, Node r)
{
    parent.psoms = max(max(l.psoms, r.psoms), l.suf + r.pref);
    parent.suf = max(r.suf, r.sum + l.suf);
    parent.pref = max(l.pref, l.sum + r.pref);
    parent.sum = l.sum + r.sum;
}

void Insert(int node, int x)
{
    while (node > 0)
    {
        Update(tree[node], tree[node * 2], tree[(node * 2) + 1]);
        node /= 2;
    }
}

void Init()
{
    cin >> n >> x;
    lfs = (1 << int((log2(n)) + 1));
    tree.resize(2 * lfs);
    l = lfs - 1;
    for (int node = 1; node <= n; ++node)
    {
        cin >> tree[node + l].psoms;
        tree[node + l].pref = tree[node + l].suf = tree[node + l].sum 
            = tree[node + l].psoms;
        mx = max(mx, { tree[node + l].psoms, node });
        Insert((node + l) / 2, tree[node].psoms);
    }
}

void Solve()
{
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        Init();
        cout << tree[1].psoms << ' ';
        tree[mx.second + l].pref = tree[mx.second + l].suf = tree[mx.second + l].sum 
            = tree[mx.second + l].psoms += x;
        Insert((mx.second + l) / 2, x);
        cout << tree[1].psoms << ' ';
        int nxt = mx.second;
        if (nxt > 1 && nxt <= n)
        {
            nxt = tree[nxt + 1 + l].psoms > tree[nxt - 1 + l].psoms ? nxt + 1 : nxt - 1;
        }
        bool right = nxt < mx.second;
        for (int node = 1; node < n; ++node)
        {
            if (right && nxt > 1)
            {
                --nxt;
                tree[nxt + l].pref = tree[nxt + l].suf = tree[nxt + l].sum 
                    = tree[nxt + l].psoms += x;
                Insert((nxt + l) / 2, x);
            }
            else if (right && nxt == 1)
            {
                right = false;
                nxt = mx.second + 1;
                tree[nxt + l].pref = tree[nxt + l].suf = tree[nxt + l].sum 
                    = tree[nxt + l].psoms += x;
                Insert((nxt + l) / 2, x);
            }
            else if (!right && nxt < n)
            {
                ++nxt;
                tree[nxt + l].pref = tree[nxt + l].suf = tree[nxt + l].sum 
                    = tree[nxt + l].psoms += x;
                Insert((nxt + l) / 2, x);
            }
            else if (!right && nxt == n)
            {
                right = true;
                nxt = mx.second - 1;
                tree[nxt + l].pref = tree[nxt + l].suf = tree[nxt + l].sum 
                    = tree[nxt + l].psoms += x;
                Insert((nxt + l) / 2, x);
            }
            cout << tree[1].psoms << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}
