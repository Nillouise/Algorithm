//这题要校验 m* (n/m) != n
//比如99/45 = 2,但99/2 == 49;
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int t;
    cin>>t;
    while(t--)
    {
        LL x;
        cin>>x;
        int flag=0;
        //2*x+1是为了防止x为0
        for(LL n = sqrt(x)+1;n*n<=2*x+1;n++)
        {
            LL m0 = sqrt( n*n - x);
            if(m0*m0+x!=n*n)continue;
            LL m = n/m0;
            // if(n/m!=m0)continue;
            // if(n*n - (n/m) *(n/m) !=x)
            //为什么会这样？因为类型转换
            if(m0!=n/m)
            {
                cout<<"n "<<n<<" m0 "<<m0<<" m "<<m<<" n/m "<<n/m<<endl;
                cout<<"n*n "<<n*n<<" m "<<m<<" x+(n/m)*(n/m) "<<x+(n/m)*(n/m)<<endl;
                continue;
            }
            // cout<<n<<" "<<m<<endl;
            flag=1;
            break;
        }
        if(!flag)
        {
            cout<<-1<<endl;
        }
    }
    
    
    return 0;
}
