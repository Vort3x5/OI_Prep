#include <bits/stdc++.h>
using namespace std;

unsigned int t, n, k, h;

void Init()
{
    cin >> n >> k;
    h = log2(n);
}

void Solve()
{
    if (k > h )
    {
        cout << -1 << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        Init();
        Solve();
    }

    return 0;
}
