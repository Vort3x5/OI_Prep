#include <bits/stdc++.h>
using namespace std;

string wzorzec, txt, s;

int P[1000010];

int main()
{
    cin >> wzorzec >> txt;
    s = wzorzec + '#' + txt;
    P[0] = -1;
    P[1] = 0;
    int j = P[1];
    for (int i = 1; i < s.size(); ++i)
    {
        while (j != -1 && s[i] != s[j])
            j = P[j];
        ++j;
        P[i + 1] = j;
    }
    for (int i = wzorzec.size(); i <= s.size(); ++i)
        if (P[i] == wzorzec.size())
            cout << i - (2 * wzorzec.size()) << '\n';

    return 0;
}
