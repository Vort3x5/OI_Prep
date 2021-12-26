#include <bits/stdc++.h>
using namespace std;

struct Inputs
{
    int l, x, a, b;
};

int d, n, sqr_d, last_saved;
int cuff;
vector <Inputs> arr;
deque <vector <int>> cuffs;

void Init()
{
    cin >> d >> n;
    sqr_d = sqrt(d);
    arr.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i].l >> arr[i].x;
        arr[i].a = arr[i].x, arr[i].b = arr[i].x + arr[i].l;
    }
}

void AddLvl()
{
    cuffs.push_back(vector <int>(d));
}

int HighBlock(Inputs obj, int lvl, bool prev_failed = false)
{
    for (int i = cuff; i <= obj.b;)
    {
        if (cuffs[lvl][i] > obj.a)
        {
            if (cuffs.size() >= (lvl + 1))
            {
                AddLvl();
            }
            return HighBlock(obj, lvl + 1, true);
        }
        i = (cuffs[lvl][i] ? cuffs[lvl][i] : ++i);
    }
    return (prev_failed  || !lvl ? lvl : HighBlock(obj, lvl - 1));
}

void Solve()
{
    AddLvl();
    for (int i = 0; i < n; ++i)
    {
        cuff = ((arr[i].a / sqr_d) * sqr_d);
        last_saved = HighBlock(arr[i], last_saved);
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
