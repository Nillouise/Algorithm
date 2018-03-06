#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

bool check(const string &s)
{
    int i=0;
    for(auto a:s)
    {
        if(a=='(')i++;
        else i--;
        if(i<0)
        {
            cout<<"false "<<s<<endl;
            return false;
        }
    }
    return true;
}


int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    string s;
    cin>>s;
    string t = s;
    set<string> but;
    but.insert(s);
    for (int i = 0; i < s.size()-1; i++) {
        t = s;
        for(int j= i;j<s.size()-1;j++){
            swap(t[j],t[j+1]);
            if(check(t))
            but.insert(t);
        }
        t=s;
        for(int j= s.size()-2;j>=i;j--){
            swap(t[j],t[j+1]);
            if(check(t))
                but.insert(t);
        }
    }
    for(auto a:but){
        cout<<a<<endl;
    }
    cout<<but.size()-1<<endl;
    
    return 0;
}
