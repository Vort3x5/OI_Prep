#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int t, n;

vector <ll> arr;
multiset <ll> segment;

void Init()
{
    cin >> n;
    arr.resize(n);
    for (auto &it : arr)
    {
        cin >> it;
    }
}

void Solve()
{
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        Init();
        ll res = 0;
        for (int bg = 0; bg < n; ++bg)
        {
            for (int seg = bg; seg <= n; ++seg, segment.clear())
            {
                for (int j = bg; j < seg; ++j)
                {
                    segment.insert(arr[i]);
                }
                ll biggest = *segment.rbegin();
                int count = -2;
                for (auto it = segment.rbegin(); *it == biggest && it > segment.rend()
                        ; --it)
                {
                    ++count;
                }
            }
        }
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
