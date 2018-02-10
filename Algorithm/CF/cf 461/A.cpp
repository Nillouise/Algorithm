#include<bits/stdc++.h>
using namespace std;
typedef long long LL;



int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    
    LL n,m;
    cin>>n>>m;
    LL p = m-1;
    LL r = n-p;
    if(n<m-1){
      
    }
    
    if(r<0){
      cout<<"No"<<endl;
      return 0;      
    }
    if(m==1&&r>0){
      cout<<"No"<<endl;
      return 0;
    }
    
    if(r>=0&&r%2){
      cout<<"No"<<endl;
      return 0;
    }else{
      cout<<"Yes"<<endl;
    }
    
    return 0;
}
