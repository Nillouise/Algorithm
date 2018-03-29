#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    LL k,d,t;
    cin>>k>>d>>t;
    
    // if(d==k)
    if(k%d==0)
    {
        double ans = t;
        printf("%.1lf\n",ans);
    }else if(d<k)
    {
        LL r = (k/d+1)*d;
        LL r1 = (k/d+1)*d;
        r+=k;
        
        LL num = (2*t)/r;
        LL rem = (2*t)%r;
        
        if(rem>k*2){
            double ans = rem-k*2;
            ans+=num*r1;
            ans+=k;
            printf("%.1lf\n",ans);
        }else{
            double ans = rem;
            ans/=2;
            ans+=num*r1;
            printf("%.1lf\n",ans);
        }
        
    } else{
        LL r = k*2 +(d-k);
        LL num = (2*t)/r;
        LL rem = (2*t)%r;
        if(rem<=2*k)
        {
            double ans = rem;
            ans/=2;
            ans+=num*d;
            printf("%.1lf\n",ans);
        }else{
            double ans = rem - k*2;
            ans+=k;
            ans+=num*d;
            printf("%.1lf\n",ans);
        }
        
    }
    
    
    return 0;
}
