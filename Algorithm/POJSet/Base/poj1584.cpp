//这题要封闭多边形，因为是一个环。

#include <iostream>
#include <cstdio>
#include <cstring>
#include<string>
#include <algorithm>
#include<sstream>
#include<cmath>
using namespace std;
const int maxn = 200;
const double INF = 1000000.0;
double G[maxn][maxn];

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


int isInPoly(Point cent, Point *poly, int n)
{
	int wn = 0;
	for (size_t i = 0; i < n - 1; i++)
	{
		int direct = dcmp(cross(poly[i] - cent, poly[i + 1] - poly[i]));
		int d0 = dcmp(poly[i].y - cent.y);
		int d1 = dcmp(poly[i + 1].y - cent.y);
		//点在多边形内时，应该只有1而已，这里指挥加一次，因为有一次y轴是小于，转到另一边的时候，就是大于了
		if (d1 > 0 && d0 <= 0 && direct > 0)wn++;
		if (d0 > 0 && d1 <= 0 && direct < 0)wn--;

	}
	if (wn != 0)return 1;
	return 0;

}

double lineLen(Point p)
{
	return sqrt(p.x*p.x + p.y*p.y);
}

int main() {
	freopen("input.txt", "r", stdin);

	int vertices;
	while (cin >> vertices&&vertices >= 3)
	{
		Point circle;
		double radius;
		//		cin >> circle.x >> circle.y >> radius;//输入数据我又没有认真看搞错了
		cin >> radius >> circle.x >> circle.y;
		Point poly[100];
		for (size_t i = 0; i < vertices; i++)
		{
			cin >> poly[i].x >> poly[i].y;
		}
		//封闭掉多边形环
		poly[vertices].x = poly[0].x;
		poly[vertices].y = poly[0].y;
		int flag = 0;
		for (size_t i = 1; i < vertices - 1; i++)//注意这个-1 是精髓，因为下面是+2的
		{
			int wirl1 = dcmp(cross(poly[i + 1] - poly[i], poly[i] - poly[i - 1]));
			int wirl2 = dcmp(cross(poly[i + 2] - poly[i + 1], poly[i + 1] - poly[i]));

			//			if (wirl1 != wirl2)//不能这么写，因为有可能三点共线
			if (wirl1*wirl2<0)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			cout << "HOLE IS ILL-FORMED" << endl;
			continue;
		}
		if (!isInPoly(circle, poly, vertices + 1))
		{
			cout << "PEG WILL NOT FIT" << endl;
			continue;
		}

		for (size_t i = 0; i < vertices; i++)
		{
			double area = cross(poly[i + 1] - poly[i], poly[i] - circle);
			double dist = abs(area) / lineLen(poly[i + 1] - poly[i]);

			if (dist < radius)
			{
				cout << "PEG WILL NOT FIT" << endl;
				flag = 1;
				break;
			}
		}
		if (!flag)
			cout << "PEG WILL FIT" << endl;
	}


}