#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define INF 10e9

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int n, res;

v_i arr;
vector <ll> dp;

void Init()
{
    cin >> n;
    arr.resize(n);
    dp = vector <ll> (n + 1, INF);
    dp[0] = -INF;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
}

void Solve()
{
    for (int i = 0; i < n; ++i)
    {
        int j = upper_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
        if (dp[j - 1] < arr[i] && arr[i] < dp[j])
            dp[j] = arr[i];
    }
    ll res = 0;
    for (int i = 0; i <= n; ++i)
        if (dp[i] < INF)
            res = i;
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Init();
    Solve();

    return 0;
}
