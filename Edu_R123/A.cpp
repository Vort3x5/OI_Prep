#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int t;
int f[1000];

string mp;

void Init()
{
    cin >> mp;
}

void Solve()
{
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        Init();
        bool failed = false;
        for (auto c : mp)
        {
            if (c < 97)
            {
                if (f[c + 32] != (i + 1))
                {
                    cout << "NO\n";
                    failed = true;
                    break;
                }
            }
            else
            {
                f[c] = (i + 1);
            }
        }
        if (!failed)
            cout << "YES\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}
