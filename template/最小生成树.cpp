#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int N;
int G[200][200];
int w[20000], u[20000], v[20000], e[20000];

//并查集，要初始化成fa[i]=i
int fa[200];
int find(int x)
{
    if(fa[x]==x)return x;
    return fa[x] = find(fa[x]);//注意并查集的路径缩短写法
}

bool cmp(const int i,const int j)
{
    return w[i]<w[j];
}

int Kruskal()
{
    for (int i = 0; i < N; i++) fa[i]=i;//初始化并查集
    for(int i=0;i<N*N;i++)e[i]=i;//初始化边序号
    sort(e,e+N*N,cmp);
    LL ans = 0;
    for (int i = 0; i < N*N; i++) {
        // int pa = find(u[e[i]]),pb = find(v[e[i]]);//这里写错了，写成了u[i]
        int ce=e[i];int pa = find(u[ce]),pb=find(v[ce]);//这里用ce吧e[i]这个序号标记拆出来。
        
        if(pa==pb)continue;//跳过已经联通的部分
        ans+=w[ce];
        fa[pa]=pb;//合并并查集
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>N;
    int cur = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin>>G[i][j];
            u[cur]=i; v[cur]=j; w[cur]=G[i][j];
            cur++;
        }
    }
    cout<<Kruskal()<<endl;
    return 0;
}