#include <cstdio>
#include <vector>
#include <algorithm>

const int maxn=1000002;

std::vector<int>v[maxn],top,g[maxn];
int n,m,a,b,s,e,il=1;
long long fi[maxn];
bool odw[maxn], osiaga[maxn];
int scc[maxn];
long long sum[maxn];
long long res[maxn];
std::vector <int> gsc[maxn];

void dfs(int x)
{
    odw[x]=true;
    for(int i : v[x])if(!odw[i])dfs(i);
    top.push_back(x);
}

void ScDfs(int x, int i)
{
    scc[x] = i, sum[i] += fi[x];
    for (int node : g[x])
        if (!scc[node])
            ScDfs(node, i);
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &e);
    for(int i = 1; i <= n; i++)scanf("%lld", &fi[i]);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        g[b].push_back(a);
    }
    top.reserve(n);
    for(int i = 1; i <= n; i++)if(!odw[i])dfs(i);
    for (int i = top.size() - 1; i >= 0; --i)
        if (!scc[top[i]])
            ScDfs(top[i], il++);
    for (int i = 1; i <= n; ++i)
    {
        for (int j : v[i])
            if (scc[j] != scc[i])
                gsc[scc[i]].push_back(scc[j]);
    }
    osiaga[scc[e]] = true;
    for (int i = scc[e]; i >= scc[s]; --i)
    {
        long long maks = 0;
        for (int j : gsc[i])
        {
            if (osiaga[j]) {
                maks = std::max(maks, res[j]);
                osiaga[i] = true;
            }
        }
        if(osiaga[i])
            res[i] = maks + sum[i];
    }
    printf("%lld", res[scc[s]]);
}