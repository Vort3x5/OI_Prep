#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int t, zs, res;
int dp[200010][200010][2];

string s;

void Init()
{
    cin >> s;
    memset(dp, 0, sizeof(dp));
    zs = 0;
    res = s.size() + 100;
}

void Solve()
{
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        Init();
        for (int l = 0; l < s.size(); ++l)
            zs += !int(s[l] - '0');
        dp[0][0][0] = zs;
        for (int l = 1; l <= s.size(); ++l)
        {
            dp[l][0][0] = s[l] == '0' ? dp[l - 1][0][0] - 1 : dp[l - 1][0][0];
            dp[l][0][1] = s[l] == '1' ? dp[l - 1][0][1] + 1 : dp[l - 1][0][1];
        }
        for (int j = 1; j <= s.size(); ++j)
        {
            dp[j][s.size() + 1][0] = dp[j][0][0];
            dp[j][s.size() + 1][1] = dp[j][0][1];
            for (int l = s.size(); l > j; --l)
            {
                dp[j][l][0] = s[l] == '0' ? dp[j][l + 1][0] - 1 : dp[j][l + 1][0];
                dp[j][l][1] = s[l] == '1' ? dp[j][l + 1][1] + 1 : dp[j][l + 1][1];
            }
        }
        for (int j = 0; j <= s.size(); ++j)
        {
            for (int z = 0; z <= s.size(); ++z)
                res = min(res, max(dp[j][z][0], dp[j][z][1]));
        }
        cout << res << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}
