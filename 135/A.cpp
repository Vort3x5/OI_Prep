#include <algorithm>
#include <bits/stdc++.h>
#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int t, n;

v_i cnt;

void Init()
{
    cin >> n;
    cnt.resize(n);
    for (auto &i : cnt)
        cin >> i;
}

void Solve()
{
    cin >> t;
    for (int qr = 0; qr < t; ++qr)
    {
        Init();
        cout << max_element(cnt.begin(), cnt.end()) - cnt.begin()  + 1 << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Solve();

    return 0;
}
