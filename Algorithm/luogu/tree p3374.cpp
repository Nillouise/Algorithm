#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL dat[500000+100];
int N,M;

void add(int x,int p)
{
    for (int i = p; i <= N; i = i+(i&(-i))) {
        dat[i] += x;
    }
}

LL cal(int p)
{
    LL res =0;
    for(int i=p;i>0;i = i-(i&(-i)))
    {
        res+=dat[i];
    }
    return res;
}


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    cin>>N>>M;
    for (int i = 0; i < N; i++) {
        LL a;cin>>a;
        add(a,i+1);
    }
    for (int i = 0; i < M; i++) {
        int a,x,y;
        cin>>a>>x>>y;
        if(a==1)
        {
            add(y,x);
        }else{
            if(y<x)swap(y,x);
            cout<<cal(y)-cal(x-1)<<endl;
        }
    }
    
    
    return 0;
}