#include <bits/stdc++.h>

#define pb push_back
#define pf push_front
#define M  10e9 + 7

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> p_i;
typedef vector <int> v_i;
typedef vector <ull> v_ull;

int n, t, lfs, l, p = 29;
string s1, s2;

v_ull s1_tree, s2_tree, pows;

ull CountHash(int s_end, const string &s)
{
    ull sum = 0;
    for (int i = 0; i <= s_end; ++i)
        sum += (pows[i] * s[i]) % (ull)M;
    return sum;
}

void Insert(int v, int val, v_ull &tree)
{
    while (v /= 2)
        tree[v] = (tree[v * 2] + tree[(v * 2) + 1]) % (ull)M;
}

void Init()
{
    scanf("%d", &n);
    cin >> s1 >> s2;
    lfs = 1 << (int(log2(n)) + 1);
    l = lfs - 1;
    s1_tree.resize(2 * lfs);
    s2_tree.resize(2 * lfs);
    pows.resize(n + 10);
    pows[0] = 1;
    for (int i = 1; i <= n; ++i)
        pows[i] = (pows[i - 1] * p) % (ull)M;
    for (int i = 0; i < n; ++i)
    {
        s1_tree[i + lfs] = CountHash(i, s1);
        Insert(i + lfs, s1_tree[i + lfs], s1_tree);
        s2_tree[i + lfs] = CountHash(i, s2);
        Insert(i + lfs, s2_tree[i + lfs], s2_tree);
    }
}

inline void RecountHash(int pos, int prev, int s_new, int v, v_ull &tree)
{
    tree[v] -= (pows[pos] * prev) % (ull)M;
    tree[v] += (pows[pos] * s_new) % (ull)M;
}

ull Query(int v = 1, int a = 1, int b = lfs)
{
    if (v >= n)
        return (s1_tree[v] == s2_tree[v] ? 0 : s1_tree[v] > s2_tree[v] ? 1 : 2);
    else
    {
        int mid = (a + b) / 2;
        return (s1_tree[v * 2] != s2_tree[v * 2] ? Query(v * 2, a, mid) : Query((v * 2) + 1, mid + 1, b));
    }
}

void Solve()
{
    scanf("%d", &t);
    for (int q = 0; q < t; ++q)
    {
        int i, j;
        scanf("%d%d", &i, &j);
        int s1_val = s1_tree[i + lfs];
        RecountHash(i, s1_tree[i + lfs], s2_tree[j + lfs], i + lfs, s1_tree);
        Insert(i + lfs, s1_tree[i + lfs], s1_tree);
        RecountHash(i, s2_tree[j + lfs], i == j ? s1_val : s1_tree[i + lfs], j + lfs, s2_tree);
        Insert(j + lfs, s2_tree[j + lfs], s2_tree);
        printf("%lld\n", Query());
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
