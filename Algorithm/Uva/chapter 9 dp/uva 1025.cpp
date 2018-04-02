#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

double DP[1000+100][1000+100];
pair<int,int> dat[1000+100];

double cal(int a,int b)
{
    return sqrt( pow((double) dat[a].first-dat[b].first,2.0)+pow((double)dat[a].second-dat[b].second,2.0));
    
    
}

int main()
{
    freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
//    ios::sync_with_stdio(false);
    
    int n;
    while(cin>>n)
    {
        for(int i=0;i<1000+100;i++)
        {
            for(int j = 0;j<1000+100;j++)
            {
                DP[i][j] = 100000000.0;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            dat[i] = {x,y};
        }
        DP[0][0] = 0;
        for(int i = 0;i<n-1;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                int m = max(i,j);
                m++;
                double d1 = cal(j,m);
                if(DP[i][j]+d1<DP[i][m])DP[i][m] = DP[i][j]+d1;//一开始，我还写成了DP[m][j]了，真是脑残
                d1 = cal(m,i);
                if(DP[i][j]+d1<DP[m][j])DP[m][j] = DP[i][j]+d1;
            }
        }
        double ans = 1e19;
        for(int i=0;i<n;i++)
        {
            ans = min(ans,DP[i][n-1]+cal(i,n-1));
            ans = min(ans,DP[n-1][i]+cal(i,n-1));
        }
        printf("%.2lf\n",ans);
    }
    
    
    
    return 0;
}