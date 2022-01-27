#include <bits/stdc++.h>
using namespace std;

int t, n, mx, i_t;

vector <int> a, b;
int occs[100][10001];

void Init()
{
    mx = 0;
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (auto &j : a)
    {
        cin >> j;
        mx = max(mx, j);
        ++occs[i_t][j];
    }

    for (auto &j : b)
    {
        cin >> j;
        mx = max(mx, j);
        ++occs[i_t][j];
    }
}

void Solve()
{
    int first, second = mx;
    for (int i = 1; n;)
    {
        if (occs[i_t][i] && occs[i_t][i] < n)
        {
            n -= occs[i_t][i];
        }
        else if (occs[i_t][i] >= n)
        {
            first = i;
            n = 0;
        }
        ++i;
    }
    cout << first * second << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    for (int i = 0; i < t; ++i, ++i_t)
    {
        Init();
        Solve();
    }

    return 0;
}
