#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL dp[210][210*210];
LL pre[300];


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int N;
    cin>>N;
    vector<pair<LL,LL>> vec;
    for (int i = 0; i < N; i++) {
        int a,b;
        cin>>a>>b;
        vec.push_back({b,a});
    }
    sort(vec.rbegin(),vec.rend());
    
    for (int i = 0; i < N; i++) {
        pre[i+1] = pre[i] + vec[i].second;
    }
    vec.insert(vec.begin(),{0,0});
    memset(dp,0x3f3f,sizeof(dp));
    dp[0][0]=0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= pre[i]; j++) {
            if(j>=vec[i].second)
            {
                dp[i][j] = min(dp[i][j], max(dp[i-1][j-vec[i].second],j+vec[i].first)) ;
            }
            dp[i][j] = min(dp[i][j], max(dp[i-1][j],pre[i]-j + vec[i].first) );
        }
    }
    
    LL ans = 1e8;
    for (int i = 0; i <= pre[N]; i++) {
        ans = min(ans,dp[N][i]);
    }
    
    cout<<ans<<endl;
    
        
    
    return 0;
}