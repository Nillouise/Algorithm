//这题是在校赛上我开的一题，原本做对这题我就是无悬念的第一名，结果因为我忘记考虑回溯剪枝这个方法，导致我失败得一败涂地。
//那么什么情况能用于回溯呢？就是dfs时，过去的信息已经足够判断这个dfs树合不合格了。体现到这题就是可以在dfs的参数里加一个sum来记录过去的信息。
//这题并不能dp，因为时一层只能剪一条边，dp没有方法解决这个冲突。
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,k;
vector<int> G[400];
vector<int> NG[400];
vector<int> vis(400,0);
int MIN= 1e9;

//sum :inffection,被感染的人数
void dfs(const vector<int> &vec,int sum)
{
    if(sum>=MIN)return;
    vector<int> nv;
    for(auto a:vec)
    {
        if(vis[a]==0)
        for(auto b: NG[a])
        {
            nv.push_back(b);
        }
    }
    if(nv.size()==0)
    {
        if(sum+vec.size()-1<MIN)//这里要加上本层的数量，因为是算到叶子结点就结束了，不会拓展到叶子节点的儿子
        {
            MIN=sum+vec.size()-1;
        }
        return;
    }
    
    for(auto a:nv)
    {
        vis[a]=1;
        dfs(nv,sum+vec.size()-1);
        vis[a]=0;
    }
    
}
void init(int x,int p)
{
    NG[p].push_back(x);
    for(auto a:G[x])
    {
        if(a!=p)
            init(a,x);
    }
}

int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    
    cin>>n>>k;
    for (int i = 0; i < k; i++) 
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    init(1,0);
    
    vector<int> v;
    v.push_back(1);
    dfs(v,1);
    cout<<MIN<<endl;
    
    return 0;
}
