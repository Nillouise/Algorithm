#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL MOD = 20100403;

//快速幂
LL pow(LL x,LL p)
{
    LL res = 1;
    while(p)
    {
        if(p&1)res = (res*x)%MOD;
        p>>=1;
        x=(x*x)%MOD;
    }
    return res;
}

//逆元数组
LL inv[1000000];
LL pre[1000000];

//算组合数
LL Combine(int n,int m)
{
    cout<<"pre "<<pre[n]<<endl;
    cout<<"inv[n-m] "<<inv[n-m]<<endl;//
    LL up = pre[n]*inv[n-m]%MOD;//算上面组合数公式上面的结果
    cout<<"up "<<up<<endl;
    LL down = up *inv[m]%MOD;//算组合式公式下面的结果。
    cout<<"inv[m] "<<inv[m]<<endl;//
    cout<<"down "<<down<<endl;
    return down;
}



int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int T;cin>>T;
    while(T--)
    {
        int n,m,p;cin>>n>>m>>p;MOD = p;
        
        pre[0]=1;
        for (int i = 1; i <= n+m; i++) {
            pre[i] = (pre[i-1]*i)%MOD;
            if(i>14604+3902-10)cout<<pre[i]<<" ";
        }
        inv[n+m] = pow(pre[n+m],MOD-2);
        for (int i = n+m-1; i >=0; i--) {
            inv[i] = inv[i+1]*(i+1)%MOD;
        }
        cout<<Combine(n+m,m)<<endl;
    }
    
    return 0;
}