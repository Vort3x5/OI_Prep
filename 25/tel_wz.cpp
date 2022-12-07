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

struct Query
{
    char op;
    s32 x1, x2, s, a;
};

s32 n, m;

vector <Query> qs;
v_i arr, prefs;
vector <p_i> sigs;

void Init()
{
    cin >> n >> m;
    qs.resize(m);
    arr.resize(n + 10);
    prefs.resize(n + 10);
    sigs.resize(n + 10);
    for (Query &qr : qs)
    {
        cin >> qr.op;
        switch (qr.op)
        {
            case 'P':
                cin >> qr.s >> qr.a;
                break;
            
            case 'U':
                cin >> qr.x1;
                break;
                
            case 'Z':
                cin >> qr.x1 >> qr.x2;
                break;
        }
    }
}

void Sub2()
{
    for (s32 i = 0; i < m; ++i)
    {
        if (qs[i].op == 'P');
    }
}

void Solve()
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}
