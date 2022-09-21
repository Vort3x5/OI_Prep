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

s32 T, N;

pair <bool, s32> sieve[20000010];
int sigma[20000010];
bitset <20000010> res;

inline void Init()
{
    cin >> N;
}

void EraSieve()
{
    for (int i = 2; i <= 20000000; ++i)
    {
        if (sieve[i].first)
            continue;

        for (int j = (i * 2); j <= 20000000; j += i)
            sieve[j].first = true, sieve[j].second = i;
    }
}

void Sigma()
{
    sigma[1] = 1;
    for (int i = 2; i <= 20000000; ++i)
    {
        if (!sieve[i].first)
        {
            sigma[i] = 2;
            continue;
        }
        int x = i;
        while (!(x % sieve[i].second))
        {
            ++sigma[i];
            x /= sieve[i].second;
        }
        ++sigma[i];
        sigma[i] *= sigma[x];
    }
}

void CountRes()
{
    res[0] = false;
    res[1] = true;
    int last_lost = 0;
    for (int i = 2; i <= 20000000; ++i)
        res[i] = i - sigma[i] <= last_lost, last_lost += res[i] * i - last_lost * res[i];
}

inline void PreProcess()
{
    EraSieve();
    Sigma();
    CountRes();
}

void Solve()
{
    cin >> T;
    PreProcess();
    for (int qr = 0; qr < T; ++qr)
    {
        Init();
        cout << (res[N] ? "Ada\n" : "Vinit\n");
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}

