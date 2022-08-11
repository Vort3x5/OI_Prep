#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int t, n;
v_i odd, ev, h;

void Init()
{
    cin >> n;
    h = v_i(n, 0);
}

void Solve()
{
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        Init();
        int day = 1;
        for (int j = 0; j < n; ++j, ++day)
        {
            if (h[j] % 2)
            {
                if (!(day % 2))
                {
                    if (odd.empty())
                        ev.pb(day);
                    else
                        ev.pop_back(); 
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}
