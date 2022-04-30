#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int n, res;

bitset <1001> is;

void Init()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int x;
        string name;
        scanf("%d%s", &x, name.c_str());
        res += !is[x];
        is[x] = true;
    }
}

void Solve()
{
    printf("%d\n", res);
}

int main()
{
    Init();
    Solve();

    return 0;
}
