#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

#define stc sub_tree_count

int n, dp[100010][2];

struct Edge
{
    v_i deston;
    bool vis;
};

vector <Edge> graph;

void Init()
{
    scanf("%d", &n);
    graph.resize(n + 10);
    for (int i = 1; i < n; ++i)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        graph[v].deston.pb(u);
        graph[u].deston.pb(v);
    }
}

int Dfs(int v = 1)
{
    graph[v].vis = true;
    for (int node : graph[v].deston)
    {
        if (!graph[node].vis)
            dp[v][1] += min(dp[node][0], dp[node][1]), dp[v][0] += dp[node][1];
    }
    ++dp[v][1];
    return min(dp[v][1], dp[v][0]);
}

void Solve()
{
    printf("%d\n", Dfs());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}
