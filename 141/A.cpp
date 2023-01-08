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

bool cmp(s32 lhs, s32 rhs)
{ return ( lhs > rhs ); }

s32 t, n;

v32 arr;

void Init()
{
    cin >> n;
    arr.resize(n);
    for (s32 &i : arr)
        cin >> i;
}

void Solve()
{
    cin >> t;
    for (s32 qr = 0; qr < t; ++qr)
    {
        Init();
        bool same = true;
        s32 x = arr[0];
        for (s32 i = 1; i < n; ++i)
        {
            if (x != arr[i])
            {
                same = false;
                break;
            }
        }
        if (same)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        sort(arr.begin(), arr.end(), cmp);
        u64 sum = 0;
        for (s32 i = 0; i < n; ++i)
        {
            if (sum == arr[i])
                swap(arr[i], arr[n - 1]);
            sum += arr[i];
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}

