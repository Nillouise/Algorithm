#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    LL X,d;
    cin>>X>>d;
    LL b = 1;//被爆int 了!!!!!
    vector<LL> ans;
    for (int i = 0; i < 32; i++) {
        if(X&(1<<i))
        {
            for(int j=0;j<i;j++)
            {
                ans.push_back(b);
            }
            ans.push_back(b+d);
            b+=2*d;
        }
    }
    cout<<ans.size()<<endl;
    for(auto a:ans)
    {
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}