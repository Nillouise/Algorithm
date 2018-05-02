#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int ql,qr;
const int INF = 1e8;
int minv[1000000];
int query(int o,int L,int R)
{
    int M = L+ (R-L)/2,ans = INF;
    if(ql<=L&&R<=qr)return minv[o];
    if(ql<=M) ans = min(ans,query(o*2,L,M));
    if(M<qr) ans = min(ans,query(o*2+1,M+1,R));
    return ans;
}
int p,v;//修改a[p] = v;
void update(int o,int L,int R)
{
    int M = L+(R-L)/2;
    if(L==R)minv[o]=v;
    else{
        //这里假如是用来建树的话，只要同时update两边即可。
        if(p<=M)update(o*2,L,M);else update(o*2+1,M+1,R);
        minv[o] = min(minv[o*2],minv[o*2+1]);
    }
}


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    
    
    
    return 0;
}