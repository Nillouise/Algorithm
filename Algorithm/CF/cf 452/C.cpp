#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
//    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    if(n%4==0)
    {
        cout<<0<<endl;//
        cout<<n/2<<" ";
        for (int i = 1; i < n; i+=4) 
        {
            cout<<i<<" "<<i+3<<" ";
        }
    }else if(n%4 == 1){
        cout<<1<<endl;//
        cout<<n/2<<" ";
        for (int i = 2; i < n; i+=4) 
        {
            cout<<i<<" "<<i+3<<" ";
        }
    }else if(n%4 == 2)
    {
        cout<<1<<endl;//
        cout<<n/2<<" ";
        cout<<1<<" ";
        for (int i = 3; i < n; i+=4) 
        {
            cout<<i<<" "<<i+3<<" ";
        }
    }else{
        cout<<0<<endl;//
        cout<<n/2<<" ";
        cout<<3<<" ";
        for (int i = 4; i < n; i+=4) 
        {
            cout<<i<<" "<<i+3<<" ";
        }
    }


    return 0;
}
