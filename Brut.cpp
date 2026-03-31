#include <bits/stdc++.h>
using namespace std;

struct Qr
{
    int type, a, b, k;
};

int n, qs;
vector <int> arr;

void Init()
{
    cin >> n >> qs;
    arr.resize(n);
    for (auto &i : arr)
    {
        cin >> i;
    }
}

void Solve()
{
    Qr q;
    for (int i = 0; i < qs; ++i)
    {
        cin >> q.type >> q.a >> q.b;
        switch (q.type)
        {
            case 1:
                arr[q.a - 1] = q.b;
                break;
            
            case 2:
                cin >> q.k;
                int count = 0;
                for (int i = q.a - 1; i < q.b; ++i)
                {
                    count += !arr[i];
                    if (count == q.k)
                    {
                        count = i + 1;
                        break;
                    }
                }
                cout << count << '\n';
                break;
        }
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
