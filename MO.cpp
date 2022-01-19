#include <bits/stdc++.h>
using namespace std;

struct Qr
{
    int a, b, i, answ;
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
        qs[i].i = i, --qs[i].a, --qs[i].b;
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
    int l, r, answ = 1;
    l = r = qs.begin()->a;
    ++occs[arr[l]];
    for (auto &qr : qs)
    {
        if (qr.a == qr.b)
        {
            qr.answ = 1;
            continue;
        }
        do
        {
            if (l < qr.a)
            {
                --occs[arr[l]];
                answ -= !(occs[arr[l]]);
                ++l;
            }
            else if (l > qr.a)
            {
                --l;
                answ += !(occs[arr[l]]);
                ++occs[arr[l]];
            }
        }
        while (l != qr.a);
        
        do
        {
            if (r > qr.b)
            {
                --occs[arr[r]];
                answ -= !(occs[arr[r]]);
                --r;
            }
            if (r < qr.b)
            {
                ++r;
                answ += !(occs[arr[r]]);
                ++occs[arr[r]];
            }
        }
        while (r != qr.b);
        qr.answ = answ;
    }
    sort(qs.begin(), qs.end(), Cmp2);
    for (auto qr : qs)
    {
        cout << qr.answ << '\n';
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
