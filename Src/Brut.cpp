#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int n, t;
string s1, s2;

void Init()
{
    scanf("%d", &n);
    cin >> s1 >> s2;
}

int Cmp()
{
    for (int i = 0; i < n; ++i)
    {
        if (s1[i] > s2[i])
            return 1;
        else if (s1[i] < s2[i])
            return 2;
    }
    return 0;
}

void Solve()
{
    scanf("%d", &t);
    for (int q = 0; q < t; ++q)
    {
        int i, j;
        scanf("%d%d", &i, &j);
        swap(s1[i], s2[j]);
        printf("%d\n", Cmp());
    }
}

int main()
{
    Init();
    Solve();

    return 0;
}
