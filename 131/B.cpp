#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef pair <int, int> p_i;
typedef vector <int> v_i;
typedef long long ll;

int t, n, d, cost;

vector <bool> used;
vector <int> divs

void Init()
{
    scanf("%d", &n);
    divs = vector <int> (n, 0);
    used = vector <bool> (n, 0);
    d = 0;
    res = 0;
}

int Div(int x)
{
    for (int i = 2; i < x; ++i)
        if (!(x % i))
            return i;
}

void Solve()
{
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
    {
        Init();
        for (int j = n; j > 0; --j)
        {
            int curr_res = Div(j);
            if (++divs[curr_res] > cost)
            {
                cost = divs[curr_res];
            }
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
