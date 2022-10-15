#include <bits/stdc++.h>

#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_back

using namespace std;

typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;
typedef pair <int, int> p_i;
typedef pair <s64, s64> p_ll;
typedef vector <int> v_i;
typedef vector <s64> v_ll;

s32 T, N, board[3000][3000], perms[1000][3];

void Init()
{
    cin >> N;
    memset(board, 0, sizeof board);
    int val = 0;
    for (int i = 0; i < 1000; ++i)
        for (int j = 0; j < 3; ++j)
            perms[i][j] = val++;
}

void Sub1()
{
    for (s32 i = 9; i >= 0; --i)
    {
        for (s32 j = 0; j < 10; ++j)
        {
            if (i == 9 && !j)
            {
                board[i][j] = 0;
                continue;
            }

            set <int> arr;
            for (int z = 0; z <= 20; ++z)
                arr.insert(z);

            for (int x = 0; x < j; ++x)
                arr.erase(board[i][x]);
            for (int y = 9; y > i; --y)
                arr.erase(board[y][j]);
            if (i < 9 && j)
                arr.erase(board[i + 1][j - 1]);
            board[i][j] = *arr.begin();
        }
    }

    for (s32 i = 0; i < 10; ++i)
    {
        for (s32 j = 0; j < 10; ++j)
            cout << board[i][j] << setw(4);
        cout << '\n';
    }
}

void FindNodes()
{
}

void Solve()
{
    cin >> T;
    for (s32 qr = 0; qr < T; ++qr)
    {
        Init();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}

