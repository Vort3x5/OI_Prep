#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;


int log_of_l;
string s, sub1, sub2;

vector <p_i> id;
vector <v_i> kmr;

void Init()
{
    cin >> s >> sub1 >> sub2;
    log_of_l = int(log2(s.size()) + 1);
    id.resize(s.size() + 1);
}

void KMR()
{
    pair <int , pair <int, int> > pomoc[s.size() + 2];
    int r = log(s.size()) + 1, pot = 1;
    for (int i = 0; i < s.size(); i ++)
        kmr[i][0] = (s[i] - 'a') + 1;
    for (int x = 1;x <= r; x ++) {
        for(int i = 0;i < s.size(); i ++) {
            if (i+pot >= s.size())
                pomoc[i] = make_pair(
                    kmr[i][x-1],
                    make_pair(-1, i));
            else
                pomoc[i] = make_pair(
                    kmr[i][x-1],
                    make_pair(kmr[i+pot][x-1], i));
        }
        sort(pomoc,pomoc+s.size());
        pair <int, int> pom = make_pair(-1,-1);
        int ile = -1;
        for(int i = 0;i < s.size(); i ++) {
            if(pom.first != pomoc[i].first
                || pom.second != pomoc[i].second.first
            ) {
                pom = make_pair(
                    pomoc[i].first,
                    pomoc[i].second.first);
                    ++ile;
            }
            kmr[pomoc[i].second.second][x] = ile;
        }
        pot *= 2;
    }
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
