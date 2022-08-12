#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

struct Edge
{
    v_i dest;
    bool is = false;
};

int n, q;
string input[3];
v_i arr, scc, scc_pref;
vector <Edge> graph;
bitset <500010> found;

void Init()
{
    cin >> n;
    for (int i = 0; i < 3; ++i)
        cin >> input[i];
    arr = v_i(3 * n + 1, 0);
    graph.resize(arr.size());
    scc.resize(arr.size());
    scc_pref.resize(n + 1);
    for (int i = 0, indx = 1; i < 3; ++i)
        for (int j = 0; j < n; ++j, ++indx)
            arr[indx] = input[i][j] - '0';
}

void AddChild(int v)
{
    graph[v].is = true;
    int node = v - n;
    for (int i = 1; i < 3; ++i)
    {
        for (int j = node - 1; j <= node + 1; ++j)
            if (j > 0 && j < graph.size() && !arr[j] && j != v)
                graph[v].dest.pb(j);
        node += n;
    }
}

void BuildGraph()
{
    for (int i = 1; i <= n * 3; ++i)
        if (!arr[i])
            AddChild(i);
}

void SccDfs(int v, int scc_count)
{
    scc[v] = scc_count;
    for (int &node : graph[v].dest)
        if (!scc[node])
            SccDfs(node, scc_count);
}

void CountPrefSum()
{
    for (int i = 1; i <= n; ++i)
    {
        scc_pref[i] = scc_pref[i - 1];
        for (int j = i; j < arr.size(); j += n)
            if (scc[j] && !found[scc[j]])
                found[scc[j]] = true, ++scc_pref[i];
    }
}

void Solve()
{
    BuildGraph();
    for (int v = 1, scc_count = 0; v < graph.size(); ++v)
        if (!scc[v])
            SccDfs(v, ++scc_count);
    cin >> q;
    for (int qr = 0; qr < q; ++qr)
    {
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Init();
    Solve();

    return 0;
}
