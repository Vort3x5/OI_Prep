#include <bits/stdc++.h>

#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front

using namespace std;

typedef long long s64;
typedef unsigned long long u64;
typedef int s32;
typedef unsigned int u32;
typedef pair <int, int> p_i;
typedef vector <int> v_i;
typedef vector <long long> v_l;

u64 T;
s32 N;

bool res[100010];

void Init()
{
    cin >> N;
}

void PreProcess()
{
    res[0] = false;
    res[1] = true;
    for (int i = 2; i <= 100000; ++i)
    {
        for (int j = 1; j <= (int)sqrt(i); ++j)
            if(!res[i - (j * j)])
                res[i] = true;
    }
}

void Solve()
{
    cin >> T;
    PreProcess();
    for (int qr = 0; qr < T; ++qr)
    {
        Init();
        cout << (res[N] ? "Win\n" : "Lose\n");
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}
