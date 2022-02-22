#include <algorithm>
#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int t, n;

v_i seq;

void Init()
{
    cin >> n;
    seq.resize(n);
    for (int i = 0; i < n; ++i)
        seq[i] = (i + 1);
}

void Solve()
{
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        Init();
        for (int k = 0; next_permutation(seq.begin(), seq.end()) && k < n;)
        {
            bool failed = false;
            for (int j = 2; j < n; ++j)
            {
                if (seq[j] == seq[j - 1] + seq[j - 2])
                {
                    failed = true;
                    break;
                }
            }
            if (failed)
                continue;
            for (auto it : seq)
                cout << it;
            cout << '\n';
            ++k;
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
