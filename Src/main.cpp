#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

struct Edge
{
    vector <int> dest;
    int weight[20];
    int parent[20];
};

int N, K;
vector <Edge> graph;

void Init()
{
    scanf("%d", &N);
    graph.resize(N + 10);
    for (int i = 0; i < (N - 1); ++i)
    {
        int A, B, C;
        scanf("%d%d%d", &A, &B, &C);
        graph[A].dest.pb(C);
    }
}

void Dfs(int v, int par = 1)
{}

void Solve()
{
}

int main()
{
    Init();
    Solve();

    return 0;
}
