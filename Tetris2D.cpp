#include <bits/stdc++.h>
using namespace std;

struct Inputs
{
    int l, x, a, b;
};

struct Cuff
{
    int val;
    bool is_full;
};

int d, n, sqr_d, wdth, last_saved;
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

int HighBlock(Inputs obj, int lvl)
{
}

void Update(Inputs obj)
{
    if (!(obj.a % sqr_d) && obj.b >= (obj.a + sqr_d))
    {
        int i;
        for (i = (obj.a / sqr_d); i < obj.b; i += sqr_d)
        {
            ++cuffs[i].val, cuffs[i].is_full = true;
        }
        if (obj.b  % sqr_d)
        {
        }
    }
}

void Solve()
{
    for (int i = 0; i < n; ++i)
    {
        last_saved = HighBlock(arr[i], last_saved);
        Update(arr[i]);
    }
    cout << last_saved + 1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}
