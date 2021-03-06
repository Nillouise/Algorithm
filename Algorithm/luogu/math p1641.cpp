#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
//卡特兰数
LL n,m;
LL MOD = 20100403;


//禁止使用这种递归
LL pow2(LL x,LL p)
{
    if(p==1)
        return x%MOD;
    return pow2(x,p/2)*pow2(x,x/2+x%2)%MOD;
}

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

LL inv[2000000+100];
LL pre[2000000+100];

//算组合数
LL Combine(int n,int m)
{
    LL up = pre[n]*inv[n-m]%MOD;//算上面组合数公式上面的结果
    LL down = up *inv[m]%MOD;//算组合式公式下面的结果。
    return down;
}

int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    cin>>n>>m;
    
    pre[1]=1;
    for (int i = 2; i <= n+m; i++) {//算1*2*3*4...
        pre[i]=pre[i-1]*i%MOD;
    }
    
    //算1*2*3*4...MOD下的逆元
    inv[n+m] = pow(pre[n+m],MOD-2);
    for(int i=n+m-1;i>0;i--)
    {
        inv[i] = inv[i+1]*(i+1)%MOD;
    }
    
    cout<<(Combine(n+m,m)-Combine(n+m,m-1)+MOD)%MOD<<endl;
    
    
    
    
    return 0;
}