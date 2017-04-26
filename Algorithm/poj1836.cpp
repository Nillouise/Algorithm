#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<stack>
#include<set>
#include<functional>
#include<map>
#include<queue>
using namespace std;
const int maxn = 1000 + 5;
double p[maxn];
int n;
const double INF = 11000000;

int invert(int *a, int n)
{
	int i = 0;
	while (i<n)
	{
		int temp = a[i];
		a[i] = a[n - 1];
		a[n - 1] = temp;

		i++; n--;
	}
	return 0;
}

int invert(double *a, int n)
{
	int i = 0;
	while (i<n)
	{
		double temp = a[i];
		a[i] = a[n - 1];
		a[n - 1] = temp;

		i++; n--;
	}
	return 0;
}

int LIS(int  *result)
{
	double increse[maxn];//这个increse的下标代表的是次数，0次是代表没有东西，自然也就是0.0
	for (size_t i = 0; i < n; i++)increse[i] = INF;
	increse[0] = 0.0;
	for (size_t i = 0; i < n; i++)
	{
		int L = 0, R = i + 1;//R应该是+1的，因为R代表的是个数，当枚举到 i时，之前已经有i个东西弄好的，而r是i+1；
		while (L<R - 1)//这里代表L和R直接起码有两个可能元素（R是不可能的）
		{
			int temp = L + (R - L) / 2;
			//			if (line[temp] < line[i])//不能等于
			if (increse[temp] < p[i])//这里原本写错了，很明显，应该用二分数组跟当前的值比较
				L = temp;
			else
				R = temp;
		}
		increse[L + 1] = min(increse[L + 1], p[i]);
		result[i] = L + 1;//LIS在每个字符位置记录以这个位置为重点最长的递增序列，increase只是拿来二分而已
	}
	return 0;
}

int solve()
{
	int increse[maxn];
	LIS(increse);
	invert(p, n);//reverse 的用法跟 sort不一样，后面的参数是个数不是数组末尾地址
	int decrese[maxn];
	LIS(decrese);
	invert(decrese, n);
	int MAX = 0;
	for (size_t i = 1; i < n; i++)
	{
		increse[i] = max(increse[i], increse[i - 1]);
	}
	for (int i = n - 2; i >= 0; i--)
	{
		decrese[i] = max(decrese[i], decrese[i + 1]);
	}

	for (size_t i = 0; i < n - 1; i++)//要减1，因为中轴是有两个的
	{
		MAX = max(increse[i] + decrese[i + 1], MAX);
	}
	return n - MAX;
}

int main()
{
	freopen("input.txt", "r", stdin);

	while (cin >> n)
	{
		for (size_t i = 0; i < n; i++)
		{
			cin >> p[i];
		}
		cout << solve() << endl;

	}



	return 0;
}