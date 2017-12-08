//这题背包，有个更好的方法是保存状态转移边，回忆一下是什么意思。https://www.liuchuo.net/archives/2323
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

bool cmp(const vector<int>&a,const vector<int> &b)
{
    int len = min(a.size(),b.size());
    for (int i = 0; i < len; i++) 
    {
        // cout<<"a "<<a[i]<<" b "<<b[i]<<endl;//
        if(a[i]<b[i])return true;
        if(a[i]>b[i])return false;
    }
    return a.size()<b.size();
    
}


int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    
    int n,m;
    cin>>n>>m;
    vector<int> vec(n);
    vector<int> vis(m+10,0);
    for (int i = 0; i < n; i++) 
    {
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    // n = unique(vec.begin(),vec.end())-vec.begin();
    vector<int> G[300];
    vis[0]=1;
    // G[0].push_back(0);
    for (int i = 0; i < n; i++) 
    {
        // cout<<i<<" ";//
        // for (int j = m; j >=0; j--) //我又弱智了，没有考虑是否溢出（j-vec[i]会溢出）
        for(int j= m;j>=vec[i];j--)
        {
            // if(vis[j]==0)
            {
                if(vis[j-vec[i]]==1  )
                {
                    G[j-vec[i]].push_back(vec[i]);
                    if(vis[j]==0||cmp(G[j-vec[i]],G[j]))
                    {
                        G[j] = G[j-vec[i]];                 
                        // cout<<" j "<<j<<" i "<<i<<" size "<<G[j].size()<<endl;//
                    }
                    G[j-vec[i]].pop_back();
                    vis[j]=1;
                }
            }
        }
    }
    // cout<<"ok"<<endl;//
    if(vis[m]==1)
    {
        // cout<<"fdsf";//
        for (int i = 0; i < G[m].size(); i++) 
        {
            cout<<G[m][i];
            if(i!=G[m].size()-1)
                cout<<" ";
        }
        cout<<endl;
    }else{
        cout<<"No Solution"<<endl;
    }
    


    return 0;
}
