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

s32 t, n;
string boxes;
v_i arr;

void Init()
{
    cin >> n >> boxes;
    arr.resize(n);
    for (s32 &i : arr)
        cin >> i;
}

void Solve()

{
    cin >> t;
    for (s32 qr = 0; qr < t; ++qr)
    {
        Init();
        for (s32 i = 1; i < n; ++i)
        {
            if (!(boxes[i - 1] - '0') && (boxes[i] - '0'))
            {
                s32 x = i - 1;
                if (arr[i - 1] > arr[i])
                    swap(boxes[i - 1], boxes[i]);
                else
                {
                    while ((boxes[i] - '0') && arr[i] >= x && i < (n - 1))
                        ++i;
                    if (arr[i] < arr[x] && (boxes[i] - '0'))
                        swap(boxes[x], boxes[i]);
                }
            }
        }
        s32 res = 0;
        for (s32 i = 0; i < n; ++i)
            res += (boxes[i] - '0') * arr[i];
        cout << res << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}

