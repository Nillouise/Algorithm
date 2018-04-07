#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxm = 100000+100;

int dp[maxm];
struct Edge
{
    int u,v,w,e; 
    bool operator< (const Edge &rhs)const{
        if(w==rhs.w)
        {
            return (e==-1?-1:dp[e])< (rhs.e==-1?-1:dp[rhs.e]);
        }
        return w<rhs.w;
    }
};

int n,m;
int v1[maxm],v2[maxm],w[maxm];
set<Edge> G[100000+100];
int dpG[100000+100];


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    fill(begin(dp),end(dp),1);
    cin>>n>>m;
    for (int i = 0; i < m; i++) {
        cin>>v1[i]>>v2[i]>>w[i];
        
        // for(auto e:G[v1[i]])
        // {
        //     if(e.w>w[i])
        //     {
        //         break;
        //     }
        // 
        //     if(e.w<w[i])
        //     {
        //         if(dp[i]<dp[e.e]+1)
        //         {
        //             dp[i]=dp[e.e]+1;
        //         }
        //     }
        // }
        
        auto iter2 = G[v1[i]].lower_bound({0,0,w[i],-1});

        if(iter2!=G[v1[i]].begin())
        {
            cout<<iter2->e<<" w="<<iter2->w<<endl;
            int k=0;
            while(true)
            {
                if(iter2==G[v1[i]].begin())break;
                else iter2--;
                if(k>0&&dp[i]< dp[iter2->e]+1)
                {
                    dp[i] = max(dp[i], dp[iter2->e]+1);
                    // cout<<i<<" "<<dp[i]<<" "<< iter2->e<<" "<<dp[iter2->e] <<endl;//
                    for(auto a:G[v1[i]])
                    {
                        cout<<"for u="<<a.u<<" v="<<a.v<<" "<<a.e<<" "<<dp[a.e]<<" "<<a.w<<endl;
                    }
                    
                }
                k++;
                if(k>10)break;
            }
        }
        
        //erase是错的，应该erase的是v2[i]才对。
        auto iter = G[v1[i]].lower_bound({0,0,w[i],-1});
        cout<<"iter size="<<G[v1[i]].size()<<" " <<iter->u<<" "<<iter->v<<" "<<iter->w<<" "<<iter->e<<endl;
        int flag=0;
        if(iter== G[v1[i]].end()|| iter->w>w[i])flag=1;
        //这里LIS原本写漏了，没有考虑w比当前小的他的dp值，又是考虑后端，忘了考虑前端。
        if(iter!=G[v1[i]].begin())
        {
            auto iter3 = iter;
            iter3--;
            if(dp[iter3->e]>=dp[i])
            {
                cout<<" pre "<<iter3->e<<" "<<dp[iter3->e]<<" "<<i<<" "<<dp[i]<<endl;//
                continue;
            }
        }
        while(true)
        {
            if(iter!=G[v1[i]].end()&& iter->w>=w[i]&&dp[iter->e]<=dp[i])
            {
                cout<<"erase "<<iter->u<<" "<<iter->v<<" "<<iter->w<<" "<<iter->e<<endl;
                iter = G[v1[i]].erase(iter);
                flag=1;
            }else{
                break;
            }
        }
        if(flag==1)
        {
            cout<<"insert "<<v1[i]<<" "<<v2[i]<<" "<<w[i]<<" "<<i<<endl;
            G[v2[i]].insert({v1[i],v2[i],w[i],i});
        }
    }
    int ans=0;
    for(int i=0;i<m;i++)
    {
        if(ans<dp[i])ans=dp[i];
    }
    cout<<ans<<endl;
    
    return 0;
}