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

inline u64 R(u64 a, u64 b)
    { return a + rand() % (b - a + 1); }

int main(s32 argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(atoi(argv[1]));
    s32 n = R(2, 12), q = R(1, 6);
    cout << "1\n" << n << '\n';
    s32 src = 1, dest = 2, w = 0;
    cout << src << ' ' << dest << ' ' << R(1, 8) << '\n';
    for (s32 i = 3; i <= n; ++i)
    {
        src = R(1, i - 1);
        w = R(1, 8);
        cout << src << ' ' << i << ' ' << w << '\n';
        src = 0;
    }
    for (s32 i = 0; i < q; ++i)
    {
        bool res = R(0, 1);
        if (!res)
        {
            cout << "CHANGE ";
            s32 v = R(1, n - 1), w = R(1, 6);
            cout << v << ' ' << w << '\n';
        }
        else
        {
            cout << "QUERY ";
            s32 a = R(1, n - 1), b;
            b = R(a + 1, n);
            cout << a << ' ' << b << '\n';
        }
    }
    cout << "DONE\n";

    return 0;
}

