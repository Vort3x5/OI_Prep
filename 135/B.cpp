#include <bits/stdc++.h>
#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int t, n;

v_i arr;

void Init()
{
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
        arr[i] = i + 1;
}

void Solve()
{
    cin >> t;
    for (int qr = 0; qr < t; ++qr)
    {
        Init();
        swap(arr[n - 3], arr[n - 4]);
        for (auto &i : arr)
            cout << i << ' ';
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Solve();

    return 0;
}
