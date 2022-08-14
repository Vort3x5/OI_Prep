#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;
typedef vector <ll> v_ll;

int n;

vector <v_i> dists;
v_i qs;
v_ll res;
bitset <600> added;

void Init()
{
    cin >> n;
    dists.resize(n + 1);
    res.resize(n + 1);
    qs.resize(n + 1);
    for (int i = 0; i <= n; ++i)
        dists[i] = v_i(n + 1, 0);
    int w;
    for (int src = 1; src <= n; ++src)
    {
        for (int dest = 1; dest <= n; ++dest)
        {
            cin >> w;
            dists[src][dest] = w;
        }
    }
    for (int qr = 0; qr < n; ++qr)
        cin >> qs[qr];
}


void Solve()
{
    for (int qr = n - 1, i = 0; qr >= 0; --qr, ++i)
    {
        ll sum = 0;
        added[qs[qr]] = true;
        for (int src = 1; src <= n; ++src)
        {
            for (int dest = 1; dest <= n; ++dest)
                dists[src][dest] = min(dists[src][dest], dists[src][qs[qr]] + dists[qs[qr]][dest]);
        }
        for (int src = 1; src <= n; ++src)
        {
            for (int dest = 1; dest <= n; ++dest)
                if (added[src] && added[dest])
                    sum += dists[src][dest];
        }
        res[i] = sum;
    }
    for (int i = n - 1; i >= 0; --i)
        cout << res[i] << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}
