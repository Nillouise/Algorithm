#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int N,K;
pair<LL,int> dat[100000*3];



int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    cin>>N>>K;
    LL x = 0;
    for (int i = 0; i <N; i++) {
        LL gap;string dir;
        cin>>gap>>dir;
        if(dir=="R")
        {
            dat[i*2] = {x,0};
            dat[i*2+1] = {x+gap,1};
            x+=gap;
        }else{
            dat[i*2] = {x,1};
            dat[i*2+1] = {x-gap,0};
            x-=gap;
        }
    }
    sort(dat,dat+2*N);
    // for(int i=0;i<2*N;i++)
    // {
    //     cout<<dat[i].first<<" ";
    // }
    int c = 0;
    LL ans = 0;
    LL prex = 0;
    for (int i = 0; i < 2*N; i++) {
        if(c>=K)
        {
            ans+= dat[i].first-prex;
        }
        prex = dat[i].first;
        if(dat[i].second==0)
        {
            c++;
        }else{
            c--;
        }
    }
    cout<<ans<<endl;//
    
    
    
    return 0;
}