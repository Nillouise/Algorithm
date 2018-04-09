#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m;
int u[500*500],v[500*500],w[500*500];
int fa[500],e[500*500];
// 有最大值最小，典型的二分！!!! 我没想到呀
bool cmp(int a,int b)
{
    return w[a]<w[b];
}

int find(int x)
{
    return x==fa[x] ?x:fa[x] = find(fa[x]);
}

int kru()
{
    for (int i = 0; i < n; i++) {
        fa[i]=i;
    }
    // for (int i = 0; i < n*n; i++) {//错的，边的数量在本题不是n*n;
    for(int i=0;i<m;i++){
        e[i]=i;
    }
    // sort(e,e+n*n,cmp);//错的，边的数量在本题不是n*n;
    sort(e,e+m,cmp);
    for (int i = n-2; i < m; i++) {//注意这里是n-2,而不是n-1，因为数量为n-1的最后一棵树的序号是n-1
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            fa[i]=i;
        }
        for (int j = i; j >= 0; j--) {
            int ce = e[j];
            int pa = find(u[ce]),pb=find(v[ce]);
            if(pa==pb)continue;
            cnt++;
            fa[pa] = pb;
        }
        // cout<<cnt<<endl;//
        if(cnt==n-1)return w[e[i]];
    }
    return 0;
}


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for (int i = 0; i < m; i++) {
        cin>>u[i]>>v[i]>>w[i];
        u[i]--,v[i]--;
    }
    cout<<n-1<<" "<<kru()<<endl;
    
    
    return 0;
}