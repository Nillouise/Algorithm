#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> G[1000000];
vector<int> G2[1000000];
int win[1000000];
int all[1000000];
int vis[1000000];
set<int> point;



bool dfsi(int x,int dep);


void dfs2(int x,int cur)
{
    cout<<x<<" ";
    if(point.find(x)!=point.end()){
        return;
    }
    for(auto a:G[x]){
        if(win[a]==cur){
            if(cur==1)
            {
                 dfs2(a,2);
                 return;
            }else if(cur==2){
                dfs2(a,1);
                return;
            }
        }
    }
}
int two[3];
bool dfsi(int x,int dep)
{
    two[dep]=x;
    if(dep==2&&win[x]==1){
        cout<<"Win"<<endl;
        cout<<two[0]<<" "<<two[1]<<" ";
        dfs2(two[2],2);
        return true;
    }
    if(dep>2)
        return false;
    for(auto a:G[x])
    {
        if(dfsi(a,dep+1)==true)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    queue<int> loss;
    int c;
    for(int i=1;i<=n;i++)
    {
        cin>>c;
        if(c==0){
            loss.push(i);
            point.insert(i);
            win[i]=2;//2代表loss,1代表代表赢
        }
        for (int j = 0; j < c; j++) {
            int a;
            cin>>a;
            G[i].push_back(a);
            G2[a].push_back(i);
        }
    }
    int s;
    cin>>s;
    
    while(!loss.empty())
    {
        int u = loss.front();loss.pop();
        if(win[u]==2)
        {
            for(auto a:G2[u]){
                if(win[a]==0)
                {
                    win[a]=1;
                    for(auto b:G2[a]){
                        all[b]++;
                        if(all[b]==G[b].size()){
                            loss.push(b);
                            win[b]=2;
                        }
                    }    
                }
            }
        }
    }
    
    if(win[s]==0)
    {
            cout<<"Draw"<<endl;
            return 0;
    }else{
        if(dfsi(s,0)){
            return 0;
        }else{
            cout<<"Lose"<<endl;
            return 0;
        }
    }
    // 
    // if(win[s]==2){
    //     for(auto a:G[s])
    //     {
    //         if(win[a]==2)
    //         {
    //             cout<<"Win"<<endl;
    //             cout<<s<<" ";
    //             dfsi(a,0);
    //             return;
    //         }
    //     }
    // 
    //     cout<<"Lose"<<endl;
    //     return 0;
    // }else if(win[s]==1){
    //     cout<<"Win"<<endl;
    //     int u = s;
    //     dfs2(s);
    //     return;
    // }else{
    //     cout<<"Draw"<<endl;
    //     return 0;
    // }
    
    return 0;
}
