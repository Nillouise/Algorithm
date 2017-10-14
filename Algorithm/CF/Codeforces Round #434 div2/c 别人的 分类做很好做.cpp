#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>//这个sqrt要用
#include<queue>
using namespace std;

int main()
{
	int n, s;
	cin >> n >> s;
	long long p = 0, q = 0, d = 0;
	vector<pair<long long, long long> >v, w;
	for (int i = 0; i<n; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (b>c) {
			p += a*b;
			q += a;
			q %= s;
			v.push_back({ b - c, a });
		}
		else {
			p += a*c;
			d += a;
			d %= s;
			w.push_back({ c - b, a });
		}
	}
	if (q + d>s) {
		cout << p;

		return 0;
	}
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());

	long long x = 0, y = 0;
	for (pair<long long, long long> i : v) {
		x += min(i.second, q)*i.first;
		q -= min(i.second, q);
	}
	for (pair<long long, long long> i : w) {
		y += min(i.second, d)*i.first;
		d -= min(i.second, d);
	}
	cout << p - min(x, y);
	return 0;
}