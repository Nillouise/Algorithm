//做到最后才发现还有order要按顺序这回事
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
vector<int> data;
vector<int> fav;
int MAX=0;
int vis[300];
vector<int> path;
//好蠢，这里还把颜色的数量看成是颜色的种类了
// int DP[300][300];
int DP[10000+100][300];
// 
// int dfs(int x,int pre,int dep)
// {
//     if(dep>MAX)
//     {
//         MAX=dep;
//         // for(auto a:path)cout<<a<<" ";//
//         // cout<<endl;//
//     }
//     for(int i=x;i<data.size();i++)
//     {
//         if(data[i]==fav[pre])
//         {
//             vis[fav[pre]]++;
//             // path.push_back(pre);
//             dfs(i+1,pre,dep+1);
//             // path.pop_back();
//             vis[fav[pre]]--;
//         }
//     }
// 
//     for(int i=x;i<data.size();i++)
//     {
//         if(data[i]!=pre&&vis[data[i]]==0)
//         {
//             vis[data[i]]++;
//             path.push_back(data[i]);
//             dfs(i+1,data[i],dep+1);
//             path.pop_back();
//             vis[data[i]]--;     
//         }
//     }
// 
// 
//     return 0;
// }


int main()
{
    freopen("input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    cin>>n;
    int m;
    cin>>m;
    
    set<int> fil;
    for (int i = 0; i < m; i++) 
    {
        int a;
        cin>>a;
        fav.push_back(a);
        fil.insert(a);
    }
    int l;
    cin>>l;
    for (int i = 0; i < l; i++) 
    {
        int a;
        cin>>a;
        
        if(fil.find(a)!=fil.end())
        {
            data.push_back(a);
        }
    }
    //dfs(0,-1,0);//DP吧，不要dfs了
    
    for(int i=1;i<=data.size();i++)
    {
        int cmax=0;
        for(int j=0;j<fav.size();j++)
        {
            cmax=max(DP[i-1][j],cmax);
            if(data[i-1]==fav[j])
                DP[i][j]=cmax+1;
            else{
                //DP[i][j]==cmax;//妈的，这里把=打成了==，以后要好好看warning呀
                DP[i][j]=cmax;
            }
        }
    }
    int ans=0;
    for(int i=0;i<fav.size();i++)
    {
        ans=max(ans,DP[data.size()][i]);
    }
    
    
    cout<<ans<<endl;
    // for(int i=1;i<=data.size();i++)
    // {
    //     for(int j=0;j<fav.size();j++)
    //         cout<<DP[i][j]<<" ";
    //     cout<<endl;
    // }


    return 0;
}
