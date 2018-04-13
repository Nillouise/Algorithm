#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL K,M;

int cmp(LL x,LL y)
{
    stringstream ss,ss2;
    ss<<x;
    string s1,s2;
    ss>>s1;
    ss2<<y;
    ss2>>s2;
    // cout<<s1<<" s2 "<<s2<<endl;//
    return s1<s2;
}


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    cin>>K>>M;
    LL cnt = 0;
    LL cur = 1;
    LL res = 0;
    while(cnt<M)
    {
        LL x = 1;
        int flag=1;
        while(cmp(x*cur,K))
        {
            cnt+=cur;
            x++;
            flag=0;
        }
        // cout<<"cur"<<cur<<endl;//
        res = cur*(x);
        if(cnt>=M)break;
        
        if(flag){
            cout<<"0"<<endl;
            return 0;
        }
        cur*=10;
    }
    // cout<<M<<" "<<cnt<<" "<<res<<endl;//
    cout<<res-(cnt-M)-2<<endl;
    
    
    return 0;
}