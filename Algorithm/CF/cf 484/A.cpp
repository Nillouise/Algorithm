#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int n;cin>>n;
    string s;
    cin>>s;
    s='0'+s+'0';
    
    for(int i=1;i<s.size()-1;i++){
        if(s[i]=='1'&&s[i+1]=='1'){
            cout<<"No"<<endl;
            return 0;
        }
    }
    
    
    for(int i=1;i<s.size()-1;i++){
        if(s[i]=='0'&&s[i-1]=='0'&&s[i+1]=='0'){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    
    
    return 0;
}