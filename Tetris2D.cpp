#include <bits/stdc++.h>
using namespace std;

struct Inputs
{
    int l, x, a, b;
};

struct Cuff
{
    int mx, full;
};

int d, n, sqr_d, wdth, res;
vector <Inputs> arr;
vector <int> heights;
vector <Cuff> cuffs;

void Init()
{
    cin >> d >> n;
    sqr_d = sqrt(d);
    wdth = static_cast <int>(d / sqr_d);
    arr.resize(n);
    heights.resize(d);
    cuffs.resize(wdth);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i].l >> arr[i].x;
        arr[i].a = arr[i].x, arr[i].b = arr[i].x + arr[i].l;
    }
}

int HighBlock(Inputs qr)
{
    int i = qr.a, mx = 0;
    while (i < qr.b)
    {
        if (!(i % sqr_d) && qr.b >= (i + sqr_d))
        {
            mx = max(mx, cuffs[i / sqr_d].mx);
            i += sqr_d;
        }
        else
        {
            mx = max(mx, max(cuffs[i / sqr_d].full, heights[i]));
            ++i;
        }
    }
    return mx;
}

void Update(Inputs qr)
{
    int i = qr.a, val = HighBlock(qr) + 1;
    res = max(res, val);
    while (i < qr.b)
    {
        if (!(i % sqr_d) && qr.b >= (i + sqr_d))
        {
            cuffs[i / sqr_d].full = val;
            cuffs[i / sqr_d].mx = val;
            i += sqr_d;
        }
        else
        {
            heights[i] = val;
            cuffs[i / sqr_d].mx = max(cuffs[i / sqr_d].mx, heights[i]);
            ++i;
        }
    }
}

void Solve()
{
    for (auto qr : arr)
    {
        Update(qr);
    }
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}
