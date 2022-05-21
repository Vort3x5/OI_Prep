#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

struct Edge
{
    vector <int> deston;
    vector <bool> dist;
};

int n, m;

vector <Edge> graph;

void Init()
{
    scanf("%d%d", &n, &m);
    graph.resize(n + 10);
    for (int i = 0; i < n; ++i)
    {
        char fst, snd;
        int p, q;
        scanf("%c%d%c%d", &fst, &p, &snd, &q);

        graph[p].deston.pb(q);
        graph[p].dist.pb(fst == '+');

        graph[q].deston.pb(p);
        graph[q].dist.pb(snd == '+');
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
