#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1000+10,MAXM=100000+100;

int t[MAXM],u[MAXM],v[MAXM],e[MAXM];
int n,m;
int fa[MAXN];

bool cmp(int a,int b)
{
    return t[a]<t[b];
}

int find(int x)
{
    if(x==fa[x])return x;
    return fa[x]=find(fa[x]);
}

int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for (int i = 0; i < m; i++) {
        cin>>u[i]>>v[i]>>t[i];
        u[i]--,v[i]--;
    }
    for (int i = 0; i < m; i++) {
        e[i]=i;
    }
    sort(e,e+m,cmp);
    for (int i = 0; i < n; i++) {
        fa[i]=i;    
    }
    int cnt =0;
    for (int i = 0; i < m; i++) {
        int ce = e[i]; 
        int pa = find(u[ce]),pb = find(v[ce]);
        if(pa==pb)continue;
        cnt++;
        fa[pa]=pb;
        if(cnt==n-1){cout<<t[ce]<<endl;return 0;}
    }
    cout<<-1<<endl;
    
    
    
    return 0;
}