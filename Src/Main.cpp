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
    presuf.resize(2 * s.size() + 10);
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
    if (presuf[2 * i + 1] != i)
        return false;
    int z;
    for (int j = 2 * i + 1; j < w.size(); ++j)
    {
        if (presuf[j] == i)
            z = 0;
        else if (!((++z) % i) && presuf[j] != i)
            return false;
    }
    return true;
}

void Solve()
{
    KMP(s);
    int length = presuf[s.size()];
    for (int i = 0; i < length; ++i)
    {
        string w;
        w.resize(length);
        for (int j = 0; j < length; ++j)
            w[j] = s[j];
        KMP(w);
        if (presuf[w.size()] == length || presuf[w.size()] == 0)
            break;
        sizes.pf(length);
        length = presuf[w.size()];
    }
    int prev = 0;
    for (int it : sizes)
    {
        if (it > (prev * 2) && CheckPattern(it))
        {
            length = it;
            break;
        }
        prev = it;
    }
    cout << length << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}
