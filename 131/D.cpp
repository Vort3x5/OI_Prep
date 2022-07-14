#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef pair <int, int> p_i;
typedef vector <int> v_i;
typedef long long ll;

int t, n;

v_i arr;
vector <v_i> graph;
vector <bool> used;

void Init()
{
    scanf("%d", &n);
    arr.resize(n);
    graph.resize(n + 10);
    graph.clear();
    used = vector <bool>(n + 10, false);
    for (auto &it : arr)
        scanf("%d", &t);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if ((i + 1) / j == arr[i])
                graph[i + 1].pb(j);
        }
    }
}

void Solve()
{
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
    {
        Init();
        for (int j = 1; j <= n; ++j)
        {
            if (graph[j].size() == 1)
                used[graph[j][0]] = true
            else
            {
                int res = 0;
                for (int node : graph[j])
                    res += !used[node];
                if (res > 1)
                    continue;
                else
                {
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();

    return 0;
}
