#include <bits/stdc++.h>
#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int t, n, m, sx, sy, d, dp[1010][1010];

void Init()
{
    cin >> n >> m >> sx >> sy >> d;
    memset(dp, 0, sizeof dp);
}

inline int Dist(int x1, int y1, int x2, int y2) { return (abs(x1 - x2) + abs(y1 - y2)); }

inline bool Access(int x, int y) 
    { return (x < n && y < m && x >= 0 && y >= 0 && !dp[x][y]); }

void Dfs(int x = n - 1, int y = m - 1, int c = 0)
{
    if (dp[x][y] == 10100 || (x == 0 && y == 0))
        return;
    else
    {
        dp[x][y] = c;
        if (Access(x + 1, y) && !dp[x + 1][y])
            Dfs(x + 1, y, c + 1);
        if (Access(x - 1, y) && !dp[x - 1][y])
            Dfs(x - 1, y, c + 1);
        if (Access(x, y + 1) && !dp[x][y + 1])
            Dfs(x, y + 1, c + 1);
        if (Access(x, y - 1) && !dp[x][y - 1])
            Dfs(x, y - 1, c + 1);
    }
}

void Solve()
{
    cin >> t;
    for (int qr = 0; qr < t; ++qr)
    {
        Init();
        --sx, --sy;
        for (int x = 0; x < n; ++x)
        {
            for (int y = 0; y < m; ++y)
            {
                if (Dist(x, y, sx, sy) <= d)
                    dp[x][y] = 10100;
            }
        }
        Dfs();
        if (dp[1][0] == 10100 && dp[0][1] == 10100)
            cout << -1 << '\n';
        else
            cout << min(dp[1][0], dp[0][1]) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Solve();

    return 0;
}
