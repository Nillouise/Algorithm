#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> G[60];
int main()
{
//  freopen("D:\\Project\\Algorithm\\Algorithm\\Algorithm\\input.txt","r",stdin);
  int n,m;
  while(cin>>n>>m)
  {
    if(n==0||m==0)break;
    // if(n==1){
    //   cout<<0<<endl;
    //   continue;
    // }
    for(int i=0;i<n*n;i++){
      int x,y;
      cin>>y>>x;
      G[y-1].push_back(x-1);
    }
    for(int i=0;i<n;i++){
      sort(G[i].begin(),G[i].end());
    }
    LL MIN = 1e15;
    // cout<<MIN<<endl;//
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        int off = G[i][j]-j;
        if(off<0|| (m-G[i][j]-1< n-j-1))
          continue;
        LL cur = 0;
        for(int k=0;k<n;k++){
          for(int l=0;l<n;l++){
            cur+= abs((off+l) - G[k][l]);
          }
        }
        if(MIN>cur)MIN = cur;
      }
    }
    for(int i=0;i<n;i++)
    {
      G[i].clear();
    }
    cout<<MIN<<endl;
  }
    
}