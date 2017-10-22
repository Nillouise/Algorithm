#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e9+100;
vector<int> vis;
typedef pair<int,int> pii;
int DP[int(1e6)];
int tmp[int(1e6)];
int g[int(1e6)];
struct Node
{
    int p1;
    int p2;
    int flag;
};

int main()
{
    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    
    int n,k;
    cin>>n>>k;
    
    int MIN=maxn,MAX=0;
    vis.push_back(-maxn);
    for (int i = 0; i < n; i++) {
        int a;
        cin>>a;
        vis.push_back(a);
    }
    sort(vis.begin(),vis.end());
    int begin=0,end=maxn;
    
    while(begin<end)
    {
        DP[0] = 1;// 种子
        g[0] = 1;
        
        int mid = (begin+end)>>1;
        
        //用g解决状态转移数目过多的问题
        int j=1;
        for (int i = 1; i <=n; i++) {
            while(vis[i]-mid>vis[j])j++;
            //这里用j-2是因为，因为要搜索的结尾(也就是状态的转移)是j-1 到i-k+1-1，结尾是包括j-1的，所以要算结尾的前缀和时，就要算j-2.
            // if(i-k+1-1>=0&& g[i-k+1-1]-(j==1?0:g[j-2])>0 )
            //这里换一个写法就是,||前就是判断DP[j-1]是不是一个合法结尾
            if((DP[j-1]==1&&i-k+1-1>=j-1)|| (i-k+1-1>=j-1&&g[i-k+1-1]-g[j-1])>0)
            {
                DP[i] = 1;
            }else{
                DP[i]=0;
            }
            g[i] = g[i-1]+DP[i];
        }
        // for (int i = 0; i <= n; i++) {
        //     cout<<g[i]<<" ";
        // }//
        // cout<<endl;
        
        if(DP[n]==1)
        {
            memcpy(DP,tmp,sizeof(DP));
            end=mid;
        }else{
            // cout<<begin; //
            begin = mid+1;
        }
    }
    cout<<end<<endl;
    
    
    return 0;
}
