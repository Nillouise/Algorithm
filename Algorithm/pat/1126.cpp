//没有判连通呀。。//我居然连并查集都写错了。。是pa[u] = pa[v]才对呀
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int data[1000];
int pa[1000];

int unse(int x)
{
    if(pa[x]==x)
        return x;
    return pa[x] = unse(pa[x]);
}

int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;
    if(n==1)
    {
        cout<<"0"<<endl;
        cout<<"Eulerian"<<endl;
        return 0;
    }
    int flag=0;
    for (int i = 1; i <= n; i++) 
    {
        pa[i]=i;
    }
    
    for (int i = 0; i < m; i++) 
    {
        int u,v;
        cin>>u>>v;
        // cout<<"one"<<u<<" "<<v<<" v "<<v<<endl;//

        int pu=unse(u),pv=unse(v);
        // cout<<pu<<" "<<pv<<" v "<<v<<endl;//
        pa[pu]=pv;
        data[u]++;
        data[v]++;
    }
    for (int i = 1; i <= n; i++) 
    {
        if(unse(i)!=unse(1))
        // if(pa[i]!=pa[1])//居然这么蠢。。
        {
            flag=1;
            break;
        }
    }
    
    for (int i = 1; i <= n; i++) 
    {
        cout<<data[i];
        if(i!=n)cout<<" ";
    }
    cout<<endl;
    int cnt0=0,cnt1=0;
    for (int i = 1; i <= n; i++) 
    {
        if(data[i]==0)cnt0++;
        if(data[i]&1)cnt1++;
    }
    if(cnt0||(cnt1!=0&&cnt1!=2)||flag==1)
    {
        cout<<"Non-Eulerian"<<endl;
    }else if(cnt1==2){
        cout<<"Semi-Eulerian"<<endl;
    }else
    {
        cout<<"Eulerian"<<endl;
    }
    
    return 0;
}
