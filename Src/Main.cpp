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
        char fst[3], snd[3];
        int p, q;
        scanf("%s%d%s%d", fst, &p, snd, &q);

        if (fst[0] == '+' && snd[0] == '+')
        {
            graph[n + p].deston.pb(q);
            graph[n + q].dist.pb(p);
        }
        else if (fst[0] == '+' && snd[0] == '-')
        {
            graph[n + p].deston.pb(n + q);
            graph[q].dist.pb(p);
        }
        else if (fst[0] == '-' && snd[0] == '+')
        {
            graph[p].deston.pb(q);
            graph[n + q].dist.pb(n + p);
        }
        else if (fst[0] == '-' && snd[0] == '-')
        {
            graph[p].deston.pb(n + q);
            graph[q].dist.pb(n + p);
        }
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
