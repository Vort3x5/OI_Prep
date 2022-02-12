#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int t, n;

vector <ll> arr;

void Init()
{
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
}

void Solve()
{
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        Init();
        bool unsorted = false;
        for (int i = 0; i < (n - 1); ++i)
        {
            if (arr[i] > arr[i + 1])
            {
                unsorted = true;
                break;
            }
        }
        if (!unsorted)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}
