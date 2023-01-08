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

s32 t, n, arr[51][51];

vector <vector <p32>> nums;
vector <p32> pos;

void Init()
{
    cin >> n;
    nums.resize(n + 1);
    pos.resize(n * n + 1);
    memset(arr, 0, sizeof arr);
}

void Solve()
{
    cin >> t;
    for (s32 qr = 0; qr < t; ++qr)
    {
        Init();
        for (s32 i = (n * n) - 1; i > 0; --i)
        {
            s32 j = (n * n);
            while ((j - i) > 0)
                nums[i].pb({j, j - i});
        }
        arr[0][0] = nums[n - 1].second;
        arr[0][1] = nums[n - 1].first;
        pos[nums[n - 1].second] = {0, 0};
        pos[nums[n - 1].first] = {0, 1};
        s32 bs = 2;
        while (bs < (n * n))
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

