#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const double PI = acos(-1.0);
struct Point
{
	double x, y;
	Point(double x = 0, double y = 0) :x(x), y(y) {}
};

typedef Point Vector;

Vector operator +(Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator -(Point A, Point B) { return Vector(A.x - B.x, A.y - B.y); }
Vector operator *(Vector A, double p) { return Vector(A.x*p, A.y*p); }
Vector operator /(Vector A, double p) { return Vector(A.x / p, A.y / p); }

bool operator <(const Point &a, const Point& b) {
	return a.x < b.x || (a.x == b.x&&a.y < b.y);
}

const double eps = 1e-10;
int dcmp(double x) {
	if (fabs(x) < eps)return 0; else return x < 0 ? -1 : 1;
}

bool operator ==(const Point& a, const Point& b)
{
	return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}

double Dot(Vector A, Vector B) { return A.x*B.x + A.y*B.y; }
double Length(Vector A) { return sqrt(Dot(A, A)); }
double Angle(Vector A, Vector B) {
	return acos(Dot(A, B) / Length(A) / Length(B));
}

double Cross(Vector A, Vector B) { return A.x*B.y - A.y*B.x; }
double Area2(Point A, Point B, Point C) {
	return Cross(B - A, C - A);
}

double ConverxPolygonArea(Point *p, int n)
{
	double area = 0;
	for (int i = 1; i < n - 1; i++)
		area += Cross(p[i] - p[0], p[i + 1] - p[0]);
	return area / 2;
}

double PolygonLenght(Point*p, int n)
{
	double len = 0;
	for (int i = 1; i < n; i++)
		len += Length(p[i] - p[i - 1]);
	return len + Length(p[0] - p[n - 1]);
}

double solve(Point *parr, int N, Point *ch)
{
	sort(parr, parr + N);
	int m = 0;
	for (int i = 0; i < N; i++)
	{
		while (m>1 && Cross(ch[m - 1] - ch[m - 2], parr[i] - ch[m - 2]) <= 0)//这里 是 m-1 和m-2，因为m是指向空位的。
		{
			m--;
		}
		ch[m++] = parr[i];
	}
	int k = m;
	for (int i = N - 2; i >= 0; i--)
	{
		while (m>k&&Cross(ch[m - 1] - ch[m - 2], parr[i] - ch[m - 2]) <= 0)//这里跟 上面的 差不多，因为都是挑 逆时针翘上去的点，无论是上面的包 还是下面的包
		{
			m--;
		}
		ch[m++] = parr[i];
	}
	if (N > 1) m--;
	return PolygonLenght(ch, m);

}

int main()
{
	int N, L;
	cin >> N >> L;
	Point parr[1000 + 5];
	Point ch[1000 + 5];
	for (size_t i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		parr[i] = Point(x, y);
	}

	cout << (int)round(solve(parr, N, ch) + 2 * PI* L) << endl;


	return 0;
}


