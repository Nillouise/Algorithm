#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int x=0;
    for(auto a:s)
    {
        if(a=='(')
        {
            x++;
        }else if(a==')'){
            x--;
            if(x<0){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    if(x!=0)
    {
        cout<<"NO"<<endl;
        return 0;
    }else{
        cout<<"YES"<<endl;
    }
    
    
    
    return 0;
}