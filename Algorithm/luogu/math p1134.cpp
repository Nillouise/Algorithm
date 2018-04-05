#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
// 又写错了，还没意识到错误
// 算法:
// 暴力 暴力乘,每次保留得到的数的后7位左右(保证不出现误差)
// 如果每次 mod 10,会造成误差.因为当相乘后得到的是10的倍数时,mod 10 会变成0.所以每次大概mod 1000000.最后输出ans%10
// 
// 原理:最后一位相乘只会影响最后一位.故只保留最后几位就行了
// 
// 数学方法:有两种.第一种分析10怎么出现.发现如果两个数的因数中分别有2,5.那么相乘末尾一定有0.于是统计1~N中每个数的因数中2和5的个数.用2的个数减去5的个数(2的个数一定比5的个数多).剩下的是会对答案(即末尾的数)造成影响.之后大胆mod 10 就行了.
// 
// 第二种应该是正解.
// 
// 分析:N!的末尾只会是2,4,6,8(在此题中没有0).又[2,4,6,8]中任意一个数乘6,末尾仍是本身.2 * 6 = 12,末尾为2, 4 * 6 =24,末尾为4, 6 * 6=36,末尾为6,8 * 6 =48,末尾为8.又末尾数字只受末尾数字影响,如4. 4 * 6得到的末尾数字与4 * 16的末尾数字一样.又4 * 10=40,末尾数字为4(此题不要末尾0).则4 * 2 *8==4 * 2 *5(意思是得到的末尾数字是一样的).故所有乘5的时候都可以换为乘8.又多次乘8末尾是有规律的.找出规律即可.
int dfs(LL x)
{
    if(x<10)return x;
    int a = dfs(x/2);
    int b = dfs(x/2+x%2);
    
    int t =a*b;
    while(t%10==0)
    t/=10;
    return t%10;
}

int dfs(LL b,LL e)
{
    if(e-b<10)
    {
        LL t = 1;
        for(LL i=e;i>=b;i--)
        {
            t*=i;
            while(t%10==0)t/=10;
        }
        return t;
    }
    
    int x = dfs(b,b+(e-b)/2);
    int y = dfs(b+(e-b)/2+1,e);
    
    LL t=x*y;
    while(t%10==0)
    {
        t/=10;
    }
    return t%10;
}

int dfs2(LL x)
{
    if(x<10)
    {
        int t = 1;
        for (int i = 0; i < x; i++) {
            t*=8;
        }
        while(t%10==0)t/=10;
        return t%10;
    }
    int a = dfs2(x/2);
    int b = dfs2(x/2+x%2);
    
    int t =a*b;
    while(t%10==0)
    t/=10;
    return t%10;
}
int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    // LL n=1;
    // cin>>n;
    // int ans = 1;
    // for(int i=1;i<=n%10;i++)
    // {
    //     ans*=i;
    // }
    // n/=10;
    // while(n)
    // {
    //     ans*=dfs2(n);
    //     while(ans%10==0)ans/=10;        
    //     n/=10;
    //     if(n<10)
    //     {
    //         for(int i=1;i<=n%10;i++)
    //         {
    //             ans*=i;
    //         }
    //         while(ans%10==0)ans/=10;    
    //         break;
    //     }
    // }
    // cout<<ans%10<<endl;
    LL n;
    cin>>n;
    LL res = 1;
    for(LL i=1;i<n;i++)
    {
        res*=i;
        while(res%10==0)res/=10;
        res%=1000000000;
    }
        while(res%10==0)res/=10;
        cout<<res%10<<endl;
    
    return 0;
}