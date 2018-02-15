#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

//这题涉及正负号的最大数，必有坑


int main()
{
    //freopen("D:\\Project\\Algorithm\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    LL n,m;
    cin>>n>>m;
    vector<LL> A(n),B(m);
    for(auto &a:A)
    {
        cin>>a;
    }
    for(auto&a:B)
    {
        cin>>a;
    }
    LL MAX = 0;
    vector<LL> C;
    for(auto a:A)
    {
        vector<LL> tmp;
        for(auto b:B)
        {
            tmp.push_back(a*b);
        }
        sort(tmp.rbegin(),tmp.rend());
        C.push_back(tmp[0]);
    }
    sort(C.rbegin(),C.rend());
    cout<<C[1]<<endl;
    
    
    return 0;
}
