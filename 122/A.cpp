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

int t, n;

void Init()
{
    cin >> n;
}

void Solve()
{
    cin >> t;
    for (int qr = 0; qr < t; ++qr)
    {
        Init();
        if (!(n % 7))
        {
            cout << n << '\n';
            continue;
        }
        n -= (n % 10);
        while (n % 7)
            ++n;
        cout << n << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}

