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

v_i res;

void Init()
{
    cin >> n;
}

void PreProcess()
{
    res[1] = 1;
    for (s32 i = 2; i <= 30; ++i)
        res[i] = (i + res[i - 1] % 2) ? res[i - 1] : i;
}

void Solve()
{
    cin >> t;
    for (s32 qr = 0; qr < t; ++qr)
    {
        Init();
        cout << ((2 << (n - 1)) - 1) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}

