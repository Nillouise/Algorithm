#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef __int128 LLL;
// 买彩票那题，算a*(a-1)/b*(b-1)=1/2，是找规律的题目。其中b*(b-1)这个值会增大33.97倍。

ostream& operator<<(ostream& out,LLL a)
{
    vector<int> vec;
    while(a){
        vec.push_back(a%10);
        a/=10;
    }
    reverse(vec.begin(),vec.end());
    for(auto a:vec){
        out<<a;
    }
    return out;
}

LLL sqrt(LLL x)
{
    LLL be=1,en=1e18;
    while(be<en-1){
        LLL mid = (be+en)>>1;
        if(mid*mid>x)
        {
            en=mid;
        }else{
            be = mid;
        }
    }
    return be;
}

vector<int> p;

void prim(LLL x)
{
    cout<<x<<"\t";
    for(auto i:p){
        while(x%i==0){
            cout<<i<<" ";
            x/=i;
        }
    }
    cout<<endl;//
}

int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    for (int i = 2; i < 100000; i++) {
        int flag=0;
        for (int j = 2; j < i; j++) {
            if(i%j==0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            p.push_back(i);
        }
    }
    
    LLL pre = 1;
    ios::sync_with_stdio(false);
    for (LLL i = 1; i < 1e14; i++) {
        LLL up = i*(i-1)/2;
        LLL up1 = sqrt(up);
        if(up1*up1+up1 == up){
            // cout<<i<<endl;
            prim(i);
            prim(i-1);
            prim(i*i-i);
            cout<< (1.0*i*i-i)/(1.0*pre);
            pre = i*i-i;
            LLL M = 33*pre+(LLL)(0.97*pre);
            i = sqrt(M);
            cout<<endl;
            cout<<"M "<<M<<endl;
            cout<<"next "<<i;
            cout<<endl;
            cout<<endl;//
        }
    }
    
    
    return 0;
}