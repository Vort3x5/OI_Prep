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

s32 t, n, m;
p_i res[9][9];

void Init()
{
    cin >> n >> m;
}

void PreProcess()
{
    for (int i = 1; i < 9; ++i)
    {
        for (int j = 1; j < 9; ++j)
        {
            for (int x = 0; x < i; ++x)
            {
                for (int y = 0; y < j; ++y)
                {
                    if (x - 2 > 0 && y + 1 <= j)
                        res[i][j] = {x - 2, y + 1};
                    else if (x - 2 > 0 && y - 1 > 0)
                        res[i][j] = {x - 2, y - 1};
                    else if (x + 2 <= i && y + 1 <= j)
                        res[i][j] = {x + 2, y + 1};
                    else if (x + 2 <= i && y - 1 > 0)
                        res[i][j] = {x + 2, y - 1};
                    else if (x - 1 > 0 && y + 2 <= j)
                        res[i][j] = {x - 1, y + 2};
                    else if (x - 1 > 0 && y - 2 > 0)
                        res[i][j] = {x - 1, y - 2};
                    else if (x + 1 <= i && y + 2 <= j)
                        res[i][j] = {x + 1, y + 2};
                    else if (x + 1 <= i && y - 2 > 0)
                        res[i][j] = {x + 1, y - 2};
                    else if (!res[i][j].first && !res[i][j].second)
                        res[i][j] = {x, y};
                }
            }
        }
    }
}

void Solve()
{
    cin >> t;
    PreProcess();
    for (s32 qr = 0; qr < t; ++qr)
    {
        Init();
        cout << res[n][m].first << ' ' << res[n][m].second << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}

