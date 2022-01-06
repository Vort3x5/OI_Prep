#include <bits/stdc++.h>
using namespace std;

struct Inputs
{
    int l, x, a, b;
};

struct Cuff
{
    int val;
    bool is_full = true;
};

int d, n, sqr_d, wdth, mx;
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

int HighBlock(Inputs obj)
{
    int res = 0, i = obj.a;
    while (i < obj.b)
    {
        if (obj.a <= ((i / sqr_d) * sqr_d))
        {
            res = max(res, cuffs[i / sqr_d].val);
        }
        else
        {
            res = max(res, heights[i]);
        }
        i += pow(((i / sqr_d) * sqr_d + sqr_d - i),
                (cuffs[i / sqr_d].is_full && ((i / sqr_d) * sqr_d + sqr_d) < obj.b));
    }
    return res + 1;
}

void Update(Inputs obj, int lvl)
{
    for (int i = obj.a; i < obj.b; 
            i += pow(sqr_d, ((!(i % sqr_d) && (i / sqr_d) * sqr_d + sqr_d) < obj.b)))
    {
        if (!(i % sqr_d) && ((i / sqr_d) * sqr_d) >= obj.a && (i + sqr_d) <= obj.b)
        {
            cuffs[i].val = lvl, cuffs[i].is_full = true;
        }
        else
        {
            heights[i] = lvl;
            cuffs[i / sqr_d].val += (heights[i] > cuffs[i / sqr_d].val) * (lvl - cuffs[i / sqr_d].val);
        }
    }
}

void Solve()
{
    for (int i = 0; i < n; ++i)
    {
        mx = max(mx, HighBlock(arr[i]));
        Update(arr[i], HighBlock(arr[i]));
    }
    cout << mx << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}
