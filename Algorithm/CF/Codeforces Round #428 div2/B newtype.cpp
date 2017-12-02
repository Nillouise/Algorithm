#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);

    int n,k;
    cin>>n>>k;
    vector<int> data(k);
    for (int i = 0; i < k; i++) 
    {
        cin>>data[i];
    }
    int sit2=n*2,sit4=n;
    for(auto &a:data)
    {
        int ocu = a/4;
        int cut = min(sit4,ocu);
        a-=cut*4;
        sit4-=cut;
    }
    for(auto &a:data)
    {
        int ocu = a/2;
        int cut = min(sit2,ocu);
        a-=cut*2;
        sit2-=cut;
    }
    //这时合法的剩余人数是1，2，3，而有2，3剩余就表明他们一定要放到sit4里，而剩余1的话可以放到sit2,也可以放到sit4
    for(auto &a:data)
    {
        if(a==3&&sit4>0)
        {
            sit4--;
            a-=3;
        }
    }
    int sit1=0;
    for(auto &a:data)
    {
        if(a==2&&sit4>0)
        {
            sit4--;
            sit1++;
            a-=2;
        }
    }
    for(auto& a:data)
    {
        if(a==1&&sit4>0)
        {
            a-=1;
            sit4--;
            sit2++;
        }
    }
    
    for(auto&a:data)
    {
        if(a==1&&sit1>0)
        {
            a-=1;
            sit1--;
        }
    }
    for(auto&a:data)
    {
        if(a==1&&sit2>0)
        {
            a-=1;
            sit2--;
        }
    }
    for(auto a:data)
    {
        if(a!=0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;

    return 0;
}
