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
typedef pair <int, int> p32;
typedef pair <s64, s64> p64;
typedef vector <s32> v32;
typedef vector <s64> v64;

bool cmp(p32 lhs, p32 rhs)
{ return ( lhs.first < rhs.first ); }

s32 t, n, m, sum, res, pscore;

v32 arr, score, dp;
vector <p32> pls;
bitset <500010> vis;

void Init()
{
    cin >> n >> m;
    arr.resize(n);
    pls.resize(n);
    score.resize(n);
    dp.resize(m + 1);
    for (s32 &i : arr)
    {
        cin >> i;
        sum += i;
    }
    for (s32 i = 0; i < n; ++i)
    {
        pls[i].first = arr[i];
        pls[i].second = i;
    }
    sort(pls.begin(), pls.end(), cmp);
}

s32 Knapsack()
{
    for (s32 i = 0; i < n; ++i)
    {
        for (s32 w = m; w >= 0; --w)
            if (arr[i] <= w)
                dp[w] = max(dp[w], dp[w - arr[i]] + 1);
    }
    return dp[m];
}

void Solve()
{
    cin >> t;
    for (s32 qr = 0; qr < t; ++qr)
    {
        Init();
        if (sum <= m)
        {
            cout << 1 << '\n';
            continue;
        }
        for (s32 i = 0; i < n; ++i)
            score[pls[i].second] = i;
        res = Knapsack();
        pscore = 1;
        for (s32 i = 0; i < n; ++i)
        {
            if (score[i] > res && !vis[score[i]])
            {
                ++pscore;
                vis[score[i]] = true;
            }
        }
        cout << pscore << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}

