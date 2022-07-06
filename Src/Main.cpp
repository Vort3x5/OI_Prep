#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

#define stc sub_tree_count

int s, m, q;
long long k;
unsigned long long dp[210][210][210];

void Init()
{
    scanf("%d%d%d", &s, &m, &q);
}

void Solve()
{
    int d[201];
    d[0] = 1;
    dp[0][0][0] = 1;
    for (int i = 1; i <= 200; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            for (int z = 0; z <= (s - j); ++z)
            {
                for (int x = 0; x < m; ++x)
                {
                    dp[i][z + j][(x + d[i - 1] * j) % m] += dp[i - 1][z][x];
                    if (dp[i][z + j][(x + d[i - 1] * j) % m] > 1000000000000000000ll)
                        dp[i][z + j][(x + d[i - 1] * j) % m] = 1000000000000000000ll;
                }
            }
        }
        d[i] = d[i - 1] * 10;
        d[i] %= m;
    }
    for (int qr = 0; qr < q; ++qr)
    {
        scanf("%lld", &k);
        if (dp[200][s][0] < k)
        {
            printf("NIE\n");
            return;
        }
        int sm = s, md = 0;
        string res;
        for (int i = 200; i > 0; --i)
        {
            int j = 0;
            for (; j < 10; ++j)
            {
                if (dp[i - 1][sm - j][(md + (m - ((j * d[i - 1]) % m))) % m] < k)
                    k -= dp[i - 1][sm - j][(md + (m - ((j * d[i - 1]) % m))) % m];
                else
                {
                    md = (md + (m - ((j * d[i - 1]) % m))) % m;
                    sm -= j;
                    if (!res.empty() || j != 0)
                        res += to_string(j);
                    break;
                }
            }
        }
        printf("%s\n", res.c_str());
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
