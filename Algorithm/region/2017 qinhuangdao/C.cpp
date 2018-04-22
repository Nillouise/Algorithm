#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

map<string,int> m;

int dfs(const string &s)
{
    auto it = m.find(s);
    if(it!=m.end()){
        return it->second;
    }
    
    string t = s;
    int cnt = 0;
    int pos=0;
    
    while(true)
    {
        if( (pos =t.find("ggg"))!=t.npos)
        {
            cnt++;
            t = t.erase(pos,3);
            continue;
        }
        if((pos=t.find("aaa"))!=t.npos) {
            cnt++;
            t = t.erase(pos,3);
            continue;
        }
        
        if((pos=t.find("ooo"))!=t.npos) {
            cnt++;
            t = t.erase(pos,3);
            continue;
        }
        break;
        
    }
    
    if(t.size()==0)
    {
        m[s]=cnt;
        return cnt;
    }
    int maxn=0;
    for(int i=0;i<t.size();i++)
    {
        string t1 = t;
        t1 = t1.erase(i,1);
        maxn= max(maxn,dfs(t1));
    }
    m[s] = cnt+maxn;
        // cout<<s<<" "<<cnt+maxn<<endl;//
    return cnt+maxn;
}


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int T;cin>>T;
    while(T--)
    {
        string s;cin>>s;
        cout<<dfs(s)<<endl;//
    }
    
    
    return 0;
}