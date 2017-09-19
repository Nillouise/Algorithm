#include<cmath>
#include <cstring>
#include <algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

LL gcd(LL a, LL b)
{
	if (a == 0)return b;
	return gcd(b%a, a);
}

int main()
{
	ios::sync_with_stdio(false);

	long long n, k;
	cin >> n >> k;

	LL r = pow(10, k);
	LL kr = n*r / gcd(n, r);

	cout << kr << endl;
	return 0;
}