#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

string w;
int res1, res2 = 1;

void Init()
{
    cin >> w;
}

bool IsVowel(char l) { return (l == 'A' || l == 'E' || l == 'I' || l == 'O' || l == 'U' || l == 'Y'); }

void Solve()
{
    bool prev = IsVowel(w[0]);
    for (int i = 1; i < w.size(); ++i)
    {
        if (prev && IsVowel(w[i]))
        {
            prev = false;
            ++res1;
        }
        else if (!prev && !IsVowel(w[i]))
        {
            prev = true;
            ++res1;
        }
        else
            prev = IsVowel(w[i]);
    }
    prev = !IsVowel(w[0]);
    for (int i = 1; i < w.size(); ++i)
    {
        if (prev && IsVowel(w[i]))
        {
            prev = false;
            ++res2;
        }
        else if (!prev && !IsVowel(w[i]))
        {
            prev = true;
            ++res2;
        }
        else
            prev = IsVowel(w[i]);
    }
    printf("%d\n", min(res1, res2));
}

int main()
{
    Init();
    Solve();

    return 0;
}
