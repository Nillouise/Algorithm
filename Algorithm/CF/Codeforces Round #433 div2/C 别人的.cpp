#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
#include<cmath>
#include<bitset>
#include<set>
#include<iomanip>
#include<fstream>
#include<bitset>
#include<cstring>
#include<cstdlib>
#include<complex>
#include<list>
#include<sstream>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, long long> il;
typedef pair<long long, long long> ll;
typedef pair<ll, int> lli;
typedef pair<long long, int> li;
typedef pair<double, double> dd;
typedef pair<ii, int> iii;
typedef pair<double, int> di;
long long mod = 1000000007LL;
long long base = 37;
long long large = 1000000000000000000LL;

int gcd(int x, int y) {
	if (y == 0) return x;
	return gcd(y, x%y);
}

int main() 
{

	int n, k;
	cin >> n >> k;
	vector<int> c(n, 0);
	for (int i = 0; i<n; i++) scanf("%d", &c[i]);
	priority_queue<ii> pq;
	k--;
	long long cost = 0;
	vector<int> g(n, -1);
	for (int i = 0; i<n || (!pq.empty()); i++) {
		if (i<n) pq.push(ii(c[i], i));

		if (i>k) {
			ii re = pq.top();
			pq.pop();
			cost += 1LL * re.first*(i - re.second);
			g[re.second] = i + 1;
		}
	}
	cout << cost << endl;
	for (int i = 0; i<n; i++) cout << g[i] << " ";
	cout << endl;
	return 0;
}