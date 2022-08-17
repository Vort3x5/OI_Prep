#include <bits/stdc++.h>
#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

ll t, n, b, x, y;

void Init()
{
    cin >> n >> b >> x >> y;
}

void Solve()
{
    cin >> t;
    for (int q = 0; q < t; ++q)
    {
        Init();
        ll prev = 0, sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if (prev + x <= b)
                prev += x;
            else
                prev -= y;
            sum += prev;
        }
        cout << sum << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Solve();

    return 0;
}
