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
    }
}

int Dfs(int v = 1, int status = 0)
{
    graph[v].vis = true;
    for (int node : graph[v].deston)
    {
        if (!graph[node].vis)
            dp[v][0] += Dfs(node, 1), dp[v][1] += Dfs(node, 0);
    }
    return 0;
}

void Solve()
{
    Dfs();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}
