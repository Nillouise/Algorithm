#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
pair<double,double> coor[30];
double rs[10];
double cal(int a,int b)
{
    return sqrt(pow(coor[a].first-coor[b].first,2.0)+pow(coor[a].second-coor[b].second,2.0))-rs[b];
}


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int order[] = {0,1,2,3,4,5,6,7};
    int n,x,y,x1,y1;

    cin>>n>>x>>y>>x1>>y1;
    if(x>x1)swap(x,x1);
    if(y>y1)swap(y,y1);
    
    for(int i=0;i<n;i++)
    {
        cin>>coor[i].first;
        cin>>coor[i].second;
    }
    double ans=1e9;
    do
    {
        for(int i=0;i<10;i++)rs[i]=0.0;
        double total = (x1-x)*(y1-y);
        for(int i=0;i<n;i++)
        {
            double r=3000;
            r = min(coor[order[i]].first-x,r);
            r = min(x1-coor[order[i]].first,r);
            r=min(coor[order[i]].second-y,r);
            r=min(y1-coor[order[i]].second,r);
            if(r<0)continue;
            
            for(int j=0;j<i;j++)
            {
                r = min(r,cal(order[i],order[j]));
            }
            r = min(coor[order[i]].first-x,r);
            r = min(x1-coor[order[i]].first,r);
            r=min(coor[order[i]].second-y,r);
            r=min(y1-coor[order[i]].second,r);
            if(r<0)r=0;
            rs[order[i]] = r;
            total=total - 3.1415926*r*r;
        }
        ans = min(ans,total);
        
    } while(next_permutation(order,order+n));//厉害了，这里我明明用了order，但一开始居然没有在代码里使用，我的脑子真是不能同时思考很多事情呀。
    // cout<<round(ans)<<endl;//这个吊毛round函数居然这样子是不行的，会输出小数部分的
    cout<<(int)round(ans)<<endl;
    
    return 0;
}