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
    LL pre = 0;
    for (int i = 0; i < N; i++) {
        LL a;cin>>a;
        add(a,i+1);
        add(-a,i+2);
    }
    // for(int i=0;i<=5;i++)cout<<cal(i)<<" ";cout<<endl;//
    
    for (int i = 0; i < M; i++) {
        int op;cin>>op;
        if(op==1)
        {
            int x,y,k;cin>>x>>y>>k;
            // cout<<"op1"<<endl;//
            add(k,x);
            add(-k,y+1);
        }else{
            // for(int i=0;i<=5;i++)cout<<cal(i)<<" ";cout<<endl;//
            
            int x;cin>>x;
            cout<<cal(x)<<endl;
        }
            
    }
    
    
    
    return 0;
}