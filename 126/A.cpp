#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int t, n;

v_i a, b;

void Init()
{
    cin >> n;
    a = v_i(n, 0);
    b = v_i(n, 0);
    for (int &i : a)
        cin >> i;
    for (int &i : b)
        cin >> i;
}

void Solve()
{
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        Init();
        ll res_a = 0, res_b = 0;
        for (int j = 1; j < n; ++j)
        {
            if (abs(a[j - 1] - b[j]) + abs(b[j - 1] - a[j]) < abs(a[j - 1] - a[j]) + abs(b[j - 1] - b[j]) )
                swap(a[j] ,b[j]);
        }
        if (abs(b[0] - a[1]) + abs(a[0] - b[1]) < abs(a[0] - a[1]) + abs(b[0] - b[1]))
            swap(a[0], b[0]);
        for (int j = 0; j < (n - 1); ++j)
        {
            res_a += abs(a[j] - a[j + 1]);
            res_b += abs(b[j] - b[j + 1]);
        }
        cout << res_a + res_b << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}
