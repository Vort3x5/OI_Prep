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

s32 n, res = 100000, curr_res;

v_ll arr;

void Init()
{
    cin >> n;
    arr.resize(n);
    for (s64 &i : arr)
        cin >> i;
}

void Solve()
{
    if (arr[0] == arr[1])
    {
        arr[1] = arr[0] - 1;
        ++curr_res;
    }
    s64 prev = arr[1];
    for (s32 i = 2; i < n; ++i)
    {
        if (arr[i - 2] < arr[i - 1] && arr[i] >= arr[i - 1])
        {
            arr[i] = arr[i - 1] - 1;
            ++curr_res;
        }
        else if (arr[i - 2] < arr[i - 1] && arr[i] >= arr[i - 1])
        {
            arr[i] = arr[i - 1] + 1;
            ++curr_res;
        }
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

