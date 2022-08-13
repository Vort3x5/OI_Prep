#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

struct Edge
{
    unordered_set <int> dest;
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
    if (v - n > 0 && arr[v - n])
        graph[v].dest.insert(v - n), graph[v - n].dest.insert(v);
    if (v - 1 > 0 && (v - 1) % n && arr[v - 1])
        graph[v].dest.insert(v - 1), graph[v - 1].dest.insert(v);
    if (v + 1 < graph.size() && v % n && arr[v + 1])
        graph[v].dest.insert(v + 1), graph[v + 1].dest.insert(v);
    if (v + n < graph.size() && arr[v + n])
        graph[v].dest.insert(v + n), graph[v + n].dest.insert(v);
}

void BuildGraph()
{
    for (int v = 1; v <= n * 3; ++v)
        if (arr[v])
            AddChild(v);
}

void SccDfs(int v, int scc_count)
{
    scc[v] = scc_count;
    for (int node : graph[v].dest)
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
        if (!scc[v] && arr[v])
            SccDfs(v, ++scc_count);
    CountPrefSum();
    cin >> q;
    for (int qr = 0; qr < q; ++qr)
    {
        int l, r, to_add = 0;
        cin >> l >> r;
        int used = 0;
        if (l > 1)
        {
            for (int v = l; v < arr.size(); v += n)
            {
                if (arr[v] && arr[v - 1])
                {
                    if (used != scc[v])
                        ++to_add, used = scc[v];
                }
            }
        }
        cout << scc_pref[r] - scc_pref[l - 1] + to_add << '\n';
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
