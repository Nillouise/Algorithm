#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    vector<int> data;
    int b = 1,e = 1000000;
    int MAX = 0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        data.push_back(a);
        int l = a-1,r = e-a;
        // cout<<"l "<<l<<" r "<<r<<endl;//
        MAX = max(MAX,min(l,r));
        
        // MAX = max(MAX,e-a);
    }
    cout<<MAX<<endl;
    
    return 0;
}
