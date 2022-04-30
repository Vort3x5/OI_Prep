#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

struct Player
{
    int uid;
    string w;
};

int n, res;

vector <Player> msgs;
bitset <101> plays;

int Answ(const Player& obj)
{
    if (obj.w == "bede" || obj.w == "gram" || obj.w == "ja")
    {
        if (!plays[obj.uid])
        {
            plays[obj.uid] = true;
            return 1;
        }
        return 0;
    }
    else if (obj.w == "odpadam" || obj.w == "rezygnuje")
    {
        if (plays[obj.uid])
        {
            plays[obj.uid] = false;
            return -1;
        }
        return 0;
    }
    else
        return 0;
}

void Init()
{
    scanf("%d", &n);
    msgs.resize(n + 10);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &msgs[i].uid);
        cin >> msgs[i].w;
        res += Answ(msgs[i]);
    }
}

void Solve()
{
    if (res >= 10)
        printf("Gramy! Bedzie nas %d\n", res);
    else
        printf("Nie gramy :( Jest nas tylko %d\n", res < 0 ? 0 : res);
}

int main()
{
    Init();
    Solve();

    return 0;
}
