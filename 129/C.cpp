#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int t, n;

v_i a, b, asc, bsc;
vector <bool> used;

unordered_map <set <int>, bool> qs({0}, false);

void Init()
{
    scanf("%d", &n);
    a.resize(n);
    b.resize(n);
    used = vector <bool> (n, false);
    asc = v_i(n, 0);
    bsc = v_i(n, 0);
    for (auto &it : a)
        scanf("%d", &it);
    for (auto &it : b)
        scanf("%d", &it);
}

void Solve()
{
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
    {
        Init();
        for (int j = 0; j < n; ++j)
        {
            int z;
            for (z = a[j] - 1; used[z]; ++z);
            asc[j] = z;
            used[z] = true;
        }
        used = vector <bool> (n, false);
        for (int j = 0; j < n; ++j)
        {
            int z;
            for (z = b[j] - 1; used[z]; ++z);
            bsc[j] = z;
            used[z] = true;
        }
        for (int j = 0; j < n; ++j)
        {
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
