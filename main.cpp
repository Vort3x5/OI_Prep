#include <bits/stdc++.h>
using namespace std;

int n;
vector <char> cars;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	cars.resize(n - 1);
	for(int i = 0; i < n - 1; ++i)
		cin >> cars[i];

	return 0;
}