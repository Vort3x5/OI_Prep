#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;
typedef vector <ll> v_ll;

ll n, l, lfs, res;

v_ll arr, inc_tree, dec_tree;

void Init()
{
    scanf("%lld", &n);
    lfs = 1 << int(log2(n - 1) + 1);
    l = lfs - 1;
    arr.resize(n + 10);
    inc_tree.resize(2 * lfs);
    dec_tree.resize(2 * lfs);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &arr[i]);
}

void Insert(v_ll &tree, int v, ll x)
{
    tree[v] = x;
    while (v /= 2)
        tree[v] = max(tree[v * 2], tree[(v * 2) + 1]);
}

ll Query(v_ll &tree, int q_a, int q_b, int v = 1, int t_a = 1, int t_b = lfs)
{
    if (t_a > q_b || t_b < q_a)
        return 0;
    else if (t_a >= q_a && t_b <= q_b)
        return tree[v];
    else
    {
        int mid = (t_a + t_b) / 2;
        return max(Query(tree, q_a, q_b, v * 2, t_a, mid), Query(tree, q_a, q_b, (v * 2) + 1, mid + 1, t_b));
    }
}

void Solve()
{
    for (int node = 0; node < n; ++node)
        Insert(inc_tree, arr[node] + l, Query(inc_tree, 1, arr[node] - 1) + 1);
    for (int node = n - 1; node >= 0; --node)
        Insert(dec_tree, arr[node] + l, Query(dec_tree, 1, arr[node] - 1) + 1);

    for (int node = 1; node <= n; ++node)
        res = max(res, Query(inc_tree, 1, node) + Query(dec_tree, node + 1, lfs));
    printf("%lld\n", n - res);
}

int main()
{
    Init();
    Solve();

    return 0;
}
