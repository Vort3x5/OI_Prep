#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

int k;

void Init()
{
    scanf("%d", &k);
}

void Solve()
{
    if (double(k / 1.609344) < 300)
        printf("NIE");
    else if (double(k / 1.609344) >= 300 && double(k / 1.609344) < 500)
        printf("SPRAWDZIMY TWOJE OBECNE BUTY");
    else
        printf("TAK");
}

int main()
{
    Init();
    Solve();

    return 0;
}
