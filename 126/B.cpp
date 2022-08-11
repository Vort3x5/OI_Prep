#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int t;
ll a;

void Init()
{
    cin >> a;
}

ll NWD(int a, int b)
{
    while (a > 0)
    {
        a %= b;
        b -= a;
    }
    return b;
}

ll NWW(int a, int b)
{
    return (a * b) / NWD(a, b);
}

void Solve()
{
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        Init();
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
