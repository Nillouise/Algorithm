#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

struct Token
{
  LL X=-1;
  LL Y=-1;
  LL Z=-1;
  void set(char i,LL cnt){
    if(i=='X'){
      X=cnt;
    }else if(i=='Y'){
      Y=cnt;
    }else if(i=='Z'){
      Z=cnt;
    }
  }
  Token(){}
  Token(LL X,LL Y,LL Z):X(X),Y(Y),Z(Z){}
  bool operator<(Token&t){
    if(X<t.X)return true;
    else if(X==t.X){
      return make_pair(Y,Z)<make_pair(t.Y,t.Z);
    }else{
      return false;
    }
  }
  bool operator==(Token&t)
  {
    return X==t.X&&Y==t.Y&&Z==t.Z;
  }
};

int main()
{
 freopen("D:\\Project\\Algorithm\\Algorithm\\Algorithm\\input.txt","r",stdin);
  int T;
  cin>>T;
  while (T--) {
    int n,m;
    cin>>n>>m;
    string tmp;
    getline(cin,tmp);
    std::vector<Token> vec;
    for(int i=0;i<m;i++)
    {
      string s;
      getline(cin,s);
      Token t;
      int p = s.find(",");
      string pre = s.substr(2,p-2);
      string suf = s.substr(p+3);
      stringstream ssp(pre);
      stringstream ssf(suf);
      LL a,b;
      ssp>>a;
      ssf>>b;
      // cout<<"a "<<a<<endl;
      // cout<<"b "<<b<<endl;
      // cout<<"s[0] "<<s[0]<<" a "<<a<<endl;
      // cout<<"s[p+1]"<<s[p+1]<<" b "<<b<<endl;//
      t.set(s[0],a);
      t.set(s[p+1],b);
      if(a<1||a>n)continue;
      if(b<1||b>n)continue;
      vec.push_back(t);
    }
    set<Token> but;
    LL total = vec.size()*n;
    vector<Token> data;
    for(auto &a:vec){
      if(a.X == -1)
      {
          for(LL i=1;i<=n;i++){
            data.push_back(Token(i,a.Y,a.Z));
          }
      }else if(a.Y==-1)
      {
          for(LL i=1;i<=n;i++){
            data.push_back(Token(a.X,i,a.Z));
          }
      }else if(a.Z==-1)
      {
            for(LL i=1;i<=n;i++){
              data.push_back(Token(a.X,a.Y,i));
            }
      }
    }
    sort(data.begin(),data.end());
    LL ans = unique(data.begin(),data.end())-data.begin();
    // for(int i=0;i<vec.size();i++){
    //   for(int j=i+1;j<vec.size();j++){
    //     int cc = 0;
    //     if(vec[i].X==vec[j].X && vec[i].X!=-1)cc++;
    //     if(vec[i].Y==vec[j].Y && vec[i].Y!=-1)cc++;
    //     if(vec[i].Z==vec[j].Z && vec[i].Z!=-1)cc++;
    //     if(cc==1)total--;
    //     else if(cc==2)total-=n;
    //   }
    // }
    cout<<ans<<endl;
    
  }
}