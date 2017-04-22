#include <iostream>
#include <cstdio>
#include <cstring>
#include<string>
#include <algorithm>
#include<sstream>
#include<cmath>//������log ����
using namespace std;
const int maxn = 200;
const double INF = 1000000.0;
double G[maxn][maxn];
int n;

struct Point
{
	double x, y;
	Point(double x = 0, double y = 0) :x(x), y(y) {}

	Point operator - (const Point &B)
	{
		return Point(x - B.x, y - B.y);
	}
};
typedef Point Vector;
double cross(Vector w, Vector v)
{
	return w.x*v.y - w.y*v.x;
}
const double eps = 1e-3;
int dcmp(double d)
{
	if (fabs(d) < eps)return 0;
	return d < 0 ? -1 : 1;
}

int check(Point A, Point B, Point C, Point D)
{
	double area1 = cross(B - A, C - A);
	double area2 = cross(B - A, D - A);

	return dcmp(area1)*dcmp(area2) <= 0;//=0�ʹ����淶�ཻ
}

double segcross(Point A, Point B, Point C, Point D)
{
	double area1 = cross(B - A, C - A);
	double area2 = cross(B - A, D - A);

	if (dcmp(area1)*dcmp(area2) < 0)
	{
		//����д�����
		//	double px = (C.x*area1 - D.x*area2) / (area1 - area2);
		double px = (C.x*area2 - D.x*area1) / (area2 - area1);
		return px;
	}

	//���if�Ǵ����淶�ཻ�����,һ��Ҫ��dcmp �ж��Ƿ����Ϊ0
	if (dcmp(area1) == 0)
	{
		return C.x;
	}
	else if (dcmp(area2) == 0)
	{
		return D.x;
	}


	return -INF;

}

int main() {
	freopen("input.txt", "r", stdin);

	while (cin >> n&&n != 0)
	{
		Point pUp[30];
		Point pDown[30];
		for (size_t i = 0; i < n; i++)
		{
			double x, y;
			cin >> x >> y;
			pUp[i] = Point(x, y);
			pDown[i] = Point(x, y - 1);
		}

		double maxX = -INF;
		int flag = 0;
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				if (i == j)continue;//i==jʱ���Ǵ�ֱ�ߣ����ܴ���ڽ���
				int collide = 0;
				size_t k;
				for (k = 0; k < n; k++)
				{
					//					if (check(pUp[i], pDown[j], pUp[k], pUp[k - 1]) ==1)//���Ǵ�ģ��ұȽϵ�����û�д���ǽ�ڣ���������׾ͻ����ƽ���ߣ������ǹ�������ǽ�����ɵģ�
					if (!check(pUp[i], pDown[j], pUp[k], pDown[k]))//��ֻ��û���� ǽ�ڿڵĴ�ֱ�߶��ѣ�����֪����ײ����ǽ�ڻ�����ǽ�ڡ�
					{
						collide = 1;
						//���������︳����ֵ����Ϊ��ȱ�˱�Ҫ������
						//double x1 = segcross(pUp[i], pDown[j], pUp[k], pDown[k]);
						//maxX = max(x1, maxX);
						//x1 = segcross(pUp[i], pDown[j], pUp[k], pDown[k]);
						//maxX = max(x1, maxX);
						break;
					}
					//					if (check(pUp[i], pDown[j], pDown[k], pDown[k - 1]) == 1)
					//					if (!check(pUp[i], pDown[j], pUp[k], pDown[k]) )
					//					{
					//						collide = 1;
					//						//�������ڸ������ʱ���������˰ѱ�����ȷ�ĵ�
					////						double x1 = segcross(pUp[i], pDown[j], pDown[k], pDown[k - 1]);
					//						double x1 = segcross(pUp[i], pDown[j], pUp[k], pDown[k]);
					//						maxX = max(x1, maxX);
					//						break;
					//					}
				}
				if (collide == 0)
				{
					flag = 1;
					break;
				}
				//�����������±�Ҫ�ģ���Ϊȷ������ôһ�����󣬹��߼Ȳ��ᴩ����ֱǽ�ڣ�Ҳû����ǽ��
				if (k > max(i, j))
				{
					double temp = segcross(pUp[i], pDown[j], pUp[k], pUp[k - 1]);
					if (maxX < temp)  //L���k-1�ڹ��ӵ��Ϲܱ��ཻ  
						maxX = temp;

					temp = segcross(pUp[i], pDown[j], pDown[k], pDown[k - 1]);
					if (maxX < temp)  //L���k-1�ڹ��ӵ��Ϲܱ��ཻ  
						maxX = temp;
				}


			}
			if (flag)break;
		}
		if (flag) { cout << "Through all the pipe." << endl; }
		else {
			printf("%.2lf\n", maxX);
		}

	}


	return 0;
}