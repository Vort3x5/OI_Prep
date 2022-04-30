#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

struct Inputs
{
    vector <ll> plan, dist;
};

int n, q;
ll mx, mn = 1000000010;
Inputs in;

vector <ll> non_pref;

void Init()
{
    scanf("%d", &n);
    in.plan.resize(n + 10);
    non_pref.resize(n + 10);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &in.plan[i]);

    scanf("%d", &q);
    in.dist.resize(n + 10);
    for (int i = 0; i < q; ++i)
    {
        scanf("%lld", &in.dist[i]);
        --in.dist[i];
    }

    non_pref[0] = in.plan[0];
    for (int i = 1; i < n; ++i)
    {
        non_pref[i] = (in.plan[i] - in.plan[i - 1]);
        mn = min(mn, non_pref[i]);
        mx = max(mx, non_pref[i]);
    }
}

ll BinS(int player, ll bg = 0, ll nd = n)
{
    ll mid = (bg + nd) / 2;
    if (non_pref[mid] <= in.dist[player] && non_pref[mid + 1] > in.dist[player])
        return mid;
    else if (non_pref[mid] > in.dist[player])
        return BinS(player, bg, mid);
    else
        return BinS(player, mid, nd);
}

void Solve()
{
    for (int player = 0; player < q; ++player)
    {
        if (in.dist[player] < mn)
            printf("0\n");
        else if (in.dist[player] >= mx)
            printf("%lld\n", in.plan[n - 1]);
        else
            printf("%lld\n", in.plan[BinS(player)]);
    }
}

int main()
{
    Init();
    Solve();

    return 0;
}
