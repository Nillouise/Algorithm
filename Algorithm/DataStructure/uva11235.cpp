#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 100000 + 5;
const int maxlog = 20;

int a[maxn], num[maxn], left[maxn], right[maxn];
int n, q;
struct RMQ
{
	int d[maxn][maxlog];
	void init(vector<int> cnt)
	{
		for (size_t i = 0; i < cnt.size(); i++) d[i][0] = cnt[i];

		//		for (int j = 1; ((1<<(j-1))-1) < cnt.size(); j++)
		for (int j = 1; (1 << j) <= cnt.size(); j++)//这里可以只覆盖一半，因为后面查询的时候，是用两个一半来覆盖整个区域的
		{
			//			for (int i = 0; i < cnt.size(); i++)
			for (int i = 0; i + (1 << j) - 1<cnt.size(); i++)//1<<j代表的是个数，要-1才是代表坐标。
			{
				d[i][j] = max(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
			}
		}
	}
	int query(int L, int R)
	{
		int j = 0;
		while ((1 << (j + 1) <= R - L + 1))j++;//j代表的是个数，R-L+1代表的也是个数，j只需要恰好一半的R-L+1 的个数即可
		return max(d[L][j], d[R - (1 << j) + 1][j]);
	}

};

RMQ rmq;

int main() {
	freopen("input.txt", "r", stdin);
	while (scanf("%d%d", &n, &q) == 2)
	{
		for (size_t i = 0; i < n; i++)scanf("%d", &a[i]);
		a[n] = a[n - 1] + 1;//这是用来标记最后一段已经完结了。

		int start = 0;
		vector<int> count;
		for (int i = 0; i <= n; i++)
		{
			if (i == 0 || a[i]>a[i - 1])//这里的作用是标记一段的开始
			{
				if (i > 0)//当i==0时，很明显不是一段的结束，所以不用执行上一段的结束代码
				{
					count.push_back(i - start);
					for (int j = start; j < i; j++)
					{
						num[j] = count.size() - 1;
						left[j] = start;
						right[j] = i - 1;
					}
				}
				start = i;
			}
		}
		rmq.init(count);
		while (q--)
		{
			int L, R;
			scanf("%d%d", &L, &R); L--; R--;//坐标化成为0开始才行
			int ans = 0;
			if (num[L] == num[R])//这是同一段的情况
			{
				printf("%d\n", R - L + 1);
			}
			else {
				//				ans = max(ans, rmq.query(num[L] + 1, num[R]-1));//这是不行的，因为rmq查询的都是一整段的。
				ans = max(right[L] - L + 1, R - left[R] + 1);//这是只跨了两段的情况
				if (num[L] + 1 == num[R])
					printf("%d\n", ans);
				else {
					ans = max(ans, rmq.query(num[L] + 1, num[R] - 1));
					printf("%d\n", ans);
				}
			}
		}




	}

	return 0;
}
