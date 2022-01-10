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
    sort(qs.begin(), qs.end(), Cmp);
    int l, r, answ = 0;
    l = r = qs.begin()->a;
    for (auto qr : qs)
    {
        while (l != (qr.a - 1))
        {
            if (l > (qr.a - 1))
            {
                --occs[arr[l]];
                answ -= !(occs[arr[l]]);
                --l;
                continue;
            }
            answ += !(occs[arr[l]]), ++occs[arr[l]], ++l;
        }
        while (r != (qr.a - 1))
        {
            if (r > (qr.a - 1))
            {
                --occs[arr[r]];
                answ -= !(occs[arr[r]]);
                --r;
                continue;
            }
            answ += !(occs[arr[r]]), ++occs[arr[r]], ++r;
        }
        cout << answ << '\n';
    }
    sort(qs.begin(), qs.end(), Cmp2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}
