#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int rec[1010][1010];  

int C(int n,int r){
    if(n==r || r==0)    return rec[n][r]=1;
    if(rec[n][r])    return rec[n][r];
    return rec[n][r]=(C(n-1,r)+C(n-1,r-1));
}

int C2(int n,int r)
{
    LL xi = 1;
    LL t = 1;
    for(LL i=n;i>n-r;i--)
    {
        if(xi*i%t)
        {
            cout<<"divide "<<xi<<" "<<i<<" "<<t<<endl;//这条公式不能直接用，因为有可能在中间状态是不能整除的（因为%10007会导致因素消失了）
        }
        // xi= (xi*i/t)%10007LL;
        xi= (xi*i/t);
        // cout<<xi<<endl;//
        t++;
    }
    return xi;
}


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < i; j++) {
            if(C(i,j)!=C2(i,j))
            {
                cout<<"i="<<i<<" j="<<j<<endl;
                cout<<C(i,j)<<" C2="<<C2(i,j)<<endl;
            }
        }
    }
    
    
    LL a,b,k,n,m;
    cin>>a>>b>>k>>n>>m;
    
    LL ans=1;
    
    for(int i=0;i<n;i++)
    {
        ans=(ans*a)%10007LL;
    }
    for(int i=0;i<m;i++)
    {
        ans=(ans*b)%10007LL;
    }
    // LL xi = 1;
    // LL t = 1;
    // for(LL i=k;i>k-n;i--)
    // {
    //     xi= (xi*i/t)%10007LL;
    //     // cout<<xi<<endl;//
    //     t++;
    // }
    ans= (ans*C(k,m))%10007LL;
    
    
    cout<<ans<<endl;
    
    
    return 0;
}