#include <bits/stdc++.h>

#define pb push_back
#define pf push_front
#define M 101810081ll

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int n, l, m, p1, p2, w1, w2, p = 29;

vector <string> arr;
vector <ll> hsh, pows;
vector <int> res;

unordered_map <ll, unordered_set<int>> sss;

void CountHash(string s, int k)
{
    for (int i = 0; i < l; ++i)
        hsh[k] = (hsh[k] + pows[i] * (s[i] - 'a' + 1)) % M;
}

void Init()
{
    cin >> n >> l >> m;
    arr.resize(n);
    hsh.resize(n);
    pows.resize(l + 1);
    res.resize(n);
    for (string &it : arr)
        cin >> it;
    pows[0] = 1;
    for (int i = 1; i <= l; ++i)
        pows[i] = (pows[i - 1] * p) % (ll)M;
    for (int i = 0; i < n; ++i)
        CountHash(arr[i], i);
}

void RecountHash(int pos, ll prev, ll val, int k)
{
    hsh[k] = (hsh[k] + (((val - prev + M) % M) * pows[pos])) % M;
}

void Solve()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (hsh[j] == hsh[i])
                ++res[i];
        }
    }
    for (int i = 0; i < n; ++i)
        sss[hsh[i]].insert(i);
    for (int q = 0; q < m; ++q)
    {
        cin >> p1 >> w1 >> p2 >> w2;
        sss[hsh[p1 - 1]].erase(p1 - 1);
        sss[hsh[p2 - 1]].erase(p2 - 1);
        swap(arr[p1 - 1][w1 - 1], arr[p2 - 1][w2 - 1]);
        RecountHash(w1 - 1, arr[p2 - 1][w2 - 1], arr[p1 - 1][w1 - 1], p1 - 1);
        RecountHash(w2 - 1, arr[p1 - 1][w1 - 1], arr[p2 - 1][w2 - 1], p2 - 1);
        sss[hsh[p1 - 1]].insert(p1 - 1);
        sss[hsh[p2 - 1]].insert(p2 - 1);
        for (auto &it : sss[hsh[p1 - 1]])
            res[it] = max(res[it], (int)sss[hsh[p1 - 1]].size());
        for (auto &it : sss[hsh[p2 - 1]])
            res[it] = max(res[it], (int)sss[hsh[p2 - 1]].size());
    }
    for (int i = 0; i < n; ++i)
        cout << res[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}
