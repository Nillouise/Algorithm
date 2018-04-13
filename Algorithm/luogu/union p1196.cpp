#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int fa[30000+10];
int fa2[30000+10];
int dis[30000+10];
int dis2[30000+10];
int find(int x)
{
    if(fa[x] ==x)
    {
        dis[x] = 0;
        return x;
    }
    int pref = fa[x];
    // int gap = dis[x] - dis[fa[x]];
    int gap = dis[x];
    int f = find(fa[x]);
    // cout<<x<<f <<"gap "<<gap<<endl;
    dis[x] =  dis[pref]+gap;
    fa[x] = f;
    return f;
}

int find2(int x)
{
    if(fa2[x] ==x)
    {
        dis2[x] = 0;
        return x;
    }
    int pref = fa2[x];
    // int gap = dis2[x] - dis2[fa2[x]];
    int gap = dis2[x];
    int f = find2(fa2[x]);
    
    dis2[x] =  dis2[pref]+gap;
    fa2[x] = f;
    return f;
}



int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int T;
    cin>>T;
    for (int i = 0; i < 30000+10; i++) {
        fa[i]=i;
        fa2[i]=i;
    }
    while(T--)
    {
        string s;
        int a,b;
        cin>>s>>a>>b;
        if(s=="M")
        {
            int la = find2(a),lb = find2(b);
            // cout<<"la"<<la<<" lb "<<lb;
            int pa = find(la),pb = find(lb);
            dis[pa] = dis[lb]+1;
            fa[pa] = pb;
            
            fa2[lb] = la;
            dis2[lb] = dis2[pa]+1;
        }else{
            int pa = find(a),pb = find(b);
            if(pa!=pb)
            {
                cout<<-1<<endl;
            }else{
                // cout<<dis[a]<<" dis "<<dis[b]<<endl;//
                cout<<abs(dis[a]-dis[b])-1<<endl;
            }
            
        }
    }
    
    
    return 0;
}