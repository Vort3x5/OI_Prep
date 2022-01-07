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
    cin >> n;
    sqr_n = sqrt(n);
    arr.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    cin >> q;
    qs.resize(q);
    for (int i = 0; i < q; ++i)
    {
        cin >> qs[i].a >> qs[i].b;
        qs[i].i = i  + 1;
    }
}

bool Cmp(Qr lv, Qr rv)
{
    return ((lv.a / sqr_n) != (rv.a / sqr_n) ? (lv.a / sqr_n) < (rv.a / sqr_n)
            : lv.b > rv.b);
}

bool Cmp2(Qr lv, Qr rv)
{
    return (lv.i <= rv.i);
}

void Solve()
{
    for (auto qr : qs)
    {
        int res = 0;
        for (int i = qr.a - 1; i < qr.b; ++i)
        {
            if (occs[arr[i]] != qr.i)
            {
                ++res;
                occs[arr[i]] = qr.i;
            }
        }
        cout << res << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}
