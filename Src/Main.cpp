#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int KMR[2000020][50], l, T;

string s, w;
pair <p_i, int> p[2000020];
v_i res;

void Init()
{
    cin >> s >> w;
    s = w + s;
    for (int i = 0; i < s.size(); ++i)
    {
        KMR[i][0] = s[i] - 'a' + 1;
    }
    l = ceil(log2(s.size()));
    for (int i = 1; i <= l; ++i)
    {
        int j;
        for (j = 0; j < s.size() - i; ++j)
            p[j].first = {KMR[j][i - 1], KMR[j + (1 << (i - 1))][i - 1]}, p[j].second = j;
        for (j = s.size() - i; j < s.size(); ++j)
            p[j].first = { KMR[j][i - 1], -1 }, p[j].second = j;
        sort(p, p + s.size());
        p_i x = { -1, -1 };
        int f = 0;
        for (j = 0; j < s.size(); ++j)
        {
            if (p[j].first.first != x.first || p[j].first.second != x.second)
                x = p[j].first, ++f;
            KMR[p[j].second][i] = f;
        }
    }
}

void Solve()
{
    cin >> T;
    for (int qr = 0; qr < T; ++qr)
    {
        Init();
        int lw = log2(w.size());
        int ls = 1 << lw;
        for (int i = w.size(); i < s.size(); ++i)
        {
            if (KMR[0][lw] == KMR[i][lw] && KMR[w.size() - ls][lw] == KMR[i + w.size() - ls][lw])
                res.pb(i - w.size() + 1);
        }
        if (res.empty())
            cout << "Not Found\n";
        else
        {
            cout << res.size() << '\n';
            for (int i : res)
                cout << i << ' ';
            cout << '\n';
        }
        res.clear();
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}
