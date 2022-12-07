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

s32 n, s, res = 1000010;

v_i arr, answ, indx;

void Init()
{
    cin >> n >> s;
    arr.resize(n);
    answ.resize(n);
    indx.resize(n);
    for (s32 i = 0; i < n; ++i)
    {
        cin >> arr[i];
        ++arr[i];
        indx[arr[i]] = i;
    }
}

void Sub1()
{
    s32 curr_s = s, sum = 0;
    sort(arr.begin(), arr.end());
    do
    {
        for (s32 i = 0; i < n; ++i)
        {
            if (curr_s == 1)
                ++sum, curr_s = s;
            else if (arr[i] > curr_s)
                curr_s = s - (arr[i] - curr_s);
        }
        if (sum < res)
        {
            for (s32 i = 0; i < n; ++i)
                answ[i] = indx[arr[i]] + 1;
            res = sum;
        }
    } 
    while (next_permutation(arr.begin(), arr.end()));
}

void Sub2()
{
}

void Sub3()
{
}

void Solve()
{
    if (n <= 10)
        Sub1();
    else if (n <= 1000)
        Sub3();
    else
        Sub2();
    cout << res << '\n';
    for (s32 i = 0; i < n; ++i)
        cout << answ[i] << ' ';
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

