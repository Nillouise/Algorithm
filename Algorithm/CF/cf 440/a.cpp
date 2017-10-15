#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int n,m;
    cin>>n>>m;
    vector<int> v1(n);
    vector<int> v2(m);
    for (size_t i = 0; i < n; i++) {
        cin>>v1[i];
    }
    for (size_t i = 0; i < m; i++) {
        cin>>v2[i];
    }
    
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    
    for(int i=0;i<n;i++)
    {
        for (size_t j = 0; j < m; j++) {
            if(v1[i]==v2[j])
            {
                return cout<<v1[i]<<endl,0;
            }
        }
    }
    
    if(v1[0]<v2[0])
    {
        if(v1[0]==0)
        {
            cout<<v2[0]<<v1[0]<<endl;
        }else{
            cout<<v1[0]<<v2[0]<<endl;
        }
    }else{
        if(v2[0]==0)
        {
            cout<<v1[0]<<v2[0]<<endl;
        }else{
            cout<<v2[0]<<v1[0]<<endl;
        }
    }
    
    
    return 0;
}
