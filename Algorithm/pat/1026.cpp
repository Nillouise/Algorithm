#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m;
vector<int> coins;
vector<int> ans;
int dfs(int pos,int sum)
{
    if(sum>m)return 0;
    if(sum==m)return 1;
    for(int i=pos;i<coins.size();i++)
    {
        ans.push_back(coins[i]);
        if(dfs(i+1,sum+coins[i])==1)
            return 1;
        ans.pop_back();
    }
    return 0;
}

int main()
{
    freopen("input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    cin>>n>>m;
    coins.resize(n);
    for (int i = 0; i < n; i++) 
    {
        cin>>coins[i];
    }
    sort(coins.begin(),coins.end());
    if(dfs(0,0))
    {
        for (int i = 0; i < ans.size(); i++) 
        {
            cout<<ans[i];
            if(i !=ans.size()-1)cout<<" ";
        }
        cout<<endl;
        
    }else{
        cout<<"No Solution"<<endl;
    }


    return 0;
}
