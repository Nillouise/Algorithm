//һ��ʼ��û�����
//�ṹ��Ҫ�ڶ����˺�����ã������ȫ�ֱ������ܻ������ͻ��
//û�����⵽����x�����Ǹ�����
//����һ�����磬��ûŪ��������ˣ������˴�˼·�����Ǹ��̵ģ����õ����������ݶ��ǶԵģ��������wa��
//��������Ҫ��ѧ�ط��������Ŀ������ѧ�������ǣ���Сʱǰ���������Ŀ��
//�������ǣ���y���������ȽϺ�
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
