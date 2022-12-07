#include <bits/stdc++.h>

#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_back

using namespace std;

typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;
typedef pair <int, int> p_i;
typedef pair <s64, s64> p_ll;
typedef vector <int> v_i;
typedef vector <s64> v_ll;

s32 n, m;

v_i sig;
vector <p_i> masts;

void Init()
{
    cin >> n >> m;
    sig.resize(n + 10);
    masts.resize(n + 10);
}

void Insert(s32 x, s32 s, s32 a)
{
    masts[x] = {s, a};
    for (s32 i = 1; i <= n; ++i)
    {
        if (i == x)
            sig[i] = s;
        else if (abs(x - i) * a < s)
            sig[i] += s - abs(x - i) * a;
    }
}

void Del(s32 x)
{
    s32 s = masts[x].first, a = masts[x].second;
    for (s32 i = 1; i <= n; ++i)
    {
        if (i == x)
            sig[i] = s;
        if (abs(x - i) * a < s)
            sig[i] -= s - abs(x - i) * a;
    }
}

s32 Query(s32 a, s32 b)
{
    s32 sum = 0;
    for (s32 i = a; i <= b; ++i)
        sum += sig[i];
    return (sum / (b - a + 1));
}

void Sub1()
{
    for (s32 qr = 0; qr < m; ++qr)
    {
        char ops;
        cin >> ops;
        s32 x1, x2, s, a;
        switch (ops)
        {
            case 'P':
                cin >> x1 >> s >> a;
                Insert(x1, s, a);
                break;
            
            case 'Z':
                cin >> x1 >> x2;
                cout << Query(x1, x2) << '\n';
                break;
            
            case 'U':
                cin >> x1;
                Del(x1);
                break;
        }
    }
}

void Sub3()
{
}

void Solve()
{
    if (n <= 2000 && m <= 2000)
        Sub1();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}

