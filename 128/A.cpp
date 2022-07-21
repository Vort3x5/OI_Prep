#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int t, l1, l2, r1, r2;

void Init()
{
    cin >> l1 >> r1 >> l2 >> r2;
}

void Solve()
{
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        Init();
        int res;
        if (l1 == l2)
            res = l1;
        else if (l1 > l2 && r2 >= l1)
            res = l1;
        else if (l2 > l1 && r1 >= l2)
            res = l2;
        else
            res = l1 + l2;
        cout << res << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}
