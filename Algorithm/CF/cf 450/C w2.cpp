#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int vis[100000+10];


int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    vector<int> dat(n);
    if(n==1||n==2)return cout<<1<<endl,0;
    for (int i = 0; i < n; i++) 
    {
        cin>>dat[i];
    }
    set<int> but;
    for (int i = 0; i < n; i++) 
    {
        auto it = but.lower_bound(dat[i]+1);
        int num = 0;
        auto it2 = it;
        // cout<<*it2<<endl;//
        while(it!=but.end())
        {
            num++;
            it++;
            if(num>1)break;
        }
        if(num==1)
        {
            vis[*it2]++;
        }
        but.insert(dat[i]);
    }
    
    int MAX=0;
    int maxi=1;
    int flag=0;
    for (int i = 1; i <= n; i++) 
    {
        // cout<<vis[i]<<" ";//
        if(vis[i]>MAX)
        {
            MAX=vis[i];
            maxi=i;
            flag=1;
        }
    }
    if(flag==1)
    cout<<maxi<<endl;//
    else{
        cout<<1<<endl;
    }
    return 0;
}
