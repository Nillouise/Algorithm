#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int i=0;
    for(;i<s.size();i++)
    {
        if(s[i]!='a')
            break;
    }
    if(i==0){
        cout<<"NO"<<endl;
        return 0;
    }
    int a = i;
    for(;i<s.size();i++)
    {
        if(s[i]!='b')
            break;
    }
    if(a==i)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    int b = i-a;
    for(;i<s.size();i++)
    {
        if(s[i]!='c')
            break;
    }
    if(i!=s.size()){
        cout<<"NO"<<endl;
        return 0;
    }
    int c = i - b-a;
    // cout<<a<<" "<<b<<" "<<c<<endl;
    if(a==c||b==c)
    {
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    
    
    return 0;
}