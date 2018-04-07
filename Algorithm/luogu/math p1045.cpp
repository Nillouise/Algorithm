#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

void mul(vector<int> &s)//错的，用快速幂
{
    int a=0;
    for(int i=0;i<s.size();i++)
    {
        if((s[i]*2+a)>9){
            s[i] = (s[i]*2+a)%10;
            a=1;
        }else{
            s[i] = s[i]*2+a;
            a=0;
        }
    }
    if(a&&s.size()<550)
    {
        s.push_back(a);
    }
}

int mul2(deque<int> &s)//错的，用公式即可算出。
{
    int a=0;
    for(int i=0;i<s.size();i++)
    {
        if((s[i]*2+a)>9){
            s[i] = (s[i]*2+a)%10;
            a=1;
        }else{
            s[i] = s[i]*2+a;
            a=0;
        }
    }
    if(s.size()>600)
    {
        s.pop_front();
    }
    if(a)
    {
        s.push_back(a);
        return 1;
    }
    return 0;
}


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> v;
    v.push_back(1);
    deque<int> v2(v.begin(),v.end());
    int cnt =  1;
    for (int i = 0; i < n; i++) {
        cnt+=mul2(v2);
    }
    for (int i = 0; i < n; i++) {
        mul(v);
    }
    // cout<<v.size()<<endl;
    cout<<cnt<<endl;
    string s;
    // s+=char(v[0]);
    v[0]--;
    for(int i=0;i<min(500,(int)v.size());i++)
    {
        s = char('0'+v[i])+s;
    }

    while(s.size()<500)
    {
        s='0'+s;
    }
    // cout<<s<<endl;
    for(int i=0;i<500;i++)
    {
        cout<<s[i];
        if(i%50==49)cout<<endl;
    }
    
    
    return 0;
}