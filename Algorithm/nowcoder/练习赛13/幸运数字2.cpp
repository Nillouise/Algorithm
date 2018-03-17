#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL nxt(LL x)
{
    LL t =x;
    LL b=0;
    for(int i=0;;i++){
        if(x%10==7){
            b=b| (1LL<<i);
        }
        x/=10;
        if(x==0)break;
    }
    b++;
    x=t;
    int flag=0;
    while(x){
        if(x%10==4){flag=1;break;}
        x/=10;
    }
    if(flag==0){
        b=0;
    }
    LL r = 0;
    for(int i=0;r<=t;i++){
        if(b&(1LL<<i)){
            r= r+(int)pow(10,i)*7;
        }else{
            r=r+(int)pow(10,i)*4;
        }
    }
    return r;
}

bool chk(LL x)
{
    while(x){
        if(x%10!=4&&x%10!=7)return false;
        x/=10;
    }
    return true;
}

LL nxt2(LL x)
{
    for(LL i =x;;i++)
    {
        if(chk(i))return i;
    }
}

int main()
{
    // freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int l,r;
    cin>>l>>r;
    LL pre = nxt2(l);
    vector<LL> vec;
    vec.push_back(pre);
    while(true)
    {
        LL n = nxt(vec.back());
        vec.push_back(n);
        if(n>r)break;
    }
    LL ans = pre*(pre-l+1);
    
    
    
    return 0;
}