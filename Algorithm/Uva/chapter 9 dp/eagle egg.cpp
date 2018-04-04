#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
LL dp[200][100];//i个球，n次，可以验证多高的楼层
LL test[2000][10];


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    for(int i=0;i<100;i++)
    {
        dp[1][i]=i;
    }
    
    for(int i=2;i<200;i++)
    {
        for(int j=1;j<100;j++)
        {
            dp[i][j] =  dp[i-1][j-1] + dp[i][j-1]+1;
        }
    }
    // for(int i=0;i<30;i++)
    // {
    //     cout<<"i = "<<i<<" "<<dp[3][i]<<endl;
    // }
    memset(test,0x3f3f3f,sizeof(test));
    test[1][0] = 10000;
    for(int i=0;i<2000;i++)
    {
        test[i][1] = i;
        
    }
    for(int j=2;j<10;j++)
    {
        for(int i=1;i<=1000;i++)
        {
            // if(i<=j)
            test[1][j]=1;
            test[0][j]=0;
            for(int k=1;k<=i;k++)
            {
                test[i][j] = min(test[i][j],1+max(test[k-1][j-1],test[i-k][j]));
                // cout<<test[i][j]<<endl;
            }
        }

    }
    for(int i=990;i<1005;i++)
    cout<<test[i][3]<<endl;
    
    
    LL k,n;
    while(cin>>k,k!=0)
    {
        cin>>n;
        int flag=0;

            for(int j=1;j<64;j++)
            {
                if(dp[k][j]>=n)
                {
                    flag=1;
                    cout<<j<<endl;
                    break;
                }
            }
        if(flag==0)
        cout<<"More than 63 trials needed."<<endl;
    }
    
    
    
    return 0;
}