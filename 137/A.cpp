#include <algorithm>
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

s32 t, n;

v_i a;

void Init()
{
    cin >> n;
    a.resize(n);
    for (s32 &i : a)
        cin >> i;
}

void Solve()
{
    cin >> t;
    for (s32 qr = 0; qr < t; ++qr)
    {
        Init();
        s32 m = 10;
        m -= a.size();
        s32 res = 0;
        for (s32 i = 1; i <= m; ++i)
            res += (m - i) * 6;
        cout << res << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}

