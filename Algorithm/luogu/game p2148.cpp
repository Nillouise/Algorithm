#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL N, dat[10000*3];

int gx(LL x)
{
    if(x==1)return 0;
    set<int> s;
    
    for(int i=1;i<=x/2;i++)
    {
        s.insert(gx(i));
        s.insert(gx(x-i));
    }
    
    int i=0;
    for(auto a:s)
    {
        if(a!=i)
        {
            return i;
        }
        i++;
    }
    return i;
}

int gx(LL x,LL y)
{
    if(x>y)return gx(y,x);
    
    if(x==1&&y==1)return 0;
    set<int> s;
    
    for(int i=1;i<y;i++)
    {
        s.insert(gx(i,y-i));
    }
    for(int i=1;i<x;i++)
    {
        s.insert(gx(i,x-i));
    }
    int i=0;
    for(auto a:s)
    {
        if(a!=i)
            return i;
        i++;
    }
    return i;
}



int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
// cout<<gx(9,1);    
    for (int i = 1; i < 17; i++) {
        for (int j = 1; j < 17; j++) {
            // cout<<"i="<<i<<j<<" "<<gx(i,j)<<" ";
            cout<<gx(i,j)<<" ";
        }
        cout<<endl;//
    }
    
    
    
    int T;
    cin>>T;
    while(T--)
    {
        cin>>N;
        for (int i = 0; i < N; i++) {
            cin>>dat[i];
        }
        LL res = 0;
        for(int i=0;i<N;i+=2)
        {
            res = res^(max(dat[i],dat[i+1])-1);
        }
        if(res>0)
        {
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    
    
    }
    
    
    return 0;
}