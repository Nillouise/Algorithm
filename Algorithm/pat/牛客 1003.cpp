#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
double ori,rate;
vector<int> pa;
vector<double> dep;
double dfs(int x)
{
    if(dep[x]>=0)
    {
        return dep[x];
    }
    if(pa[x]==-1)
        return ori;
    dep[x] = dfs(pa[x])*(1.0+(rate)/100);
    return dep[x];
}

int main()
{
    freopen("input.txt","r",stdin);//    
    cin>>n>>ori>>rate;
    pa.resize(n);
    for(int i=0;i<n;i++)cin>>pa[i];
    dep.resize(n);
    fill(dep.begin(),dep.end(),-1.0);
    for(int i=0;i<n;i++)
        dfs(i);
    double MAX = 0.0;
    for(auto a:dep)
        MAX= max(a,MAX);
    int cnt =0;
    for(auto a:dep)
        if(a==MAX)cnt++;
    printf("%.2lf",MAX);
    cout<<" "<<cnt<<endl;
    
    
    return 0;
}
