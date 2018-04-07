#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int N,M;
    int x;
    vector<int> dat;
    cin>>N>>M;
    for (int i = 0; i < N; i++) {
        cin>>x;
        dat.push_back(x);
    }
    do {
        if(M==0)break;
        M--;
        
    } while(next_permutation(dat.begin(),dat.end()));
    for(auto a:dat)
    {
        cout<<a<<" ";
    }
    cout<<endl;
    
    return 0;
}