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
	double increse[maxn];//���increse���±������Ǵ�����0���Ǵ���û�ж�������ȻҲ����0.0
	for (size_t i = 0; i < n; i++)increse[i] = INF;
	increse[0] = 0.0;
	for (size_t i = 0; i < n; i++)
	{
		int L = 0, R = i + 1;//RӦ����+1�ģ���ΪR������Ǹ�������ö�ٵ� iʱ��֮ǰ�Ѿ���i������Ū�õģ���r��i+1��
		while (L<R - 1)//�������L��Rֱ����������������Ԫ�أ�R�ǲ����ܵģ�
		{
			int temp = L + (R - L) / 2;
			//			if (line[temp] < line[i])//���ܵ���
			if (increse[temp] < p[i])//����ԭ��д���ˣ������ԣ�Ӧ���ö����������ǰ��ֵ�Ƚ�
				L = temp;
			else
				R = temp;
		}
		increse[L + 1] = min(increse[L + 1], p[i]);
		result[i] = L + 1;//LIS��ÿ���ַ�λ�ü�¼�����λ��Ϊ�ص���ĵ������У�increaseֻ���������ֶ���
	}
	return 0;
}

int solve()
{
	int increse[maxn];
	LIS(increse);
	invert(p, n);//reverse ���÷��� sort��һ��������Ĳ����Ǹ�����������ĩβ��ַ
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

	for (size_t i = 0; i < n - 1; i++)//Ҫ��1����Ϊ��������������
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