#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int G[300][300];


int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++) 
    {
        int u,v;
        cin>>u>>v;
        G[u][v]=1;
        G[v][u]=1;
        G[v][v]=1;
        G[u][u]=1;
    }
    int k;
    cin>>k;
    for (int i = 0; i < k; i++) 
    {
        int pcnt;
        cin>>pcnt;
        vector<int> vec(pcnt);
        set<int> but;
        for (int i = 0; i < pcnt; i++) 
        {
            cin>>vec[i];
            but.insert(vec[i]);
        }
        if(pcnt!=n+1||but.size()!=n||vec.back()!=vec[0])
        {
            cout<<"NO"<<endl;
            continue;
        }
        int flag=1;
        for (int i = 0; i < pcnt-1; i++) 
        {
            if(G[vec[i]][vec[i+1]]==0)
            {
                // cout<<"NO"<<endl;
                flag=0;
                break;//脑残，压根没break外层for
            }
        }
        if(flag==1)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
    

    return 0;
}
