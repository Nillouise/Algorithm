//不分析的暴力 超时！！！
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;



int main()
{
    //freopen("input.txt","r",stdin);//

    ios::sync_with_stdio(false);

    cin>>n;
    if(n==0||n==1)return cout<<0<<endl,0;
    int mcnt=1;
    LL mb=n;
    for (LL i = 2; pow(i,mcnt) < n; i++) 
    {
        LL j;
        LL t =n;
        for(j = i;;j++)
        {
            // cout<<"i "<<i<<" "<<t<<endl;
            if(t%j == 0)t/=j;
            else break;
        }
        // cout<<"j-i "<<j-i<<endl;
        if(j-i>mcnt)
        {
            mcnt=j-i;
            mb = i;
        }
    }
    cout<<mcnt<<endl;
//    for (int i = mb; i < mcnt; i++)//啊这里很容易看错吗？ 
    for (int i = 0; i < mcnt; i++) 
    {
        cout<<mb+i;
        if(i!=mcnt-1)cout<<"*";
    }
    
    cout<<endl;
    


    return 0;
}
