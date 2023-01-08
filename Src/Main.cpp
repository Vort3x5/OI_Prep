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

u64 n, m, v1[2000010], v2[2000010], arr1[20], arr2[20], k1 = 0, k2 = 0;

vector <bool> mask;
unordered_map <u64, s32> m1, m2;

void Init()
{
    cin >> n;
    for (s32 i = 0; i < n && i < 20; ++i)
        cin >> arr1[i];
    for (s32 i = 20; i < n && i < 40; ++i)
        cin >> arr2[i];
    cin >> m;
}

void Solve()
{
    for (u64 i = 0; i < (1 << 20); ++i)
    {
        u64 j = i;
        while (j)
        {
            mask.pb(j % 2);
            j /= 2;
        }
        for (u64 bit = 0; bit < mask.size(); ++bit)
            v1[i] += (mask[bit] * arr1[bit]);
        mask.clear();
        m1[v1[i]] = i;
    }
    for (u64 i = 0; i < (1 << 20); ++i)
    {
        u64 j = i;
        while (j)
        {
            mask.pb(j % 2);
            j /= 2;
        }
        for (u64 bit = 0; bit < mask.size(); ++bit)
            v2[i] += (mask[bit] * arr2[bit]);
        mask.clear();
        m2[v2[i]] = i;
    }

    for (auto const & [key, val] : m1)
    {
        if (key == m)
        {
            k1 = key;
            break;
        }
        else if (m2.count(m - key))
        {
            k1 = key;
            k2 = m - key;
            break;
        }
    }

    if (!k2)
    {
        s32 l = (s32)log2(m1[k1]) + 1;
        for (s32 i = 0; i < (n - l); ++i)
            cout << 0;
    }
    else
    {
        s32 l = ((s32)log2(m1[k1]) + 1) + ((s32)log2(m2[k2]) + 1);
        for (s32 i = 0; i < (n - l); ++i)
            cout << 0;
        u64 res = m2[k2];
        while (res)
        {
            cout << res % 2;
            res /= 2;
        }
    }
    u64 res = m1[k1];
    while (res)
    {
        cout << res % 2;
        res /= 2;
    }
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
