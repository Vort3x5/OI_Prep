#include <bits/stdc++.h>
#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int t;
string r1, r2;

v_i f;

void Init()
{
    cin >> r1 >> r2;
    f.clear();
    f.resize(300);
}

void Solve()
{
    cin >> t;
    for (int qr = 0; qr < t; ++qr)
    {
        Init();
        int os, ts, tr, fr;
        os = ts = tr = fr = 0;
        for (int i = 0; i < 2; ++i)
            ++f[r1[i]], ++f[r2[i]];
        for (int i = 'a'; i <= 'z'; ++i)
        {
            switch (f[i])
            {
                case 1:
                    ++os;
                    break;
                case 2:
                    ++ts;
                    break;
                case 3:
                    ++tr;
                    break;
                case 4:
                    ++fr;
                    break;
            }
        }
        if (tr == 1 || ts == 2)
            cout << 1 << '\n';
        else if (fr)
            cout << 0 << '\n';
        else if (os == 4)
            cout << 3 << '\n';
        else
            cout << 2 << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Solve();

    return 0;
}
