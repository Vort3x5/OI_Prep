#include <bits/stdc++.h>
#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int t, n;

vector <ll> a, b;
deque <ll> remain_a, remain_b;

ll amount_a[1000000010], amount_b[1000000010], res;

void Init()
{
    cin >> n;
    res = 0;
    a.resize(n);
    b.resize(n);
    memset(amount_a, 0, sizeof amount_a);
    memset(amount_b, 0, sizeof amount_b);
    for (ll &i : a)
    {
        cin >> i;
        ++amount_a[i];
    }
    for (ll &i : b)
    {
        cin >> i;
        ++amount_b[i];
    }
    for (int i = 1; i <= 1000000000; ++i)
    {
        if (amount_a[i] < amount_b[i])
            for (int j = 0; j < amount_b - amount_a; ++j)
                remain_a.pb(i);
        
        else if (amount_b[i] < amount_a[i])
            for (int j = 0; j < amount_a - amount_b; ++j)
                remain_b.pb(i);
    }
}

int F(int x)
{
    int curr_res = 0;
    while (x)
        x /= 10, ++curr_res;
    return curr_res;
}

void Solve()
{
    cin >> t;
    for (int qr = 0; qr < t; ++qr)
    {
        Init();
        for (int i = 0; i < remain_a.size(); ++i)
        {
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Solve();

    return 0;
}
