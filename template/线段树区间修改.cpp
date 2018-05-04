#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 100000*3;
LL sumv[MAXN],minv[MAXN],maxv[MAXN],addv[MAXN];
void maintain(int o,int L,int R)
{
    int lc = o*2,rc = o*2+1;
    sumv[o] = minv[o] = maxv[o]=0;//注意不要把o写成零
    if(R>L)
    {
        sumv[o] = sumv[lc]+sumv[rc];
        minv[o] = min(minv[lc],minv[rc]);
        maxv[o] = max(maxv[lc],maxv[rc]);
    }
    minv[o] += addv[o];maxv[o] += addv[o];sumv[o]+=addv[o]*(R-L+1);
}
LL x1,x2,v;
void update(int o,int L,int R)
{
    int lc = o*2,rc = o*2+1;
    if(x1<=L&&x2>=R){
        addv[o]+=v;
    }else{
        int M = L+(R-L)/2;
        if(x1<=M)update(lc,L,M);
        if(x2>M)update(rc,M+1,R);
    }
    maintain(o,L,R);
}

LL _min,_max,_sum;
void query(int o,int L,int R,LL add)
{
    if(x1<=L&&x2>=R)
    {
        _sum+=sumv[o]+add*(R-L+1);//注意这里，单单sumv[o]是不包含父节点被增加的变量的，
        _min = min(_min,minv[o]+add);
        _max = max(_max,maxv[o]+add);
    }else {
        int M = L+(R-L)/2;
        if(x1<=M)query(o*2,L,M,add+addv[o]);
        if(x2>M) query(o*2+1,M+1,R,add+addv[o]);
    }
}


int main()
{
    
    ios::sync_with_stdio(false);
    int N,M;
    cin>>N>>M;
    //使用示例
    for (int i = 0; i < N; i++) {
        int x;cin>>x;
        v = x;//v 是全局变量，代表把某个区间要增加的值
        x1 = i,x2 = i;//单点修改，用全局变量x1,x2来表示要修改的区间
        update(1,0,N-1);
        _sum=0,_max = 0,_min = 1e8;//这些都是全局变量，在查询的时候需要充值。
        query(1,0,N-1,0);//形参add，代表的是父节点对子节点的影响
    }
    
    return 0;
}