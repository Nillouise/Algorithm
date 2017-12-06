//unsigned long long 不支持20位数 （1e20是不行的）
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;




int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    unsigned long long a;
    cin>>a;
    unsigned long long b = a*2;
    vector<int> v1;
    while(a)
    {
        v1.push_back(a%10);
        a/=10;
    }
    vector<int> v2;
    unsigned long long t = b;
    while(b)
    {
        v2.push_back(b%10);
        b/=10;
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int flag=1;
    if(v1.size()!=v2.size())flag=0;
    for (int i = 0; i < v1.size(); i++) 
    {
        if(v1[i]!=v2[i])flag=0;
    }
    if(flag)
    {
        cout<<"Yes"<<endl;
    }else
    {
        cout<<"No"<<endl;
    }
    cout<<t<<endl;


    return 0;
}
