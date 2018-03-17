#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    
    string s;
    cin>>s;
    map<char,int> m;
    for(auto a:s){
        m[a]++;
    }
    
    int ans = max(m['4'],m['7']);
    if(ans==0)cout<<-1<<endl;
    else {
        if(m['4']>=m['7'])cout<<4<<endl;
        else cout<<7<<endl;
    }
    
    
    
    return 0;
}