#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int n, m;

vector <vector <int>> graph;

void Init()
{
    scanf("%d%d", &n, &m);
    graph.resize(n + 10);
    for (int e = 0; e < m; ++e)
    {
        int src, dest;
        scanf("%d%d", &src, &dest);
        graph[src].pb(dest);
    }
}

void Solve()
{
}

int main()
{
    Init();
    Solve();

    return 0;
}
