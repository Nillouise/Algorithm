#include <iostream>
#include <cstdio>
#include <cstring>
#include<string>
#include <algorithm>
#include<sstream>
#include<cmath>//这里有log 函数
using namespace std;
const int maxn = 200;
const double INF = 1000000.0;
double G[maxn][maxn];
int n;

struct Point
{
	double x, y;
	Point(double x = 0, double y = 0) :x(x), y(y) {}
	Point operator -(const Point&p)
	{
		return Point(x - p.x, y - p.y);
	}
};

double cross(Point a, Point b)
{
	return a.x*b.y - a.y*b.x;
}

int dcmp(double x)
{
	if (abs(x) < 1e-3)return 0;
	return x < 0 ? -1 : 1;
}

void intersect(Point ha, Point hb, Point va, Point vb, double &rx, double &ry)//这里忘记用引用传递
{
	double area1 = cross(hb - ha, va - ha);
	double area2 = cross(hb - ha, vb - ha);
	if (dcmp(area1)*dcmp(area2) == -1)//这里写错了，应该用dcmp化精度
	{
		rx = (area1*vb.x - area2*va.x) / (area1 - area2);
		ry = (area1*vb.y - area2*va.y) / (area1 - area2);
	}
	else {
		if (dcmp(area1) == 0)
		{
			rx = va.x;
			ry = va.y;
		}
		else {
			rx = vb.x;
			ry = vb.y;
		}
	}
}

double calrect(Point a, Point b, Point c, Point d)
{
	double angle1 = cross(c - a, b - a);//矩形内对角线的两个三角形
	double angle2 = cross(c - a, d - a);
	//	return abs(angle1) + abs(angle2);//记得取绝对值，但忘记除以2
	return 0.5*(abs(angle1) + abs(angle2));
}



int main() {
	freopen("input.txt", "r", stdin);

	int n;
	while (cin >> n&&n != 0)
	{
		Point a[35], b[35], c[35], d[35];
		a[0].x = 0; a[0].y = 0; a[n + 1].x = 1, a[n + 1].y = 0;
		for (size_t i = 1; i <= n; i++)
		{
			cin >> a[i].x;
			a[i].y = 0;
		}
		b[0].x = 0; b[0].y = 1; b[n + 1].x = 1, b[n + 1].y = 1;
		for (size_t i = 1; i <= n; i++)
		{
			cin >> b[i].x;
			b[i].y = 1;
		}
		c[0].x = 0; c[0].y = 0; c[n + 1].x = 0; c[n + 1].y = 1;
		for (size_t i = 1; i <= n; i++)
		{
			cin >> c[i].y;
			c[i].x = 0;
		}
		d[0].x = 1; d[0].y = 0; d[n + 1].x = 1; d[n + 1].y = 1;
		for (size_t i = 1; i <= n; i++)
		{
			cin >> d[i].y;
			d[i].x = 1;
		}
		double maxrect = 0;
		for (size_t i = 1; i < n + 2; i++)
		{
			for (size_t j = 1; j < n + 2; j++)
			{
				double r[4][2];
				for (int f = 0; f < 4; f++)
				{
					intersect(d[i - f % 2], c[i - f % 2], b[j - f / 2], a[j - f / 2], r[f][0], r[f][1]);//这个循环不是逆时针的，而是 上下上下这样的，需要转换
				}
				//下面这么写还是太蠢了，应该在calrect那里改
				{
					double x = r[2][0], y = r[2][1];
					r[2][0] = r[3][0]; r[2][1] = r[3][1];
					r[3][0] = x; r[3][1] = y;
				}

				//				double rect = calrect(Point(r[0][1], r[0][1]), Point(r[1][1], r[1][1]), Point(r[2][1], r[2][1]), Point(r[3][1], r[3][1]));//错的真离谱
				double rect = calrect(Point(r[0][0], r[0][1]), Point(r[1][0], r[1][1]), Point(r[2][0], r[2][1]), Point(r[3][0], r[3][1]));

				maxrect = max(rect, maxrect);
			}
		}
		printf("%0.6lf\n", maxrect);

	}

}