#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> data;
LL cnt=0;

LL get(int len)
{
    
    LL res=0;
    for(int i=1;i<=len;i++)
    {
        LL C=1;
        for(int j=len;j>len-i;j--)
        {
            C*=j;
            C=C/(len-j+1);
        }
        // cout<<"C"<<C<<endl;//
        res +=pow(9,len-i)*C*i; //这个组合数真难写对，还不如直接二项式做
        // cout<<"res"<<res<<endl;
    }
    // cout<<"len "<<len<<"res "<<res<<endl;
    return res;
}

LL dfs(int x)
{
    
    
    if(x>=data.size())return 0;
    for(int i=0;i<data[x];i++)
    {
        // cout<<"i="<<i<<"data[x]"<<data[x]<<endl;
        if(i==1)
        {
            LL c=1;
            for(int j =0;j<data.size()-1-x;j++)c*=10;//这里填错了几次标量呀
            // cout<<"c"<<c<<endl;
            cnt+=c;
        }
        //cnt+=get(data.size()-1-i);//这里不是-i，是-x才对把
        cnt+=get(data.size()-1-x);
            // cout<<"x "<<x<<"cnt"<<cnt<<endl;// 
    }
    dfs(x+1);
    if(data[x]==1)
    {
        LL c=0;
        for(int i=x+1;i<data.size();i++)
        {
            c*=10;
            c+=data[i];
        }
        // cout<<"cup "<<c<<endl;
        cnt+=c+1;
    }
       
    return 0;
}

int main()
{
//    freopen("input.txt","r",stdin);//

//    ios::sync_with_stdio(false);
//    cout<<get(2)<<endl;//
//    cout<<get(3);
    LL n;
    cin>>n;
    // n=1<<23;
    LL t = n;
    while(t)
    {
        data.push_back(t%10);
        t/=10;
    }
    //卧槽，搞了半天是忘记reverse了
    reverse(data.begin(),data.end());
    dfs(0);
    cout<<cnt<<endl;

    return 0;
}
