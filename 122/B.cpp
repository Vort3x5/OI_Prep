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

int t;
string s;

int cnt[2];

void Init()
{
    cin >> s;
    cnt[0] = 0;
    cnt[1] = 0;
}

void Solve()
{
    cin >> t;
    for (int qr = 0; qr < t; ++qr)
    {
        Init();
        for (int i = 0; i < s.size(); ++i)
            ++cnt[s[i] - '0'];
        if (cnt[0] != cnt[1])
            cout << min(cnt[0], cnt[1]) << '\n';
        else
            cout << 0 << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}

