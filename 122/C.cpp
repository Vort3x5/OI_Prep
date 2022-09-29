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

u64 t, hc, dc, hm, dm, k, w, a;

void Init()
{
    cin >> hc >> dc >> hm >> dm >> k >> w >> a;
}

void Solve()
{
    cin >> t;
    for (s32 qr = 0; qr < t; ++qr)
    {
        Init();
        if (ceil((hc + (k * a)) / dm) < ceil((hm + (k * a)) / dc))
        {
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}

