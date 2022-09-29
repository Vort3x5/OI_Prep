#include <bits/stdc++.h>

#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_back

using namespace std;

typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;
typedef pair <int, int> p_i;
typedef pair <s64, s64> p_ll;
typedef vector <int> v_i;
typedef vector <s64> v_ll;

struct Node
{
    bool is;
    p_i point;
};

s32 n;

vector <p_i> arr;
bitset <200010> xmex, ymex;

void Init()
{
    cin >> n;
    arr.resize(n);
    for (p_i &i : arr)
    {
        cin >> i.first >> i.second;
        xmex[i.first] = true;
        ymex[i.second] = true;
    }
}

void Solve()
{
    for (p_i &i : arr)
        // cout << min(BinS(), BinS()) << min(BinS(), BinS()) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}
