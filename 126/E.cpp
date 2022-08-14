#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int n, q;
string input[3];
v_i arr, parent, children, all_pref, scc_pref, horizon_pref, vert_pref, nxt;

void Init()
{
    cin >> n;
    for (int i = 0; i < 3; ++i)
        cin >> input[i];
    arr = v_i(3 * n + 1, 0);
    parent.resize(arr.size());
    children.resize(arr.size());
    iota(parent.begin(), parent.end(), 0);
    scc_pref.resize(n + 1);
    all_pref.resize(n + 1);
    vert_pref.resize(n + 1);
    horizon_pref.resize(n + 1);
    nxt.resize(n + 1);
    for (int i = 0, indx = 1; i < 3; ++i)
        for (int j = 0; j < n; ++j, ++indx)
            arr[indx] = input[i][j] - '0';
}

inline int GetParent(int v) { return v == parent[v] ? v : parent[v] = GetParent(parent[v]); }

bool Unite(int v1, int v2)
{
    v1 = GetParent(v1), v2 = GetParent(v2);
    if (v1 == v2)
        return false;

    if (children[v1] < children[v2])
        swap(v1, v2);
    parent[v2] = v1;
    children[v1] += children[v2];
    return true;
}

void PreProcess()
{
    for (int i = 1; i <= n; ++i)
    {
        all_pref[i] += all_pref[i - 1];
        for (int j = 0; j < 3; ++j)
            all_pref[i] += arr[i + (j * n)];
    }
    for (int j = 1; j <= n; ++j)
    {
        for (int i = 0; i < 2; ++i)
            if (arr[j + (i * n)] && arr[j + ((i + 1) * n)] && Unite(j + (i * n), j + ((i + 1) * n)))
                ++vert_pref[j];
        for (int i = 0; i < 3; ++i)
            if (j > 1 && arr[j + (i * n)] && arr[j + (i * n) - 1] && Unite(j + (i * n), j + (i * n) - 1))
                ++horizon_pref[j - 1];
    }
    for (int i = 1; i <= n; ++i)
        vert_pref[i] += vert_pref[i - 1], horizon_pref[i] += horizon_pref[i - 1];
    for (int i = n; i > 0; --i)
        nxt[i - 1] = (arr[i] && !arr[i + n] && arr[i + (2 * n)] ? (nxt[i] + 1) : 0);
}

void Solve()
{
    PreProcess();
    cin >> q;
    for (int qr = 0; qr < q; ++qr)
    {
        int l, r;
        cin >> l >> r;
        --l, --r;
        int non101 = l + nxt[l];
        if (non101 > r)
        {
            cout << "2\n";
            continue;
        }
        int all = all_pref[r + 1] - all_pref[non101];
        int joined = (vert_pref[r + 1] - vert_pref[non101]) + (horizon_pref[r] - horizon_pref[non101]);
        int res = all - joined;
        if (non101 != l)
        {
            if (arr[non101 + 1] && arr[non101 + 1 + n] && arr[non101 + 1 + (2 * n)]);
            else if (arr[non101 + 1] == '0' && arr[non101 + 1 + n])
                res += 2;
            else
                ++res;
        }
        cout << res << '\n';
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
