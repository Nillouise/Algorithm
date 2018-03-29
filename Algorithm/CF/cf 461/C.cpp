#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
  //  freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    LL n,m;
    cin>>n>>m;
    for(LL i=2;i<=m;i++){
      if(n%i!=i-1){
        cout<<"No"<<endl;
        return 0;
      }
    }
    cout<<"Yes"<<endl;
    return 0;
}
