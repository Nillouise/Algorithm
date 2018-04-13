#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 100000*3;
LL sumv[MAXN],minv[MAXN],maxv[MAXN],addv[MAXN];
void maintain(int o,int L,int R)
{
    int lc = o*2,rc = o*2+1;
    sumv[o] = minv[o] = maxv[o]=0;
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
        // cout<<"q"<<sumv[o]<<endl;
        _sum+=sumv[o]+add*(R-L+1);
        _min = min(_min,minv[o]+add);
        _max = max(_max,maxv[o]+add);
    }else {
        int M = L+(R-L)/2;
        if(x1<=M)query(o*2,L,M,add+addv[o]);
        if(x2>M) query(o*2+1,M+1,R,add+addv[o]);
    }
}

int useexample()
{
    
}


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int N,M;
    cin>>N>>M;
    for (int i = 0; i < N; i++) {
        int x;cin>>x;
        v = x;
        x1 = i,x2 = i;
        update(1,0,N-1);
    }
    for (int i = 0; i < M; i++) {
        int op; cin>>op;
        if(op==1){
            int x,y,k;cin>>x>>y>>k;
            v = k, x1 = x-1,x2 = y-1;
            update(1,0,N-1);
        }else{
            int x,y;cin>>x>>y;
            x1 = x-1,x2=y-1;
            _sum=0,_max = 0,_min = 1e8;
            query(1,0,N-1,0);
            // cout<<"d "<<_sum<<" "<<_max<<" "<<_min<<endl;//
            cout<<_sum<<endl;//
        }
    }
    
    
    return 0;
}