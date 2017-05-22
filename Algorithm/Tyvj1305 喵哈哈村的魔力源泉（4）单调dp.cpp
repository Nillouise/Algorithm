#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

long long a[1000000 + 5];
int main()
{
	freopen("input.txt", "r", stdin);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)//这里是1开头，为什么必须要这样？因为后面的连续和需要用0来表示前面的所有数。
	{
		int t;
		scanf("%lld", &a[i]);//long long 要用lld才行
		a[i] += a[i - 1];
	}
	list<int> q;
	long long MAX = 0;
	q.push_front(0);//这里的作用是避免第一个数一直被减去。
	for (int i = 1; i <= n; i++)
	{
		while (!q.empty() && a[q.front()] >= a[i]) {
			q.pop_front();
		}
		q.push_front(i);//必须在这里pushfront，因为前面都是负数时，就代表啥区间都不要了（i也不要了），以i为结尾的区间和直接不要，填0
		while (!q.empty() && q.back()< i - k)q.pop_back();
		MAX = max(MAX, a[i] - a[q.back()]);

	}
	cout << MAX << endl;

	return 0;
}