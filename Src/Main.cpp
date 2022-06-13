#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

struct Edge
{
    v_i deston;
};

int n, m, src, dest;

vector <Edge> graph;

void Init()
{
    scanf("%d%d", &n, &m);
    graph.resize(n + 10);
    for (int i = 0; i < m; ++i)
    {
    }
    scanf("%d%d", &src, &dest);
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
