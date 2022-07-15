#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int t, n, m;

v_i a, b;

void Init()
{
    scanf("%d", &n);
    a.resize(n);
    for (auto &it : a)
        scanf("%d", &it);
    scanf("%d", &m);
    b.resize(m);
    for (auto &it : b)
        scanf("%d", &it);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

void Solve()
{
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        Init();
        int ff = 0, fs = 0, z = 0, j = 0;
        string res;
        for (j = 0; j < (n > m ? n : m); ++j)
        {
            if (j && a[j] <= b[j - 1])
                ff = 2;
            else if (b[j] <= a[j])
                ff = 1;
        }
        if (ff == 1)
            res = "ALICE";
        else if (ff == 2)
            res = "BOB";
        else if (n > m)
        {
            if (a[j + 1] <= b[j])
                res = "BOB";
            else
                res = "ALICE";
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
