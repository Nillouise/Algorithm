#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int N;
int dat[100];


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    cin>>N;
    for (int i = 0; i < N; i++) {
        cin>>dat[i];
    }
    int forward=0,back=0;
    for (int i = 0; i < N; i++) {
        if(dat[i]==0)break;
        forward++;
    }
    for (int i = N-1; i >=0; i--) {
        if(dat[i]==0)break;
        back++;
    }
    
    if(forward%2==1||back%2 == 1)
    {
        return cout<<"YES"<<endl,0;
    }else{
        return cout<<"NO"<<endl,0;
    }
    
    
    return 0;
}