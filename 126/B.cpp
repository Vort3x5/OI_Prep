#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int t, a, dp[16], res;

void Init()
{
    cin >> a;
    memset(dp, 0, sizeof dp);
}

void Solve()
{
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        Init();
        for (int j = 0; j < 16; ++j)
        {
            int shift = a + j;
            while (shift % 32768)
                ++dp[j], shift <<= 1;
        }
        res = 16;
        for (int j = 0; j < 16; ++j)
            res = min(res, dp[j] + j);
        cout << res << ' ';
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}
