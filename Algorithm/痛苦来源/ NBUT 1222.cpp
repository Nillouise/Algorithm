#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
string s;
int tri[1000*30][30][2];
LL dp[10000+100];
LL vis[10000+100];
LL dfs(int x)
{
    if(x==s.size())
    {
        return 0;
    }else if(x>s.size()){
        return -1e8;
    }
    if(vis[x])
    {
        return dp[x];
    }    
    vis[x]=1;
    
    int be = 0;
    int len = 0;
    while(be!=-1 && len+x<s.size())
    {
        int w = tri[be][s[x+len]-'a'][0];
        if(w!=-1)
        {
            dp[x] = max(dfs(x+len+1)+w,dp[x]);
        }
        be = tri[be][s[x+len]-'a'][1];
        len++;//一开始还忘记了len++;
    }
    return dp[x];
}

int main()
{
    
    ios::sync_with_stdio(false);
    while(cin>>n>>s)
    {
        memset(tri,-1,sizeof(tri));
        memset(vis,0,sizeof(vis));
        memset(dp,-0x3f3f3f,sizeof(dp));
        int len = 1;
        for (int i = 0; i < n; i++) {
            int w;string t;cin>>t>>w;
            int be = 0;
            for(int j=0;j<t.size();j++)
            {
                char a = t[j];
                if(j==t.size()-1)
                {
                    tri[be][a-'a'][0] = w;
                    break;
                }
                if( tri[be][a-'a'][1] == -1)
                {
                    tri[be][a-'a'][1] = len;
                    len++;
                }
                be = tri[be][a-'a'][1];
            }
        }
        
        dfs(0);
        if(dp[0]>0){
            cout<<dp[0]<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
    
    
    
    return 0;
}