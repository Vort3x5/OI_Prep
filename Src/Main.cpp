#include <bits/stdc++.h>
#include <random>

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

u64 t, N;

void Init()
{
    cin >> N;
}

inline u64 BinMultiply(u64 x, u64 y)
{
    if (y % 2)
        return (x + BinMultiply(x, y - 1));
    return (2 * BinMultiply(x, y / 2));
}

inline u64 BinPower(u64 x, u64 y)
{
    if (y == 0)
        return 1;

    if (y % 2)
        return BinMultiply(x, BinPower(x, y - 1));
    u64 z = BinPower(x, y / 2);
    return z * z;
}

bool IsPrime(int n, int it)
{
    if (n < 4)
        return n == 2 || n == 3;

    srand(time(NULL));
    
    for (s32 i = 0; i < it; ++i)
    {
        int x = 2 + rand() % (n - 3);
        if (BinPower(x, n - 1) != 1)
            return false;
    }
    return true;
}

void Solve()
{
    cin >> t;
    for (s32 qr = 0; qr < t; ++qr)
    {
        Init();
        cout << (IsPrime(N, 10) ? "YES\n" : "NO\n");
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}

