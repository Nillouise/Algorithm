//贪心错误

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int comb(int C, int i)
{

}

int deduct(long long num, int index, int zeros)
{
	int cnt = 0;
	int i;
	for (i = index - 1; i >= 0; i--)
	{
		if (num&(1 << i))
		{
			break;
		}
		cnt++;
	}
	return deduct(num, i, zeros - cnt) + comb(index, zeros - cnt - 1);

}

int cal(long long num)
{



}


int main() {
	freopen("input.txt", "r", stdin);

	long long a, b;
	while (cin >> a >> b)
	{
		cout << cal(b) - cal(a) << endl;
	}

	return 0;
}