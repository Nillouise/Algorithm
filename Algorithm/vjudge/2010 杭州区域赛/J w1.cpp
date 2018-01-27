#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
double DP[1010];

int main()
{
  freopen("D:\\Project\\Algorithm\\Algorithm\\Algorithm\\input.txt","r",stdin);
  int n,m;
  while(cin>>n>>m){
    memset(DP,0,sizeof(DP));
    for(int i=0;i<1010;i++){
      DP[i] = 0.0;
    }
    if(n==0&&m==0)
      break;
    map<char,double> data;
    for(int i=0;i<n;i++)
    {
      char c;
      double p;
      cin>>c>>p;
      data[c]=p;  
    }
    string word;
    cin>>word;
    double pos = 1.0;
    for(auto a:word){
      data[]
    }
    int ws = word.size();
    for(int i=1;i<=m;i++){
      for(int j=1;j<=ws;j++)
      {
        DP[i][j] = DP[i-1][j-1]* data[word[j-1]];  
      }
    }
    double ans = 0;
    for(int i=1;i<=m;i++){
      cout<<" + "<<DP[i][ws]<<" ";//
      ans+=DP[i][ws];
    }
    double none = 1;
    for(int i=1;i<=m;i++){
      none*=1.0-DP[i][ws];
    }
    cout<<"none "<<none<<" "<<1-none<<endl;//
    cout<<endl;//
    cout<<ans<<endl;
  }  
}