#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int t, n, m, sum;

vector <int> a;

void Init()
{
    sum = 0;
    scanf("%d", &n);
    a.clear();
    a.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        int x;
        scanf("%d", &x);
        sum += x;
    }
    sum %= n;
}

void Solve()
{
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
    {
        Init();
        if (!sum)
            printf("%d\n", a[0]);
        else
            printf("%d\n", a[n - (n - sum)]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}
