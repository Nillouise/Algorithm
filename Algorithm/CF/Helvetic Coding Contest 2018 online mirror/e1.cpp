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

bool SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2)
{
    double c1 = Cross(a2-a1,b1-a1),c2 = Cross(a2-a1,b2-a1),
        c3 = Cross(b2-b1,a1-b1),c4 = Cross(b2-b1,a2-b1);
    return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
    
}



int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    // cout<<SegmentProperIntersection({0,-1},{0,1},{1,0},{-1,0});
    // cout<<SegmentProperIntersection({0,-1},{0,-0.5},{1,0},{-1,0});
    int R,C;cin>>R>>C;
    if(R!=C){
        cout<<"No"<<endl; return 0;
    }
    for (int i = 0; i < R; i++) {
        cin>> r[i].x>>r[i].y;
    }
    for (int i = 0; i < C; i++) {
        cin>>c[i].x>>c[i].y;
    }
    
    vector<int> dat(R);
    for (int i = 0; i < R; i++) {
        dat[i] = i;
    }
    
    
    do
    {
        int flag = 1 ;
        for(int i=1;i<R;i++)
        {
            for (int j = 0; j < i; j++) {
                if(SegmentProperIntersection(r[dat[i]],c[i],r[dat[j]],c[j]))
                {
                    flag = 0;
                    break;
                }
            }
            if(flag==0)break;
        }
        if(flag==1)
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }while(next_permutation(dat.begin(),dat.end()));
    cout<<"No"<<endl;
    
    
    
    return 0;
}