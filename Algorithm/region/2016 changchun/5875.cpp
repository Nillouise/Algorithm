#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int T;
    while(cin>>T)
    {
        while(T--)
        {
            LL M;cin>>M;
            vector<int> dat(M);
            for (int i = 0; i < M; i++) {
                cin>>dat[i];
            }
            sort(dat.rbegin(),dat.rend());
            LL total = 0;
            for(auto a:dat){
                total+=a;
            }
            if(total!=M*(M-1)){
                cout<<"F"<<endl;
                continue;
            }
            LL v = M*(M-1);
            int flag=1;
            int mid = 0;
            
            
            
            if(flag==1){
                cout<<"T"<<endl;
            }else{
                cout<<"F"<<endl;
            }
            
        }    
    }
    
    
    return 0;
}