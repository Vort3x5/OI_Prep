#include <bits/stdc++.h>
using namespace std;

struct Qr
{
    int a, b, i;
};

int n, q, sqr_n;
vector <int> arr;
vector <Qr> qs;
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
        cin >> qs[i].a >> qs[i].b;
        qs[i].i = i;
    }
}

bool Cmp(Qr lv, Qr rv)
{
    return ((lv.a / sqr_n) != (rv.a / sqr_n) ? (lv.a / sqr_n) < (rv.a / sqr_n) 
            : lv.b > rv.b);
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
