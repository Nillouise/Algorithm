//一开始就没想对了
//结构体要在定义了后才能用，这个和全局变量可能会产生冲突。
//没有留意到坐标x可以是负数。
//搞了一个下午，仍没弄清哪里错了，跟别人答案思路几乎是复刻的，能拿到的样例数据都是对的，结果还是wa。
//所以现在要科学地放弃这道题目，更科学的做法是，两小时前放弃这道题目。
//最后结论是，按y坐标排序会比较好
#include<iostream>
#include<algorithm>
#include<fstream>
#include<cmath>
using namespace std;
const int INF = 1000000;
int n, d;
struct qujian
{
	double b, e;
	bool operator <(const qujian &t)const {
		return b < t.b;
	}
}line[1005];

int main()
{
	int T = 0;
	freopen("input.txt", "r", stdin);
	while (true)
	{
		cin >> n >> d;
		if (n == 0 && d == 0)break;
		int flag = 1;
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			qujian cur;
			cur.b = x - (double)sqrt((double)d*d - (double)y*y);
			cur.e = x + (double)sqrt((double)d*d - (double)y*y);
			line[i] = cur;
			if (abs(y) > d)flag = 0;
		}
		if (!flag) { cout << "Case " << ++T << ": " << -1 << endl; continue; }
		sort(line, line + n);
		int cnt = 1;
		int left = line[0].b, right = line[0].e;
		for (size_t i = 1; i < n; i++)
		{
			//			if (line[i].b>left) //这是没有考虑边界的结果
			//			{
			if (line[i].b > right)
			{
				cnt++;
				right = line[i].e;
			}
			else {
				if (line[i].e < right)
					right = line[i].e;
			}

			//			}
		}
		cout << "Case " << ++T << ": " << cnt << endl;


	}

	return 0;
}
