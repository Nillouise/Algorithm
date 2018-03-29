#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int ans[10000];
vector<int> vec;

bool dfs(int dep,int rem)
{
    if(rem==0){
        return true;
    }
    if(rem&1){
        vec.push_back(1);
        return dfs(dep+1,(rem-1)/2);
    }else{
        vec.push_back(2);
        return dfs(dep+1,(rem-2)/2);
    }
}


int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    LL n;
    cin>>n;
    dfs(0,n);
    for(auto a=vec.rbegin();a!=vec.rend();a++){
        cout<<*a;
    }
    cout<<endl;
    
    return 0;
}
