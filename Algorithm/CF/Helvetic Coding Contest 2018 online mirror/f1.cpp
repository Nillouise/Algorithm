#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int n,m;cin>>n>>m;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin>>vec[i];
        vec[i]--;
    }
    vector<int> dat(m);
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        cin>>dat[i];
        cnt+=dat[i];
    }
    
    for (int i = 0; i < n; i++) {
        if(i>=cnt)dat[vec[i-cnt]]++;//这里逻辑反复错误
        dat[vec[i]]--;
        int flag=0;
        for (int j = 0; j < m; j++) {
            // cout<<dat[j]<<" ";
            if(dat[j]!=0){
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            return cout<<"YES"<<endl,0;
        }
    }
    cout<<"NO"<<endl;
    
    
    
    
    
    
    return 0;
}