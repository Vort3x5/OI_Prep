#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int t, r, res;

void Init()
{
    scanf("%d", &r);
}

bool IsLeap(int r) { return ((!(r % 4) && (r % 100)) || !(r % 400)); }

void Solve()
{
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
    {
        Init();
        int j = 0;
        while (j == 0 || j % 7)
        {
            if (IsLeap(r))
                j += 2;
            else
                ++j;
            ++res, ++r;
        }
    }
    printf("%d\n", res);
}

int main()
{
    Solve();

    return 0;
}
