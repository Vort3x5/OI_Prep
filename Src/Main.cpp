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

s32 n, m, v1[1000010], v2[1000010];
u64 sum;

v32 arr;
unordered_map m1, m2;

void Init()
{
    cin >> n;
    arr.resize(n);
    for (s32 &i : arr)
    {
        cin >> i;
        sum += i;
    }
    cin >> m;
}

void Solve()
{
    for (s32 i = 0; i < ( s32(log2(sum) + 1) / 2 ); ++i)
    {
    }
    
    for (s32 i = ( s32(log2(sum) + 1) / 2 ); i < (s32(log2(sum) + 1); ++i)
    {
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}

