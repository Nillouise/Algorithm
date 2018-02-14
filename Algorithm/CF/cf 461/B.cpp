#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
  //  freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    LL n;
    cin>>n;
    LL res = 0;
    for(int i=1;i<=n;i++){
      for(int j=i-1;j>= (i-j);j--){
        if(j>=(j^i)&&(j+(j^i))>i ){
          res++;
          // cout<<i<<" "<<j<<endl;//
        }
      }
    }
    cout<<res;
}
