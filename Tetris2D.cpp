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

int d, n, sqr_d, wdth, last_saved, mx;
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
    for (int i = obj.a; i < obj.b; i += sqr_d)
    {
        mx = max(mx, cuffs[i / sqr_d].val);
    }
    return mx;
}

void Update(Inputs obj)
{
    for (int i = obj.a; i < obj.b; 
            i = !(i % sqr_d) && obj.b >= (i + sqr_d) ? i += sqr_d : ++i)
    {
        if (!(i % sqr_d))
        {
            if (obj.b >= (i + sqr_d))
            {
                ++cuffs[i / sqr_d].val, cuffs[i / sqr_d].is_full = true;
            }
            else
            {
                ++cuffs[i / sqr_d].val, cuffs[i / sqr_d].is_full = false;
            }
        }
        else
        {
            ++heights[i];
            if (heights[i] > cuffs[i / sqr_d].val)
            {
                cuffs[i / sqr_d].val = heights[i];
            }
        }
    }
}

void Solve()
{
    for (int i = 0; i < n; ++i)
    {
        last_saved = HighBlock(arr[i], last_saved) + 1;
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
