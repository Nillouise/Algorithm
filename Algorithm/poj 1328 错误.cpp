//һ��ʼ��û�����
//�ṹ��Ҫ�ڶ����˺�����ã������ȫ�ֱ������ܻ������ͻ��
//û�����⵽����x�����Ǹ�����
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
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
}line[10000];

int main()
{
	freopen("input.txt", "r", stdin);
	int T = 0;
	while (cin >> n >> d&& n != 0)
	{
		int flag = 1;
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			qujian cur;
			cur.b = x - (double)sqrt(d*d - y*y);
			cur.e = x + (double)sqrt(d*d - y*y);
			line[i] = cur;
			if (abs(y) > d)flag = 0;
		}
		if (!flag) { cout << "Case " << ++T << ": " << -1 << endl; continue; }
		sort(line, line + n);
		int cnt = 1;
		int left = line[0].b, right = line[0].e;
		for (size_t i = 1; i < n; i++)
		{
			//			if (line[i].b>left) //����û�п��Ǳ߽�Ľ��
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
