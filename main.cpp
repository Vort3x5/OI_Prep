#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int N, K, f, s;
ll W, res, mx, sum;

void Init()
{
    cin >> N;
}

void Solve()
{
    for (int i = 0; i < N; ++i)
    {
        cin >> K;
        sum = mx = 0;
        for (int j = 0; j < K; ++j)
        {
            cin >> W;
            if (sum + W > 0)
                sum += W;
            else
                sum = 0;
            mx = max(mx, sum);
        }
        res += mx;
        if (res)
        {
            f += !f * (i + 1);
            s = i + 1;
        }
    }
    cout << res << '\n';
    cout << f << ' ' << s << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}
