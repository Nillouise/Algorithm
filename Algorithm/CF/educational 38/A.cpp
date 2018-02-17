#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

bool isv(char x)
{
    string s = "aeiouy";
    return s.find(x)<s.npos;
}


int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<s.size();)
    {
        if(!isv(s[i])){
            cout<<s[i];
            i++;
        }
        else{
            int j = i+1;
            while(j<s.size()&&isv(s[j]))j++;
            cout<<s[i];
            i = j;
        }
    }
    
    
    return 0;
}
