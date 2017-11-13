//枚举每一种硬币的数量
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[6]={1,2,3,5,10,20};
int cnt[6];
int DP[10000];
int dfs(int n,int sum)
{
    if(n==6)
    {
        DP[sum]=1;
        return 0;
    }

    for(int i=0;i<=cnt[n];i++)
    {
        dfs(n+1,sum+i*a[n]);
    }
    return 0;
}

int main()
{
    freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);


    for(int i=0;i<6;i++)
        cin>>cnt[i];
    dfs(0,0);
    int m=0;
    for(int i=1;i<1001;i++)
        if(DP[i])m++;
    cout<<"Total="<<m<<endl;

}
