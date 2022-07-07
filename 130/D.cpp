#include <bits/stdc++.h>

using namespace std;

typedef pair <long long, long long> p_l;

int n, res;
long long to_mod = 998244353;

vector <p_l> arr;

void Init()
{
    scanf("%d", &n);
    arr.resize(n);
    for (p_l &i : arr)
        scanf("%d%d", &i.first, &i.second)
}

int Dist(p_l a, p_l b)
{
    return (abs(a.first - b.first) + abs(a.second - b.second));
}

void Solve()
{
    printf("%d\n", res % to_mod);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}
