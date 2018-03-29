#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int DP[1000000+10][10];

inline intGet(int x)
{
    while(x>=10)
    {
        int pro = 1,t = x;
        while(t)
        {
            if(t%10)
                pro*=t%10;
            t/=10;
        }
        x = pro;
    }
    return x;
}

int main()
{
    //freopen("D:\\Project\\Algorithm\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int tmp[10]={0};
    for(int i=0;i<1000000+10;i++)
    {
        tmp[intGet(i)]++;
        memcpy(DP[i],tmp,sizeof(tmp));
    }
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) {
        int l,r,k;
        cin>>l>>r>>k;
        cout<<DP[r][k]-DP[l-1][k]<<endl;
    }
    
    return 0;
}
