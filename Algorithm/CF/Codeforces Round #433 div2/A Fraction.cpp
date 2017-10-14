#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;

int gcd(int a, int b)
{
	if (a == 0)return b;
	return gcd(b%a, a);
}

int main()
{
	//freopen("stdin.txt", "r", stdin);
	int n;
	cin >> n;

	for (int i = (n - 1) / 2; i >0; i--)
	{
		if (gcd(i, n - i) == 1)
		{
			cout << i << " " << n - i << endl;
			return 0;
		}
	}



	return 0;
}