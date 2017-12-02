//这题的重点是对字符串的拼接缩减，以及怎么用bitset去表示数的长度
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 14;


struct Token
{
    string pre,suf;
    int len;
    bitset<(1<<(maxn+1))> but;
};
int span[maxn+2];


int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    
    int m=1;
    for (int i = 0; i < maxn+2; i++) 
    {
        span[i]=m;
        m= m+(1<<i);
    }
    
    int n;
    cin>>n;
    vector<Token> vec;
    for (int i = 0; i < n; i++) 
    {
        string s;
        cin>>s;
        Token t;
        t.but.reset();
        for (int i = 0; i < s.size(); i++) 
        {
            int val = 0;
            for (int j = i; j < s.size()&& j-i+1<=maxn; j++) 
            {
                int mask = span[j-i+1];
                val=val*2+s[j]-'0';
                t.but.set(mask+val);
            }
        }
        t.len = s.size();
        if(t.len>=maxn)
        {
            t.pre = s.substr(0,maxn);
            t.suf = s.substr(s.size()-maxn,maxn);
        }else{
            t.pre = s;
            t.suf = s;
        }
        vec.push_back(t);
    }
    int K;
    cin>>K;
    while(K--)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        
        Token t;
        t.len = vec[u].len+vec[v].len;
        string s = vec[u].suf+vec[v].pre;
        t.but = vec[u].but|vec[v].but;//看看这里的操作
        
        for (int i = 0; i < s.size(); i++) 
        {
            int val=0;
            for (int j = i; j < s.size()&& j-i+1<=maxn; j++)//这里不小心就超出了span的长度了 
            {
                int mask = span[j-i+1];
                val=val*2+ s[j]-'0';
                t.but.set(val+mask);
            }
        }
        if(vec[u].pre.size()>=maxn)
        {
            t.pre = vec[u].pre;
        }else{
            t.pre = s.substr(0,maxn);
        }
        if(vec[v].suf.size()>=maxn)
        {
            t.suf = vec[v].suf;
        }else{
            t.suf = s.substr(max(0,(int)s.size()-maxn));
        }
        vec.push_back(t);
        int res=0;
        for (int i = 1; i <= maxn; i++) 
        {
            int flag=1;
            for (int j =span[i]; j < span[i+1]; j++) 
            {
                flag = flag & (t.but[j]);
            }
            if(flag)res = i;
        }
        cout<<res<<endl;
    }
    
    
    
    return 0;
}
