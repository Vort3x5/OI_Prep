#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;


int log_of_l;
string s, sub1, sub2;

vector <v_i> suf;

void Init()
{
    cin >> s >> sub1 >> sub2;
    log_of_l = int(log2(s.size()) + 1);
    suf.resize(log_of_l);
    id.resize(300);
    for (v_i &vi : suf)
        vi.resize(s.size() + 1);
}

void KMR()
{
    int j = 1;
    for (int i = 0; i < s.size(); ++i)
        suf[0][i] = s[i] - 'a' + 1;
}

void Solve()
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();
    Solve();

    return 0;
}
