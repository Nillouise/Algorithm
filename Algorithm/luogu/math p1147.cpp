#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int pre[10000];


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    for (int i = 1; i < 10000; i++) {
        pre[i]=pre[i-1]+i;
        if(pre[i]> 2000000)
        {
            break;
        }
    }
    int M;
    cin>>M;
    vector<pair<int,int>> ans;
    int up = 1;
    for (int i = 2; ; i++) {
        int t = M- pre[i];
        if(t%i==0)
        {
            ans.push_back({t/i+1,t/i+i});
        } 
        if(pre[i]>M)break;
    }
    
    sort(ans.begin(),ans.end());
    for(auto a:ans)
    {
        cout<<a.first<<" "<<a.second<<endl;
    }
    
    
    return 0;
}