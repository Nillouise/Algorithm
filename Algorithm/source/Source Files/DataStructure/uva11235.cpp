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
		for (int j = 1; (1 << j) <= cnt.size(); j++)//�������ֻ����һ�룬��Ϊ�����ѯ��ʱ����������һ�����������������
		{
			//			for (int i = 0; i < cnt.size(); i++)
			for (int i = 0; i + (1 << j) - 1<cnt.size(); i++)//1<<j������Ǹ�����Ҫ-1���Ǵ������ꡣ
			{
				d[i][j] = max(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
			}
		}
	}
	int query(int L, int R)
	{
		int j = 0;
		while ((1 << (j + 1) <= R - L + 1))j++;//j������Ǹ�����R-L+1�����Ҳ�Ǹ�����jֻ��Ҫǡ��һ���R-L+1 �ĸ�������
		return max(d[L][j], d[R - (1 << j) + 1][j]);
	}

};

RMQ rmq;

int main() {
	freopen("input.txt", "r", stdin);
	while (scanf("%d%d", &n, &q) == 2)
	{
		for (size_t i = 0; i < n; i++)scanf("%d", &a[i]);
		a[n] = a[n - 1] + 1;//��������������һ���Ѿ�����ˡ�

		int start = 0;
		vector<int> count;
		for (int i = 0; i <= n; i++)
		{
			if (i == 0 || a[i]>a[i - 1])//����������Ǳ��һ�εĿ�ʼ
			{
				if (i > 0)//��i==0ʱ�������Բ���һ�εĽ��������Բ���ִ����һ�εĽ�������
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
			scanf("%d%d", &L, &R); L--; R--;//���껯��Ϊ0��ʼ����
			int ans = 0;
			if (num[L] == num[R])//����ͬһ�ε����
			{
				printf("%d\n", R - L + 1);
			}
			else {
				//				ans = max(ans, rmq.query(num[L] + 1, num[R]-1));//���ǲ��еģ���Ϊrmq��ѯ�Ķ���һ���εġ�
				ans = max(right[L] - L + 1, R - left[R] + 1);//����ֻ�������ε����
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
