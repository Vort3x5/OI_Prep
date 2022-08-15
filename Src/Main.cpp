#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

v_i presuf;
deque <int> sizes;
string s;

void Init()
{
    cin >> s;
    presuf.resize(s.size() + 10);
}

void KMP(const string &w)
{
    presuf[0] = -1;
    presuf[1] = 0;
    int j = presuf[1];
    for (int i = 1; i < w.size(); ++i)
    {
        while(j != -1 && w[i] != w[j])
            j = presuf[j];
        ++j;
        presuf[i + 1] = j;
    }
}

bool CheckPattern(int i)
{
    string w;
    w.resize(i + 1);
    int j;
    for (j = 0; j < i; ++j)
        w[j] = s[j];
    w[j] = '#';
    w += s;
    KMP(w);
    for (int j = i + 1; j < w.size(); ++j)
        if (!presuf[j])
            return false;
    return true;
}

void Solve()
{
    KMP(s);
    sizes.pb(0);
    for (int i = 0; i <= s.size(); ++i)
        if (presuf[i] > sizes.back())
            sizes.pb(presuf[i]);
    sizes.pop_front();
    int prev = 0;
    while(!sizes.empty())
    {
        prev = sizes.front();
        if (CheckPattern(sizes.front()))
        {
            cout << sizes.front();
            break;
        }
        sizes.pop_front();
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}
