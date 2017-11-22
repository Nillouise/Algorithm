// 这种题，明显只有时把一个数分成一堆因数，接下来的所有运算都只是在因数里算而已，一定要这么想才行
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
int vis[3000];


int main()
{
    //freopen("input.txt","r",stdin);//

    ios::sync_with_stdio(false);

    cin>>n;
    set<LL> but;
    but.insert(n);
    for (LL i = 2;i*i<=n ; i++) 
    {
        if(n%i==0)but.insert(i);
    }
    int mcnt = 0;
    LL mb=0;
    for(auto a=but.begin();a!=but.end();a++)
    {
        LL t =1;
        int ct = 0;
        for(auto b=a;b!=but.end();b++)
        {
            t*= (*b);
            if(*b!= *a+ct)break;
            if(n%t==0)
            {
                ct++;
            }else
            {
                break;
            }
        }
        if(ct>mcnt)
        {
            mcnt=ct;
            mb= *a;
        }
    }
    cout<<mcnt<<endl;
    for (int i = 0; i < mcnt; i++) 
    {
        cout<<mb+i;
        if(i!=mcnt-1)cout<<"*";
    }
    cout<<endl;
    
    return 0;
}
