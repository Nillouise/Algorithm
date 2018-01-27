#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

double DP[1010];

int main()
{
  freopen("D:\\Project\\Algorithm\\Algorithm\\Algorithm\\input.txt","r",stdin);
  int n,m;
  if(cin>>n>>m){
    memset(DP,0,sizeof(DP));
    // if(n==0&&m==0)
    //   break;
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
    int ws = word.size();
    double pos = 1.0;
    for(auto a:word){
      pos*=data[a];
    }
    DP[ws] = pos;
    
    for(int i=ws+1;i<ws*2;i++){
      DP[i]=pos+DP[i-1];
    }
    // for(int i=1;i<=m;i++)
    // {
    //   // DP[i] = pos+DP[i-1]-(pos*DP[i-ws]);
    //   cout<<"DP["<<i<<"]"<<DP[i]<<" "<<endl;
    // }
    for(int i=ws*2;i<=m;i++)
    {
      DP[i] = pos+DP[i-1]-(pos*DP[i-ws]);
      // cout<<"DP["<<i<<"]"<<DP[i]<<" "<<endl;
    }
    for(int i=1;i<=m;i++)
    {
      // DP[i] = pos+DP[i-1]-(pos*DP[i-ws]);
      cout<<"DP["<<i<<"]"<<DP[i]<<" "<<endl;
    }
  }  
}