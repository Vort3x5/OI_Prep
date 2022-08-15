#include <bits/stdc++.h>
#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

ll n, m, res;

vector <ll> arr, towers, dists;

void Init()
{
    cin >> n >> m;
    arr.resize(n);
    towers.resize(m);
    dists.resize(n);
    for (ll i = 0; i < n; ++i)
        cin >> arr[i];
    for (ll i = 0; i < m; ++i)
        cin >> towers[i];
}

inline ll CountDist(ll x, ll y)
{
    return abs(x - y);
}

ll Prev(ll i)
{
    if (i - 1 < 0)
        return 3000000010;
    else
        return towers[i - 1];
}

ll Next(ll i)
{
    if (i + 1 >= towers.size())
        return 3000000010;
    else
        return towers[i + 1];
}

ll BinS(ll val, ll s_start = 0, ll s_end = m)
{
    ll mid = (s_start + s_end) / 2;
    if (CountDist(val, Prev(mid)) >= CountDist(val, towers[mid]) && CountDist(val, Next(mid)) >= CountDist(val, towers[mid]))
        return CountDist(val, towers[mid]);
    else if (CountDist(val, Prev(mid)) < CountDist(val, towers[mid]))
        return BinS(val, s_start, mid);
    else if (CountDist(val, Next(mid)) < CountDist(val, towers[mid]))
        return BinS(val, mid, s_end);
}

void Solve()
{
    sort(towers.begin(), towers.end());
    for (int i = 0; i < n; ++i)
        dists[i] = BinS(arr[i]);
    for (int i = 0; i < n; ++i)
        res = max(res, dists[i]);
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
