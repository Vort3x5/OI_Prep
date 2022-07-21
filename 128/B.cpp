#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int t, n, m, utr, dtr, ltr, rtr;
bool res;

vector <string> field;

void Init()
{
    cin >> n >> m;
    field.resize(n);
    for (string &it : field)
        cin >> it;
    utr = ltr = 10;
    res = false;
}

void Solve()
{
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        Init();
        if (field[0][0] == 'R')
        {
            cout << "YES\n";
            continue;
        }
        for (int j = 0; j < n; ++j)
        {
            for (int l = 0; l < m; ++l)
            {
                if (field[j][l] == 'R')
                {
                    utr = min(utr, j);
                    ltr = min(ltr, l);
                }
            }
        }
        for (int j = 0; j < n; ++j)
        {
            for (int l = 0; l < m; ++l)
            {
                if (field[j][l] == 'R' && j <= utr && l <= ltr)
                    res = true;
            }
        }
        cout << (res ? "YES\n" : "NO\n");
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}
