//这题算的条件还是挺复杂的，你再做也不一定能做对，我觉得这种题目要总结一下才行
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string a,b;
vector<char> ans;
map<char,int> but;

int dfs(int p,int flag)
{
  if(p==a.size())return 1;
  for(char i = '9';i>='0';i--){
    if(but[i]==0)continue;
    if(flag==1){
      but[i]--;
      ans.push_back(i);
      dfs(p+1,1);
      but[i]++;
      return 1;
    }else if(i>b[p]){
      continue;
    } else if(i<b[p]){
      but[i]--;
      ans.push_back(i);
      if(dfs(p+1,1))
      {
        but[i]++;
        return 1;
      }
    }else if(i==b[p])
    {
      ans.push_back(i);
      but[i]--;
      if(dfs(p+1,0))
      {
        return 1;
      }
      ans.pop_back();
      but[i]++;
    }
  }
  return 0;
}

int main()
{
  cin>>a>>b;
  if(b.size()>a.size()){
    std::vector<char> v;
    for(auto aa:a)v.push_back(aa);
    sort(v.begin(),v.end());
    for(auto i = v.rbegin();i!=v.rend();i++){
      cout<<*i;
    }
    cout<<endl;
    return 0;
  }else{
    for(auto aa:a){
      but[aa]++;
    }
    dfs(0,0);
    for(auto a:ans){
      cout<<a;
    }
    cout<<endl;
    
    return 0;
  }
  
  
}