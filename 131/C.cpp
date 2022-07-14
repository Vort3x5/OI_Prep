#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef pair <int, int> p_i;
typedef vector <int> v_i;
typedef long long ll;

int t, n, m, opt, res;

v_i tasks;

void Init()
{
    scanf("%d%d", &n, &m);
    tasks = v_i(n, 0);
    opt = res = 0;
    for (int i = 0; i < m; ++i)
    {
        int x;
        scanf("%d", &x);
        opt = max(opt, ++tasks[x]);
    }
}

void Solve()
{
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
    {
        Init();
        int mx = max_element(tasks.begin(), tasks.end()) - tasks.begin(), mn = min_element(tasks.begin(), tasks.end()) - tasks.begin();
        while (tasks[mn] += 2 < --tasks[mx]);
        tasks[mx] += 1, tasks[mn] -= 2;
        printf("%d\n", min(opt, *(max_element(tasks.begin(), tasks.end()))));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}
