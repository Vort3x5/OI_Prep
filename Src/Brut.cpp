#include <bits/stdc++.h>
#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int t, n;

vector <string> arr;

void Init()
{
    cin >> n;
    arr.clear();
    arr.resize(n);
    for (string &it : arr)
        cin >> it;
}

bool Eq(const string &f, const string &s)
{
    for (int i = 0; i < f.size(); ++i)
        if (f[i] != s[i])
            return false;
    return true;
}

void Solve()
{
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        Init();
        bool answer = true;
        for (int s = 0; s < n; ++s)
        {
            for (int j = 0; j < n; ++j)
            {
                if (s == j || arr[s].size() > arr[j].size())
                    continue;
                if (Eq(arr[s], arr[j]))
                {
                    answer = false;
                    break;
                }
            }
        }
        cout << (answer ? "YES" : "NO") << '\n';
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
