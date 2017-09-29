#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;
typedef long long LL;
int gcd(int a, int b)
{
	if (a == 0)return b;
	return gcd(b%a, a);
}

int main()
{
	//freopen("stdin.txt", "r", stdin);
	LL n, k;
	cin >> n >> k;
	//所有人都没房住的情况没考虑
	cout << ((n - k > 0 && k != 0) ? 1 : 0) << " ";
	if (n > 3 * k)
	{
		cout << 2 * k << endl;
	}
	else {
		cout << n - k << endl;
	}



	return 0;
}