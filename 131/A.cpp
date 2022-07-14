#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef pair <int, int> p_i;
typedef vector <int> v_i;
typedef long long ll;

int t, res;

void Init()
{
    res = 0;
}

void Solve()
{
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
    {
        Init();
        int p[4];
        for (int j = 0; j < 4; ++j)
        {
            scanf("%d", &p[j]);
            res += p[j];
        }
        printf("%d\n", res > 3 ? 2 : res ? 1 : 0);
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
