#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int n;
        cin>>n;
        int dat[4]={0};
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            if(a&1){
                dat[0]++;
            }else if(a%4==0){
                dat[2]++;
            }else if(a%2==0){
                dat[1]++;
            }
        }
        if(dat[0]<=dat[2]){
            cout<<"Yes"<<endl;
        }else if(dat[0]==dat[2]+1){
            if(dat[1]==0){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }else{
            cout<<"No"<<endl;
        }
        
    }
    
    
    return 0;
}
