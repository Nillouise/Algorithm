#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int n,k;
    cin>>n>>k;
    vector<int> v;
    for (size_t i = 0; i < n; i++) {
        int a;
        cin>>a;
        v.push_back(a);
        cout<<a<<" "; //
    }
    cout<<endl;  //
    if(k==1)
    {
        sort(v.begin(),v.end());
        cout<<v[0]<<endl;
    }else if(k==2)
    {
        vector<int> vm;
        int MIN = 1e10;
        for (size_t i = 0; i < n; i++) {
            if(MIN>v[i])
            {
                MIN=v[i];
            }
            vm.push_back(MIN);
            cout<<MIN<<" "; //
        }
        cout<<endl;
        int MAX = -1e10;
        MIN = 1<<10;  // 这里错了。。。。。。。。。。。。。。。。。。。。。。。
        for(int i= n-1;i>0;i--)
        {
            if(MIN>v[i])
            {
                MIN=v[i];
            }
            cout<<MIN<< " "; //
            MAX = max(max(MIN,vm[i-1]),MAX);
        }
        cout<<MAX<<endl;
        
    }
    else{
        sort(v.begin(),v.end());
        cout<<v.back()<<endl;
    }
    
    return 0;
}
