#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

struct Point
{
    int x, y;
};

int bx, by, n, res;

vector <Point> pos;

void Init()
{
    scanf("%d%d%d", &bx, &by, &n);
    pos.resize(n + 10);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &pos[i].x, &pos[i].y);
        res += (
                ((bx * pos[i].y) - (pos[i].x * by)) == 0 && pos[i].x >= 0 && pos[i].x <= bx && pos[i].y >= 0 && pos[i].y <= by
               );
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
