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
typedef vector <int> v32;
typedef vector <s64> v64;

s32 n, m;
u64 dp[2000000000];

v32 arr;

void Init()
{
    cin >> n;
    arr.resize(n);
    for (s32 &i : arr)
        cin >> i;
    cin >> m;
}

void Solve()
{
    for (s32 i = 1; i <= m; ++i)
    {
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

