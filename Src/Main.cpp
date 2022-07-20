#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int n, l, m, p1, p2, w1, w2;

vector <string> arr;

void Init()
{
    cin >> n >> l >> m;
    arr.resize(n);
    for (string &it : arr)
        cin >> it;
    for (int q = 0; q < m; ++q)
        cin >> p1 >> p2 >> w1 >> w2;
}

void Solve()
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}
