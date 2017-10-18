//这题说是用2set做，但重点是应该意识到从前到后，只要比较相邻的字符串就可以了
//而且还只要注意到第一次不同的字母就可以了
//题目又看错了，没注意到可以字符串可以相同
//debug半天发觉是输入数据没改。。。。
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m;
vector<vector<int> > but;
vector<int> G[100000+10];
int sta[100000+10];//0代表无状态，1代表一定要小写字母，2代表一定要大写字母
int possible=1;

inline void dfs(int x)
{
    for(int i=0;i<G[x].size();i++)
    {
        int v=G[x][i];
        if(sta[v]==1)
        {
            possible=0;
            // cout<<x<<" "<<v<<" "; //
        }
        // else {sta[v]=2;dfs(v);}
        if(sta[v]==0)
        {
            sta[v]=2;
            dfs(v);
        }
    }
}

int main()
{
    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    cin>>n>>m;

    for (int i = 0; i < n; i++) {
        int k;
        cin>>k;
        vector<int> v;
        v.clear();
        while(k--)
        {
            int a;
            cin>>a;
            v.push_back(a);
        }
        but.push_back(v);
    }
    
    //
    // for (int i = 0; i < but.size(); i++) {
    //     for (int j = 0; j < but[i].size(); j++) {
    //         cout<<but[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    for (int i = 1; i < n; i++) {
        int j=0;
        for(j=0;j<but[i].size()&&j<but[i-1].size();j++)
        {
            if(but[i][j]!=but[i-1][j])break;
        }
        
        // if(j==but[i].size())//这里这么写问题好严重，因为会跳到下一个if
        if(j==but[i].size()||j==but[i-1].size())
        {
            // if(j==but[i].size())
            // if(but[i].size()>but[j].size())//这里写错了。。。
            // if(but[i].size()>but[i-1].size())// 必须比较两个字符串的长度，因为有可以是一样的//啊啊啊，这是错的，后面的字符串要比前面的字符串长才行
            if(but[i].size()<but[i-1].size())
                possible=0;
        }
        else if(but[i][j]>but[i-1][j])
        {
            G[but[i][j]].push_back(but[i-1][j]);
            // cout<< "but:"<<but[i][j]<<" "<<but[i-1][j]<<endl; //
        }else{
            if(sta[but[i-1][j]]==1||sta[but[i][j]]==2)
            {
                possible=0;
            }else
            {
                sta[but[i-1][j]]=2;
                sta[but[i][j]]=1;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(sta[i]==2)
        {
            dfs(i);
        }
    }
    
    if(possible)
    {
        cout<<"Yes"<<endl;
        int cnt =0;
        
        for (int i = 1; i <= m; i++) {
            if(sta[i]==2)
                cnt++;
        }
        cout<<cnt<<endl;
        for (int i = 1; i <= m; i++){
            if(sta[i]==2)
            cout<<i<<" ";
        }
        cout<<endl;
    }else{
        cout<<"No"<<endl;
    }
    
    
    return 0;
}
