#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int dat[200][200];



int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int T;cin>>T;
    while(T--)
    {
        int n,m;cin>>n>>m;
        memset(dat,0,sizeof(dat));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin>>dat[i][j];
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int cur = dat[i][j]>0?1:0;
                
                cur+= dat[i][j] - dat[i-1][j]<0?0:dat[i][j] - dat[i-1][j];
                cur+= dat[i][j] - dat[i][j-1]<0?0:dat[i][j] - dat[i][j-1];
                cur+= dat[i][j] - dat[i+1][j]<0?0:dat[i][j] - dat[i+1][j];
                cur+= dat[i][j] - dat[i][j+1]<0?0:dat[i][j] - dat[i][j+1];
                ans+=cur;
            }
        }
        
        cout<<ans<<endl;//
        
        
    }
    
    
    
    
    return 0;
}