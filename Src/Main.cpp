#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;


int log_of_l;
string s, sub1, sub2;

vector <v_i> kmr;
vector <p_i> id;

void Init()
{
    cin >> s >> sub1 >> sub2;
    log_of_l = int(log2(s.size()) + 1);
    kmr.resize(log_of_l + 1);
    id.resize(s.size() + 1);
    for (v_i &vi : kmr)
        vi.resize(s.size() + 1);
}

void KMR()
{
    int j = 1;
    for (int i = 0; i < s.size(); ++i)
        kmr[1][i] = s[i] - 'a' + 1;
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
