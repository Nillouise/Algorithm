//一开始就没想对了
//结构体要在定义了后才能用，这个和全局变量可能会产生冲突。
//没有留意到坐标x可以是负数。
//搞了一个下午，仍没弄清哪里错了，跟别人答案思路几乎是复刻的，能拿到的样例数据都是对的，结果还是wa。
//所以现在要科学地放弃这道题目，更科学的做法是，两小时前放弃这道题目。
//最后结论是，按y坐标排序会比较好

//这次debug了超久的原因，主要是因为我，忘记了int left = p[0].b, right = p[0].e; 应该使double，因为这个区间本来就是实数的
#include <iostream>  
#include <algorithm>  
#include <stdlib.h>  
#include <math.h>
using namespace std;
struct qujian
{
	double b, e;
	//bool operator <(const qujian &t){
	//	return b < t.b;
	//}
}p[2010];
bool operator < (qujian a, qujian b)
{
	return a.b < b.b;
}


int main()
{
	int n;
	double d;
	int T = 0;
	freopen("input.txt", "r", stdin);
	while (cin >> n >> d && (n || d))
	{
		//cin >> n >> d;
		//if (n == 0 && d == 0)break;
		int flag = 1;
		for (int i = 0; i < n; i++)
		{
			//			int x, y;
			double x, y;
			cin >> x >> y;
			qujian cur;
			//cur.b = x*1.0 - (double)sqrt((double)d*d - (double)y*y);
			//cur.e = x*1.0 + (double)sqrt((double)d*d - (double)y*y);
			//p[i] = cur;
			p[i].b = x * 1.0 - sqrt(d * d - y * y);
			p[i].e = x * 1.0 + sqrt(d * d - y * y);

			if (fabs(y) > d)flag = 0;
		}
		cout << "Case " << ++T << ": ";
		if (!flag)
		{
			cout << -1 << endl;
		}
		else {
			int cnt = 1;
			sort(p, p + n);
			//			int left = p[0].b, right = p[0].e;//这行代码就是我debug了超久的代码了
			double left = p[0].b, right = p[0].e;
			for (int i = 1; i < n; i++)
			{
				//			if (line[i].b>left) //这是没有考虑边界的结果
				//			{
				if (p[i].b > right)
				{
					cnt++;
					right = p[i].e;
				}
				else {
					if (p[i].e < right)
						right = p[i].e;
				}

				//			}
			}
			cout << cnt << endl;
		}

	}

	return 0;
}
