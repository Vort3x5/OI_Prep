#include <bits/stdc++.h>
using namespace std;

struct Inputs
{
    int n, m, r, c;
    vector <string> grid;
    vector <bool> cls, rs;
};

int t;

vector <Inputs> arr;

void Init()
{
    cin >> t;
    arr.resize(t);
    for (int i = 0; i < t; ++i)
    {
        cin >> arr[i].n >> arr[i].m >> arr[i].r >> arr[i].c;
        arr[i].grid.resize(arr[i].n);
        arr[i].cls.resize(arr[i].m);
        arr[i].rs.resize(arr[i].n);
        --arr[i].r;
        --arr[i].c;
        for (int j = 0; j < arr[i].n; ++j)
        {
            cin >> arr[i].grid[j];
        }
    }
}

void Solve()
{
    for (int i = 0; i < t; ++i)
    {
        if (arr[i].grid[arr[i].r][arr[i].c] == 'B')
        {
            cout << 0 << '\n';
            continue;
        }
        int r = 0;
        for (auto row : arr[i].grid)
        {
            for (int c = 0; c < row.size(); ++c)
            {
                if (row[c] == 'B')
                {
                    arr[i].cls[c] = true;
                    arr[i].rs[r] = true;
                }
            }
            ++r;
        }
        if (arr[i].cls[arr[i].c] || arr[i].rs[arr[i].r])
        {
            cout << 1 << '\n';
            continue;
        }
        else
        {
            bool found = false;
            for (int c = 0; c < arr[i].m; ++c)
            {
                if (arr[i].cls[c])
                {
                    cout << 2 << '\n';
                    found = true;
                    break;
                }
            }
            if (found)
                continue;
        }
        cout << -1 << '\n';
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
