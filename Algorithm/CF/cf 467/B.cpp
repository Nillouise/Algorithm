#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    LL p,y;
    cin>>p>>y;
    LL i;
    for(i = y;i>p;i--){
        int flag=0;
        LL up = min(p,LL(sqrt(y)+1));
        for(LL j = 2;j<=up;j++)
        {
            if(i%j==0){
                flag=1;
                break;
            }
        }
        if(!flag){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    
    
    return 0;
}
