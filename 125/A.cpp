#include <bits/stdc++.h>
#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int t, x, y, res;

bool dp[51][51] = { 0 };

void Init()
{
    cin >> x >> y;
    res = 0;
}

void Solve()
{
    cin >> t;
    for (int i = 0; i <= 50; ++i)
        for (int j = 0; j <= 50; ++j)
            dp[i][j] = sqrt(i * i + j * j) * sqrt(i * i + j * j) == (i * i + j * j);
    for (int q = 0; q < t; ++q)
    {
        Init();
        if (!x && !y)
            res = 0;
        else if (dp[x][y])
            res = 1;
        else
            res = 2;
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
