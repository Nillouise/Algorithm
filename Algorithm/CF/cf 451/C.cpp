#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

struct Token
{
    char a;
    vector<Token*> vec;
};

void extend(Token *t,string s)
{
    if(s.size()<=0)return;
    for(auto a:t->vec)
    {
        if(a->a == s[0])
        {
            extend(a,s.substr(1));
            return;
        }
    }
    Token *nt = new Token();
    nt->a=s[0];
    t->vec.push_back(nt);
    extend(nt,s.substr(1));
}

vector<char> path;
vector<vector<char>> ans;

void dfs(Token*t)
{
    if(t->vec.size()==0)
    {
        ans.push_back(path);
        return;
    }
    for(auto a:t->vec)
    {
        path.push_back(a->a);
        dfs(a);
        path.pop_back();
    }
}

int main()
{
//    freopen("I:\Project\acm\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    map<string,vector<string>> but;
    for (int i = 0; i < n; i++) {
        string name,phone;
        int k;
        cin>>name>>k;
        for (int j = 0; j < k; j++) {
            cin>>phone;
            reverse(phone.begin(),phone.end());
            but[name].push_back(phone);
        }
    }
    
    cout<<but.size()<<endl;
    for(auto a: but)
    {
        cout<<a.first<<" ";
        vector<string> vec;
        Token *t = new Token();
        for(auto b: a.second)
        {
            extend(t,b);
        }
        ans.clear();
        path.clear();
        dfs(t);
        cout<<ans.size()<<" ";
        for(auto b:ans)
        {
            reverse(b.begin(),b.end());
            for(auto c:b)
            {
                cout<<c;
            }
            cout<<" ";
        }
        cout<<endl;
    }
    
    
    
    return 0;
}