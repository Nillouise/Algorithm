//这种题目要考虑1才行
//这么枚举会超时是因为，最多只需要枚举到i*i,防止因为输入的数是质数导致的超时，这是很重要的！！
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    freopen("input.txt","r",stdin);//

    ios::sync_with_stdio(false);

    LL n;
    cin>>n;
    LL t = n;
    map<LL,int> but;
    while(t%2==0)
    {
        but[2]++;
        t/=2;
    }
    int first=true;
    //这么枚举会超时是因为，最多只需要枚举到i*i,防止因为输入的数是质数导致的超时
    // for (LL i = 2; t!=1; i+=1) 
    for (LL i = 3; t>=i*i; i+=2) 
    {
        while(t%i==0){
            t/=i;
            but[i]++;
        }
    }
    if(t>1)but[t]++;
    
    vector<pair<LL,LL> > ans;
    for(auto a:but)
    {
        ans.push_back({a.first,a.second});
    }
    cout<<n<<"=";
    if(n==1)return cout<<1<<endl,0;//这种题目要考虑1才行
    for (int i = 0; i < ans.size(); i++) 
    {
        cout<<ans[i].first;
        if(ans[i].second>1)cout<<"^"<<ans[i].second;
        if(i!=ans.size()-1)cout<<"*";
    }
    cout<<endl;

    return 0;
}
