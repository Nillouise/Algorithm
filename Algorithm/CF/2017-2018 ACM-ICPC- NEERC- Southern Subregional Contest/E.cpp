#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int n,m;
    cin>>n;
    string hid;
    cin>>hid;
    set<char> reveal;
    for(auto a:hid)
    {
        if(a!='*')
            reveal.insert(a);
    }
    cin>>m;
    int matchcnt=0;
    map<char,int> M;
    for (int i = 0; i < m; i++) {
        string s;
        cin>>s;
        int flag=1;
        for(int i=0;i<s.size();i++)
        {
            if(hid[i]!='*'&&hid[i]!=s[i])flag=0;
            if(hid[i]=='*'&&reveal.find(s[i])!=reveal.end())flag=0;
        }
        if(flag)
        {
            matchcnt++;
            for(char a='a';a<='z';a++)
            {
                if(reveal.find(a)==reveal.end()&&s.find(a)!=s.npos){
                    M[a]++;
                }
            }
            
        }
    }
    int cnt=0;
    for(auto a:M)
    {
        if(a.second==matchcnt)cnt++;
    }
    cout<<cnt<<endl;
    
    return 0;
}
