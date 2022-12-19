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

s32 n, res, m;
string s;

void Init()
{
    cin >> n >> s;
    m = n / 10;
}

void Solve()
{
    for (s32 i = 0; i < (n + 1); i += m)
    {
        s32 j = i;
        for (j; j < (i + m); ++j)
            if (s[j] != 'T')
                break;
        if (j == i + m)
            ++res;
    }
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}

