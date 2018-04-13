#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    set<string> dat;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) {
        string x;cin>>x;
        std::transform(x.begin(), x.end(), x.begin(), ::tolower);
        dat.insert(x);
    }
    string s;
    int ans = 0;
    getline(cin,s);
    getline(cin,s);
    string cur;
    vector<string> sen;
    for(auto a :s)
    {
        if(a==' '||isdigit(a)||a==',')
        {
            if(cur.size()!=0)
                sen.push_back(cur);
            cur="";
        }else if(a=='.')
        {
            if(cur.size()!=0)
            sen.push_back(cur);
            cur="";
            set<string> tmp = dat;
            for(auto x:sen)
            {
                std::transform(x.begin(), x.end(), x.begin(), ::tolower);
                if(tmp.find(x)!=tmp.end())
                {
                    ans++;
                    tmp.erase(x);
                }
            }
            sen.clear();
        }else{
            cur+=a;
        }
    }
    set<string> tmp = dat;
    sen.push_back(cur);
    for(auto x:sen)
    {
        std::transform(x.begin(), x.end(), x.begin(), ::tolower);
        if(tmp.find(x)!=tmp.end())
        {
            ans++;
            tmp.erase(x);
        }
    }
    
    
    

    cout<<ans<<endl;//
    
    return 0;
}