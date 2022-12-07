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

s32 n, s, res;

v_i arr, answ, cnt;

bool cmp(p_i lhs, p_i rhs)
    { return lhs.first >= rhs.first; }

priority_queue <p_i, vector <p_i>, decltype(&cmp)> ord;

void Init()
{
    cin >> n >> s;
    arr.resize(n);
    cnt.resize(s + 10);
    for (s32 &i : arr)
    {
        cin >> i;
        i = (i + 1) % s;
        ++cnt[i + 1];
    }
}

void Solve()
{
    s32 w = 0;
    cout << res << '\n';
    while (!ord.empty())
    {
    }
    for (s32 &i : answ)
        cout << i << ' ';
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
