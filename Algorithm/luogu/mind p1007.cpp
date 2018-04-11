#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int L,N;
    cin>>L>>N;
    vector<int> vec;
    int x;
    for (int i = 0; i < N; i++) {
        cin>>x;
        if(x<1||x>L)continue;
        vec.push_back(x);
    }
    if(vec.size()==0){cout<<"0 0"<<endl;return 0;}
    sort(vec.begin(),vec.end());
    int mid = 0;
    for(auto a:vec)
    {
        mid = max(mid,min(a,L-a+1));
    }
    cout<<mid<<" "<<max(L- *vec.begin()+1,(vec.back()))<<endl;
    
    
    return 0;
}