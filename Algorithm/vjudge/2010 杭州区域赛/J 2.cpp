//概率题
//http://blog.csdn.net/JalexDooo/article/details/52107549
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
double DP[1010][50];
int f[100];

void getFail(const string &s,int *f)
{
  f[0]=0;f[1]=1;
  while（int i=1;i<s.size();i++){
    int j=f[i];
    while(j&&s[i]!=s[j])j=f[j];
    f[i+1]=s[i]==s[j]?j+1:0;
  }
}

int main() {
  
    freopen("D:\\Project\\Algorithm\\Algorithm\\Algorithm\\input.txt","r",stdin);
    int n,m;
    while(cin>>n>>m){
      memset(DP,0,sizeof(DP));
      if(n==0&&m==0)break;
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
      DP[0][0]=1;
      for(int i=0;i<m;i++){
        for(int j=0;j<word.size();j++){
          for(auto it = map.begin();it!=map.end();it++){
            int pos = j;
            while(pos&&word[j]!=it->second)pos = f[pos];
            if(word[j+1]==it->second)pos++;
            DP[i+1][pos] = DP[i][j]*data[word[j+1]];
          }
        }
      }
      double ans = 0.0;
      for(int i=0;i<=m;i++)
        ans+=DP[i][word.size()];
      cout<<ans;
      
    }
}