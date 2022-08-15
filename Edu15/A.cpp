#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define INF 10e9

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int n, res;

v_i arr;

void Init()
{
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
}

void Solve()
{
    int prev = 0, curr = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > prev)
        {
            ++curr;
            res = max(res, curr);
        }
        else
        {
            res = max(res, curr);
            curr = 1;
        }
        prev = arr[i];
    }
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Init();
    Solve();

    return 0;
}
