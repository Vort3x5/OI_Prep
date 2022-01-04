#include <bits/stdc++.h>
using namespace std;

int n, q, sqr_n;
vector <int> arr;
vector <pair <int, int>> qs;
int occs[1000001];

void Init()
{
    cin >> n >> q;
    sqr_n = sqrt(n);
    arr.resize(n);
    qs.resize(q);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < q; ++i)
    {
        cin >> qs[i].first >> qs[i].second;
    }
}

bool Cmp(pair <int, int> a, pair <int, int> b)
{
    return ((a.first / sqr_n) != (b.first / sqr_n) ? (a.first / sqr_n) < (b.first / sqr_n) 
            : a.second > b.second);
}

void Solve()
{
    sort(qs.begin(), qs.end(), Cmp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}
