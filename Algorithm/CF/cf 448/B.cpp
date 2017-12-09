#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    vector<int> dat(n);
    for (int i = 0; i < n; i++) 
    {
        cin>>dat[i];
    }
    
    set<int> s1;
    s1.insert(0);
    for (int i = 0; i < n; i++) 
    {
        set<int> s2=s1;
        // s2.insert(0);
        for(auto a:s1)
        {
            // cout<<a<<endl;//
            s2.insert(dat[i]+a);
        }
        s1 = s2;
    }
    // cout<<"osdfs"<<endl;
    // for(auto a:s1)cout<<a<<" ";
    auto it = s1.lower_bound(180);
    cout<<abs(*it-(360-*it));
    

    return 0;
}
