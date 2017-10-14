﻿#include<cmath>
using namespace std;
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


