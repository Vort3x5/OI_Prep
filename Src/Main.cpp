#include <bits/stdc++.h>

#define pb push_back
#define pf push_front
#define M  1696969

using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef long long s64;
typedef pair <int, int> p_i;
typedef vector <int> v_i;
typedef vector <u64> v_u64;

int n, t, lfs, l, p = 29;
string s1, s2;

v_u64 pows, s1_tree, s2_tree;

inline u64 CountHash(int i, const string &s)
{
    return (pows[i] * s[i]) % (u64)M;
}
void Insert(int v, s64 val, v_u64 &tree)
{
    tree[v] += val;
    while (v /= 2)
        tree[v] = tree[v * 2] + tree[(v * 2) + 1] % (u64)M;
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
        pows[i] = (pows[i - 1] * p) % (u64)M;
    for (int i = 0; i < n; ++i)
    {
        Insert(i + lfs, CountHash(i, s1), s1_tree);
        Insert(i + lfs, CountHash(i, s2), s2_tree);
    }
}

inline s64 RecountHash(int pos, int prev, int s_new)
{
    return ((s_new - prev) * pows[pos]);
}

u64 Query(int v = 1, int a = 1, int b = lfs)
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
        swap(s1[i], s2[j]);
        Insert(i + lfs, RecountHash(i, s2[j], s1[i]), s1_tree);
        Insert(j + lfs, RecountHash(j, s1[i], s2[j]), s2_tree);
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
