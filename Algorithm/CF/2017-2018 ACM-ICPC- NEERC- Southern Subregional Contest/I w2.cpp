#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e9+100;
vector<int> vis;
typedef pair<int,int> pii;
int DP[int(1e6)];
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
        
        memset(DP,0,sizeof(DP));
        DP[0] = 1;// 种子
        int mid = (begin+end)>>1;
        for (int i = 1; i <= n; i++) {//这里是小于等于n
            for(int j=i;j>=1;j--)
            {
                if(vis[i]-vis[j]<=mid)
                {
                    if(i-j+1>=k)
                    {
                        DP[i] = DP[j-1];
                        if(DP[i] == 1)break;
                    }
                }else{
                    break;
                }
            }
        }
        if(DP[n]==1)
        {
            
            end=mid;
        }else{
            // cout<<begin; //
            begin = mid+1;
        }
    }
    cout<<end<<endl;
    
    
    return 0;
}
