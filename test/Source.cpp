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

int check(Point A,Point B,Point C,Point D)
{
	double area1 = cross(B - A, C - A);
	double area2 = cross(B - A, D - A);

	return dcmp(area1)*dcmp(area2)<=0;//=0就代表不规范相交
}

double segcross(Point A, Point B, Point C, Point D)
{
	double area1 = cross(B - A, C - A);
	double area2 = cross(B - A, D - A);

	if (dcmp(area1)*dcmp(area2) < 0)
	{
		//我又写错变量
		//	double px = (C.x*area1 - D.x*area2) / (area1 - area2);
		double px = (C.x*area2 - D.x*area1) / (area2 - area1);
		return px;
	}

	//这个if是处理不规范相交的情况,一定要用dcmp 判断是否面积为0
	if (dcmp(area1 )== 0)
	{
		return C.x;
	}
	else if(dcmp(area2)==0)
	{
		return D.x;
	}


	return -INF;

}

int main() {
	freopen("input.txt", "r", stdin);



	}


	return 0;
}