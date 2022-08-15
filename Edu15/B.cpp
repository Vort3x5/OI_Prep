#include <bits/stdc++.h>
#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

ll n, res;

vector <ll> arr;

ll amount[1000000010];

void Init()
{
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        ++amount[arr[i]];
    }
}

void Solve()
{
    for (int i = 0; i < n - 1; ++i)
    {
        int curr = arr[i];
        for (int j = i + 1; j < n; ++j)
            if (1 << int(log2(arr[j] + curr)) == arr[j] + curr)
                ++res;
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
