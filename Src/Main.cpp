#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;
typedef int s32;

s32 Q, r, lvl;
string s;

v_i qs;
s32 KMR[1000010][21];
vector <pair <s32, p_i>> buffs;

void Init()
{
    cin >> s >> Q;
    r = log2(s.size()) + 1, lvl = 1;
    qs.resize(Q);
    buffs.resize(r + 1);
    for (s32 &i : qs)
        cin >> i;
}

void PreProcess()
{
    for (s32 i = 0; i < s.size(); ++i)
        KMR[i][0] = s[i] - 'a' + 1;
    for (s32 x = 1; x <= r; ++x)
    {
        for (s32 i = 0; i < s.size(); ++i)
        {
            if (i + lvl >= s.size())
                buffs[i] = make_pair(KMR[i][x - 1], make_pair(-1, i));
            else
                buffs[i] = make_pair(KMR[i][x - 1], make_pair(KMR[i + lvl][x - 1], i));
        }
        sort(buffs.begin(), buffs.end());
        p_i buff = {-1, -1};
        s32 cnt = -1;
        for (s32 i = 0; i < s.size(); ++i)
        {
            if (buff.first != buffs[i].first ||buff.second != buffs[i].second.first)
            {
                buff = {buffs[i].first, buffs[i].second.first};
                ++cnt;
            }
            KMR[buffs[i].second.second][x] = cnt;
        }
        lvl *= 2;
    }
}

void Solve()
{
    PreProcess();
    for (s32 &qr : qs)
    {
        for (s32 i = buffs[qr - 1].second.second; i < s.size(); ++i)
            cout << s[i];
        cout << '\n';
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
