//http://www.2cto.com/kf/201308/232597.html
//http://qscoj.cn/problem/163/
//求质因子和 欧拉函数的应用

#include<iostream>
#include<list>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--)
	{
		long long N;
		cin >> N;
		long long ans = N;
		long long phi = N;
		// 这里的N在没一个循环都会变得，当一个数含有两个以上的因子时，总有一个是<=sqrt(N)的
		//但当剩下一个质数时，这里不能处理好，所以需要在下面用if语句处理，
		for (long long i = 2; i <= sqrt(N); i++)
		{
			if (N%i == 0)
			{
				phi = phi / i*(i - 1);
				while (N%i == 0)N /= i;
			}
		}
		if (N>1) phi = phi / N *(N - 1);

		ans = phi / 2 * ans;//phi是有多少个数与N互质，这些互质的数总是成对出现（一对数想加就等于N），所以就需要这样处理就可以了
		cout << ans << endl;
	}

	return 0;
}