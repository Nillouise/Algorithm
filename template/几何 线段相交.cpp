#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

struct Point
{
    double x,y;
    Point operator-(const Point& t)const
    {
        return {x-t.x,y-t.y};
    }
};

Point r[20];
Point c[20];

double Dot(Point a,Point b)
{
    return a.x*b.x+a.y*b.y;
}
double Cross(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}
const double eps = 1e-8;
int dcmp(double x)
{
    if(fabs(x)<eps)return 0;
    return x<0?-1:1;
}

//线段a1a2 跟线段b1b2有没有相交
bool SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2)
{
    double c1 = Cross(a2-a1,b1-a1),c2 = Cross(a2-a1,b2-a1),
        c3 = Cross(b2-b1,a1-b1),c4 = Cross(b2-b1,a2-b1);
    return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}