#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

ll N, M;

v_i arr;

void Init()
{
    cin >> N >> M;
    arr.resize(N);
    for (int i = 0; i < N; ++i)
        arr[i] = i + 1;
}

void Insert(int j)
{
    for (int i = j - 1; i < N; ++i)
        ++arr[i];
}

inline ll Qr(int i)
    { return arr[i - 1]; }

void Solve()
{
    for (int q = 0; q < M; ++q)
    {
        char l;
        int num;
        cin >> l >> num;
        switch (l)
        {
            case 'L':
                cout << Qr(num) << '\n';
                break;

            case 'D':
                Insert(num);
                break;
        }
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
