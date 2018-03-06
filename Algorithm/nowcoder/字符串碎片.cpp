#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

map<char,int> dat;


int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    string s;
    cin>>s;
    pair<char,int> pp={0,0};
    int cnt = 0;
    double total =0.0;
    for(auto a:s){
        if(a==pp.first){
            pp.second++;
        }else{
            if(pp.first!=0)
                dat[pp.first] = max(pp.second,dat[pp.first]);
            total+=pp.second;
            pp.first = a;
            pp.second = 1;
            cnt++;
        }
    }
    dat[pp.first] = max(pp.second,dat[pp.first]);
    total+=pp.second;

    // cout<<res<<endl;
    printf("%.2lf\n",total/cnt);
    
    return 0;
}
