#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
//这题居然可以直接用LIS或者算 是不是必要删 某个数。
vector<int> dat(200000);
vector<int> tmp(200000);

bool solve(int n)
{
    int pre = 1;
    for(;pre<n;pre++)
    {
        if(dat[pre-1]>dat[pre]){
            pre--;break;
        }
    }
    int suf = n-1;
    for(;suf>=0;suf--)
    {
        if(dat[suf]<dat[suf-1])
        {
            break;
        }
    }
    // cout<<pre<<suf<<endl;//
    if(pre>=suf){
        return true;
    }else if(suf - pre == 1){
        if((dat[pre-1]<=dat[suf])||( dat[pre]<=dat[suf+1]))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int T;cin>>T;
    while(T--)
    {
        int n;cin>>n;
        for (int i = 1; i <= n; i++) {
            cin>>dat[i];
            tmp[i] = dat[i];
        }
        dat[0]=0;
        dat[n+1]=1e8;
        if(solve(n+2))
        {
            cout<<"YES"<<endl;
        }else{
            reverse(dat.begin(),dat.begin()+n+2);
            dat[0] = 0;dat[n+1]=1e8;
            if(solve(n+2)){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
        
        
    }
    
    
    return 0;
}