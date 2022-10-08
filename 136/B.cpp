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
v_i arr, res;

void Init()
{
    cin >> n;
    arr.resize(n);
    res = v_i(n, 0);
    for (s32 &i : arr)
        cin >> i;
    res[0] = arr[0];
}

s32 CountRes(s32 i = 1, s32 x = arr[0])
{
    if (i == arr.size())
        return 1;
    if (x != arr[i - 1])
        return 0;
    
    if (CountRes(i + 1, abs(arr[i] + x)) ^ CountRes(i + 1, abs(x - arr[i])))
    {
        if (CountRes(i + 1, abs(arr[i] + x)))
            res[i] = abs(arr[i] + x);
        else if (CountRes(i + 1, abs(x - arr[i])))
            res[i] = abs(x - arr[i]);
        return 1;
    }
    return 0;
}

void Solve()
{
    cin >> t;
    for (s32 qr = 0; qr < t; ++qr)
    {
        Init();
        if (!CountRes())
        {
            cout << -1 << '\n';
            continue;
        }
        for (s32 &i : res)
            cout << i << ' ';
        cout << '\n';
    }
}

s32 main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}

