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

s32 n, s, dp[501][501][501], res = 1000010;

v_i answ, arr;
vector <p_i> cost, cls;
bitset <3001> lr;
vector <vector <bool>> insts; 

void Init()
{
    cin >> n >> s;
    cost.resize(n - 1);
    arr.resize(n - 1);
    answ.resize(n - 1);
    for (p_i &i : cost)
        cin >> i.first >> i.second;
    s32 j = 0;
    for (s32 i = 1; i <= n; ++i)
    {
        if (i == s)
            continue;
        else
        {
            arr[j] = i;
            ++j;
        }
    }
}

void PreProcess()
{
    for (s32 i = 1; i < n; ++i)
    {
        for (s32 v = 1; v <= n; ++v)
        {
            if (v == s)
                continue;
            
            for (s32 u = 1; u <= 500; ++u)
            {
                if (v == u)
                    continue;
                else if (u > v)
                    dp[i][v][u] = cost[i].second;
                else
                    dp[i][v][u] = cost[i].first;
            }
        }
    }
    for (s32 i = 0; i < (n - 1); ++i)
        lr[0] = cost[i].first < cost[i].second;
    for (s32 i = 0; i < (n - 1); ++i)
    {
        for (s32 j = i + 1; j < (n - 1); ++j)
        {
            if (!cls[i].first && !lr[j])
                cls[i].first = j;
            else if (!cls[i].second && lr[j])
                cls[i].second = j;
        }
    }
}

void Solve()
{
    do
    {
        s32 i = 0, sum = 0, curr_s = s;
        for (s32 &j : arr)
        {
            if (j < curr_s)
                sum += cost[i].first;
            else
                sum += cost[i].second;
            curr_s = j;
            ++i;
        }
        if (sum < res)
        {
            for (s32 j = 0; j < (n - 1); ++j)
                answ[j] = arr[j];
            res = sum;
        }
    }
    while (next_permutation(arr.begin(), arr.end()));
    cout << res << '\n' << s << ' ';
    for (s32 &j : answ)
        cout << j << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}

