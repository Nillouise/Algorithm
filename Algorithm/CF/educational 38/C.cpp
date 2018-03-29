#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<LL> sq;

inline bool check(LL n,LL x)
{
    LL s = sqrt(n-x);
    
    if(s*s+x==n&&x!=n &&s<=sqrt(n)/2+1)
    {
        // cout<<"check "<<n<<" "<<x<<endl;//
        return true;
    }
    return false;
}

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    // for(LL i=1;i*i<=1e13;i++)
    // {
    //     sq.push_back(i*i);
    // }
    // cout<<sq.back()<<endl;//
    LL n;
    cin>>n;
    for(int t=0;t<n;t++)
    {
        LL x;
        cin>>x;
        LL b = sqrt(x)+1;
        int flag =0;
        while(b*b<=x*2+1)
        {
            
            if(check(b*b,x))
            {
                LL sma = sqrt(b*b-x);
                cout<<b<<" "<<b/ sma<<endl;
                flag=1;
                break;
            }
            b++;
        }
        if(!flag)cout<<-1<<endl;
    }
    
    
    
    return 0;
}
