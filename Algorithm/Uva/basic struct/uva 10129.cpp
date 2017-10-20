//注意指向自己的边
#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > vertice(30,vector<int>(30,0));
vector<vector<int> > G(30,vector<int>(30,0));
int vis[30];
int dfs(int x)
{
      int flag=0;
    //重点
    if(G[x][x]&&vis[x]==0)flag=1;
  vis[x]=1;
  for (size_t i = 0; i < 26; i++) {
   if(G[x][i]&&vis[i]==0)
    {
      flag=1;
      dfs(i);
    }
  }
  return flag;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  ios::sync_with_stdio(false);
  int T;
  cin>>T;
  while(T--)
  {
    int n;
    cin>>n;
    vector<vector<int> > temp(30,vector<int>(30,0));
    memset(vis,0,sizeof(vis));
    vertice.clear();
    G.clear();
    vertice.assign(temp.begin(),temp.end());
    G.assign(temp.begin(),temp.end());

    for (size_t i = 0; i < n; i++) {
      string s;
      cin>>s;
      s[0]-='a';
      s.back()-='a';

      G[s[0]][s.back()]=1;
      G[s.back()][s[0]]=1;
      vertice[s[0]][s.back()]++;
    }
    int cnt=0;
    for (size_t i = 0; i < 26; i++) {
      if(vis[i]==0)
      cnt+=dfs(i);
    }
    if(cnt>1){
      cout<<"The door cannot be opened."<<endl;
    }else{
      int flag=1;
      int tout=0,tin=0;
      for (size_t i = 0; i < 26; i++) {
        int in=0,out=0;
        for (size_t j = 0; j < 26; j++) {
          out+=vertice[i][j];
          in+=vertice[j][i];
        }
        if(abs(out-in)>1)
        {
          flag=0;
        }else{
          if(out-in==1)tout++;
          if(in-out==1)tin++;
        }
      }
      if(tout!=tin)flag=0;
      else if(tout>1)flag=0;

      if(flag)
      {
        cout<<"Ordering is possible."<<endl;
      }else{
        cout<<"The door cannot be opened."<<endl;
      }
    }
  }

}
