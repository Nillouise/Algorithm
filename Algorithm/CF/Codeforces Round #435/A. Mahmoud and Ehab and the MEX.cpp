#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	int n, x;
	cin >> n >> x;

	vector<int> v;
	for (size_t i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		v.push_back(c);
	}
	sort(v.begin(), v.end());

	int index = lower_bound(v.begin(), v.end(), x) - v.begin();

	int ans = x - index + (v[index] == x ? 1 : 0);

	cout << ans << endl;

	return 0;
}