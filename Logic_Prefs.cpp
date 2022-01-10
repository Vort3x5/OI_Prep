#include <bits/stdc++.h>
using namespace std;

int n;

vector <int> arr;
vector <int> prefs;

void Init()
{
    cin >> n;
    arr.resize(n);
    prefs.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i - 1];
        prefs[i] = prefs[i - 1] ^ arr[i - 1];
    }
}

void Solve()
{
    int res = 0;
    for (int i = 1; i <= n; ++i)
        for (int k = i + 1; k <= n; ++k)
            res = !(prefs[k] ^ prefs[i - 1]) ? res += (k - i) : res;

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
