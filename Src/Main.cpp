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
    bool vis[2];
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

int Dfs(int status, int iter = 0, int v = 1)
{
    graph[v].vis[iter] = true;
    for (int node : graph[v].deston)
    {
        if (!graph[node].vis[iter])
            dp[v][status] += Dfs(!status, iter, node);
    }
    return dp[v][status] + status;
}

void Solve()
{
    Dfs(0);
    Dfs(1, 1);
    printf("%d\n", min(dp[1][0], dp[1][1]));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}
