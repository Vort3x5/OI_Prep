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
};

int N;
vector <Edge> graph;

void Init()
{
    scanf("%d", &N);
    graph.resize(N + 10);
    for (int i = 0; i < (N - 1); ++i)
    {
        int p, q;
        scanf("%d%d", &p, &q);
        graph[p].dest.push_back(q);
        graph[q].dest.push_back(p);
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
