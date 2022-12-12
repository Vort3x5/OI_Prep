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
    s32 l, r, diff;
};

s32 n, s, curr_s, edgel, edger;

vector <Query> qs;
bitset <1000010> prefd;

void Init()
{
    cin >> n >> s;
    qs.resize(n - 1);
    for (Query &qr : qs)
    {
        cin >> qr.l >> qr.r;
        qr.diff = abs(qr.l - qr.r);
    }
    edgel = 1, edger = n, curr_s = s;
}

void Solve()
{
    for (s32 i = 0; i < (n - 1); ++i)
        prefd[i] = qs[i].l <= qs[i].r;
    for (s32 i = 0; i < (n - 1); ++i)
    {
        if (curr_s == 1 && !prefd[i])
        {
            curr_s = edger;
            --edger;
            if (edger == s)
                --edger;
        }
        else if (curr_s == n && prefd[i])
        {
            curr_s = edgel;
            ++edgel;
            if (edgel == s)
                ++edgel;
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

