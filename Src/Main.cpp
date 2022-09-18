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

s32 T, N, M;

bool res[10010][10000];

void Init()
{
    cin >> N >> M;
}

void PreProcess()
{
    for (int i = 0; i <= 10000; ++i)
    {
        for (int j = 1; j < 10000; ++j)
            res[i][j] = (((i + j) % 10) > i);
    }
}

void Solve()
{
    cin >> T;
    PreProcess();
    while(T--)
    {
        Init();
        cout << (res[M][N] ? "Ada\n" : "Vinit\n");
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}

