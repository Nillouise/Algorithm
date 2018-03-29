//这题被字面值 不是long long坑死了
#include <iostream>
#include<vector>
#include<string>
#include<cstring>
#include <algorithm>
using namespace std;


int main()
{
	//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);

	unsigned long long n, k;
	cin >> n >> k;
	if (k == 1)
	{
		cout << n << endl;
	}
	else if (k == 0)
	{
		cout << "0" << endl;
	}
	else
	{
		unsigned long long t = 0;
		for (int i = 0; i<64; i++)
		{
			if (n&(1LL << i))
				t = 1LL << i;
		}
		//		t = (t << 1) - 1;
		t = t + (t - 1);
		cout << t;
	}

	return 0;
}
