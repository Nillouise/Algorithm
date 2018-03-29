//这题我傻逼了，以为半径除以2就能计算到中心点(r/2,r2)，但其实是要用开方才能根据半径 (r/根号2,r/根号2)
//好傻逼呀
// http://codeforces.com/contest/935/problem/C
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
typedef long long LL;

double mypow(double x)
{
    return x*x;
}

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    double r,x1,y1,x2,y2;
    cin>>r>>x1>>y1>>x2>>y2;
    
    
    double ori = sqrt(mypow(y2-y1)+mypow(x2-x1));
    if(ori>=r)
    {
        printf("%.8lf %.8lf %.8lf\n",x1,y1,r);
        return 0;
    }
    double delimeter = sqrt(mypow(y2-y1)+mypow(x2-x1))+r;
    // cout<<delimeter<<endl;
    double rad =delimeter/2;
    
    double gy;
    double gx;
    // cout<<1e-5<<endl;
    if(ori<1e-9)
    {
        gy = rad;
        gx = 0;
        // gx = rad/2;
    }else{
        gy = rad*((y2-y1)/ori);
        gx = rad*((x2-x1)/ori);
    }
    
    // cout<<gy<<" "<<gx<<endl;
    
    double ay = y2-gy;
    double ax = x2-gx;
    
    // cout<<ay<<" "<<ax<<endl;
    
    // cout<<rad<<" "<<ax<<" "<<ay<<endl;
    int ans=0;
    while(sqrt(mypow(ax-x2)+mypow(ay-y2))-rad>1e-6)
    {
        ans++;
    }
    
    printf("%.8lf %.8lf %.8lf\n",ax,ay,rad);
    
    if(sqrt(mypow(ax-x2)+mypow(ay-y2))-rad>1e-6)
    {
        cout<<ans;
    }
    return 0;
}
