//һ��ʼ��û�����
//�ṹ��Ҫ�ڶ����˺�����ã������ȫ�ֱ������ܻ������ͻ��
//û�����⵽����x�����Ǹ�����
//����һ�����磬��ûŪ��������ˣ������˴�˼·�����Ǹ��̵ģ����õ����������ݶ��ǶԵģ��������wa��
//��������Ҫ��ѧ�ط��������Ŀ������ѧ�������ǣ���Сʱǰ���������Ŀ��
//�������ǣ���y���������ȽϺ�

//���debug�˳��õ�ԭ����Ҫ����Ϊ�ң�������int left = p[0].b, right = p[0].e; Ӧ��ʹdouble����Ϊ������䱾������ʵ����
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
			//			int left = p[0].b, right = p[0].e;//���д��������debug�˳��õĴ�����
			double left = p[0].b, right = p[0].e;
			for (int i = 1; i < n; i++)
			{
				//			if (line[i].b>left) //����û�п��Ǳ߽�Ľ��
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
