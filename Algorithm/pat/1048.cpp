#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


int n,thr;
map<string,int> ids;
vector<string> ids2;
int ID(string s)
{
    if(ids.find(s)==ids.end())
    {
        ids[s]=ids2.size();
        ids2.push_back(s);
    }
    return ids[s];
}
int G[2000+10][2000+10];
int vis[2000+10];
int cnt[2000+10];
int lar[2000+10];//人数
int bfs(int x)
{
    if(vis[x]==1)return -1;
    queue<int> Q;
    set<int> fil;
    vis[x]=1;
    Q.push(x);
    fil.insert(x);
    while(!Q.empty())
    {
        int u = Q.front();Q.pop();
        for (int i = 0; i < ids2.size(); i++) 
        {
            // cout<<x<<"Gx "<<u<<" "<<i<<" "<<G[u][i]<<endl;//
            if(G[u][i]>0&&vis[i]==0)
            {
                Q.push(i);
                vis[i]=1;
                // fil.insert(x);//妈的，写个bfs都写错
                fil.insert(i);
            }
        }
    }
    int maxi =-1;
    int MAX=0;
    int wei = 0;
    for(auto a:fil)
    {
        // cout<<x<<"net "<<a<<endl;
        wei+=cnt[a];
        if(cnt[a]>MAX)
        {
            MAX=cnt[a];
            maxi=a;
        }
        lar[a]=fil.size();
    }
    // cout<<"weiT"<<wei<<endl;//
    if(wei<thr*2)return -1;
    return maxi;
}

bool cmp(int t1,int t2)
{
    return ids2[t1]<ids2[t2];
}

int main()
{
    freopen("input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    
    cin>>n>>thr;
    
    for (int i = 0; i < n; i++) 
    {
        string s1,s2;
        int t;
        cin>>s1>>s2>>t;
        int id1 = ID(s1);
        int id2 = ID(s2);
        if(id1==id2)continue;
        if(id1>id2)swap(id1,id2);
        G[id1][id2]+=t;
        G[id2][id1]+=t;
    }
    for(int i=0;i<ids2.size();i++)
    {
        int ct=0;
        for(int j=0;j<ids2.size();j++)
        {
            ct+=G[i][j];
        }
        cnt[i]=ct;
    }
    
    
    vector<int> ans;
    for (int i = 0; i < ids2.size(); i++) 
    {
        int wei = bfs(i);
        // cout<<"wei"<<wei<<endl;//
        if(wei==-1)continue;
        if(lar[wei]>2) ans.push_back(wei);
    }
    
    sort(ans.begin(),ans.end(),cmp);
    cout<<ans.size()<<endl;
    for(auto a:ans)
    {
        cout<<ids2[a]<<" "<<lar[a]<<endl;
    }
    

    return 0;
}
