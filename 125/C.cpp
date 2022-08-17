#include <bits/stdc++.h>
#include <cmath>
#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int t, n;

string seq;
stack <bool> opened;

void Init()
{
    cin >> n >> seq;
}

void Solve()
{
    cin >> t;
    for (int q = 0; q < t; ++q)
    {
        Init();
        int r = 0, c = n;
        string pal;
        pal.clear();
        int j = 0;
        for (int i = 0; i < seq.size(); ++i)
        {
            if (seq[i] == '(')
                opened.push(true);
            else if (!opened.empty())
            {
                opened.pop();
                if (opened.empty())
                    ++r, c -= (i - j) + 1, j = i;
            }
        }
        cout << r << ' ' << c << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Solve();

    return 0;
}
