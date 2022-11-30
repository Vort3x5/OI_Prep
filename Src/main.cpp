#include <bits/stdc++.h>

#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_back

using namespace std;

typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;
typedef pair <int, int> p_i;
typedef pair <s64, s64> p_ll;
typedef vector <int> v_i;
typedef vector <s64> v_ll;

struct Query
{
    s32 l, r;
    u64 a;
};

s32 n, m, lfs, l, k, res;

v_i tree, answ, arr;
v_ll goals, curr_res;
vector <Query> qs;

void Init()
{
    cin >> n >> m;
    lfs = 1 << int(log2(m) + 1);
    l = lfs - 1;
    arr.resize(m);
    tree.resize(lfs * 2);
    goals.resize(n + 1);
    curr_res.resize(n + 1);
    answ.resize(n + 1);
    
    for (s32 &i : arr)
        cin >> i;
    
    for (s32 i = 1; i <= n; ++i)
        cin >> goals[i];

    cin >> k;
    qs.resize(k);
    for (Query &qr : qs)
        cin >> qr.l >> qr.r >> qr.a;
}

void Insert(Query qr, s32 a = 1, s32 b = lfs, s32 v = 1)
{
    if (qr.l > b || qr.r < a)
        return;
    else if (a >= qr.l && b <= qr.r)
        tree[v] += qr.a;
    else
    {
        s32 mid = (a + b) / 2;
        Insert(qr, a      , mid, v * 2);
        Insert(qr, mid + 1, b  , v * 2 + 1);
    }
}

inline u64 Qr(s32 v)
{
    s32 qr = 0;
    while (v)
        qr += tree[v], v /= 2;
    return qr;
}

bool CheckSeq(s32 qr, s32 val)
{
    tree.clear();
    curr_res.clear();
    tree.resize(2 * lfs);
    curr_res.resize(n + 1);
    for (s32 i = 0; i < qr; ++i)
    {
        if (qs[i].l > qs[i].r)
            Insert((Query){qs[i].l, m, qs[i].a}), Insert((Query){1, qs[i].r, qs[i].a});
        else
            Insert(qs[i]);
    }
    u64 sum = 0;
    for (s32 v = 1; v <= m; ++v)
        if (arr[v - 1] == val)
            sum += Qr(v + l);
    return sum >= goals[val];
}

s32 BinS(s32 val)
{
    s32 a = 0, b = k;
    while (a < b)
    {
        s32 mid = (a + b) / 2;
        if (CheckSeq(mid, val))
            b = mid;
        else
            a = mid + 1;
    }
    return a;
}

void Solve()
{
// Obliczanie wynikow NIE
    for (Query &qr : qs)
    {
        if (qr.l > qr.r)
            Insert((Query){qr.l, m, qr.a}), Insert((Query){1, qr.r, qr.a});
        else
            Insert(qr);
    }
    
    curr_res.clear();
    curr_res.resize(n + 1);
    for (s32 v = 1; v <= m; ++v)
        curr_res[arr[v - 1]] += Qr(v + l);

    for (s32 i = 1; i <= n; ++i)
        if (curr_res[i] < goals[i])
            answ[i] = -1;

// Obliczanie wynikow innych od NIE
    for (s32 i = 1; i <= n; ++i)
    {
        if (answ[i])
            continue;

        answ[i] = BinS(i);
    }

// Wypisywanie
    for (s32 i = 1; i <= n; ++i)
    {
        if (answ[i] == -1)
            cout << "NIE\n";
        else
            cout << answ[i] << '\n';
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

