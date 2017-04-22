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

int check(Point A, Point B, Point C, Point D)
{
	double area1 = cross(B - A, C - A);
	double area2 = cross(B - A, D - A);

	return dcmp(area1)*dcmp(area2) <= 0;//=0就代表不规范相交
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
				if (i == j)continue;//i==j时，是垂直线，不能从入口进入
				int collide = 0;
				size_t k;
				for (k = 0; k < n; k++)
				{
					//					if (check(pUp[i], pDown[j], pUp[k], pUp[k - 1]) ==1)//这是错的，我比较的是有没有穿过墙壁，但这很容易就会造成平行线，（就是光线是由墙壁生成的）
					if (!check(pUp[i], pDown[j], pUp[k], pDown[k]))//这只是没穿过 墙壁口的垂直线而已，并不知道是撞上上墙壁还是下墙壁。
					{
						collide = 1;
						//不能再这里赋予新值，因为还缺了必要的条件
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
					//						//这里我在复制黏贴时，又忘记了把变量正确改掉
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
				//下面这样做事必要的，因为确保了那么一个现象，光线既不会穿过竖直墙壁，也没穿过墙壁
				if (k > max(i, j))
				{
					double temp = segcross(pUp[i], pDown[j], pUp[k], pUp[k - 1]);
					if (maxX < temp)  //L与第k-1节管子的上管壁相交  
						maxX = temp;

					temp = segcross(pUp[i], pDown[j], pDown[k], pDown[k - 1]);
					if (maxX < temp)  //L与第k-1节管子的上管壁相交  
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