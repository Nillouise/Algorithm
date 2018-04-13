#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100000+100;
int n;
int dat1[MAXN],dat2[MAXN];
int cvt[MAXN];
int lis[MAXN];


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>dat1[i];
    }
    for (int i = 0; i < n; i++) {
        cvt[dat1[i]] = i+1;
    }
    
    for (int i = 0; i < n; i++) {
        cin>>dat2[i];
    }
    for (int i = 0; i < n; i++) {
        dat2[i] = cvt[dat2[i]];
    }
    memset(lis,0x3f3f3f,sizeof(lis));
    lis[0] = 0;
    for (int i = 0; i < n; i++) {
        int p = lower_bound(lis,lis+n,dat2[i])-lis;
        if(lis[p]!=dat2[i])
        {
            lis[p]=dat2[i];
        }
    }
    for (int i = 0; i < n+1; i++) {//注意这里要n+1
        if(lis[i]>=0x3f3f3f){
            cout<<i-1<<endl;//
            return 0;
        }    
    }
    
    
    return 0;
}