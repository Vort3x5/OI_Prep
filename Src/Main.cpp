#include <bits/stdc++.h>

using namespace std;

int n, sz_up, sz_down;

vector <pair <int, int>> arr, res_up, res_down;

void Init()
{
	cin >> n;
	arr.resize(n);
	res_up.resize(n);
	res_down.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i].first >> arr[i].second;
}

void Solve()
{
	sort(arr.begin(), arr.end());
	res_up[0] = arr[0];
	res_up[1] = arr[1];
    sz_up = 2;
	for (int i = 2; i < n; ++i)
	{
		res_up[sz_up++] = arr[i];
		while (sz_up > 2)
		{
			pair <int, int> a = res_up[sz_up - 3], c = res_up[sz_up - 1];
			a.first -= res_up[sz_up - 2].first, a.second -= res_up[sz_up - 2].second;
			c.first -= res_up[sz_up - 2].first, c.second -= res_up[sz_up - 2].second;
			if (a.first * c.second - a.second * c.first < 0)
                res_up[sz_up - 2] = res_up[sz_up - 1], --sz_up; 
            else
                break;
		}
	}
	for (int i = 0; i < sz_up; ++i)
		cout << res_up[i].first << ' ' << res_up[i].second << '\n';
    res_down[0] = arr[n - 1];
    res_down[1] = res_up[sz_up - 1];
    sz_down = 2;
	for (int i = n - 1; i > 1; --i)
	{
		res_down[sz_down++] = arr[i];
		while (sz_down > 2)
		{
			pair <int, int> a = res_down[sz_down - 3], c = res_down[sz_down - 1];
			a.first -= res_down[sz_down - 2].first, a.second -= res_down[sz_down - 2].second;
			c.first -= res_down[sz_down - 2].first, c.second -= res_down[sz_down - 2].second;
			if (a.first * c.second - a.second * c.first < 0)
				res_down[sz_down - 2] = res_down[sz_down - 1], --sz_down;
            else
                break;
		}
	}
	for (int i = 1; i < sz_down - 1; ++i)
		cout << res_down[i].first << ' ' << res_down[i].second << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

	Init();
	Solve();

	return 0;
}
