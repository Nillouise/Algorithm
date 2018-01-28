//https://www.nowcoder.com/acm/contest/74/A
//这题不知道哪里错了//具体看cvt 和cvt2的思路，其实是会错的，因为oOOoo 结合的位置可能不同，一个是oO,一个是Oo
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

bool cvt(string &s)
{
  string t;
  bool flag=false;
  if(s.size()==1){
    return false;
  }
  for(int i=1;i<s.size();){
    
    if(s[i]==s[i-1])
    {
      if(s[i]=='o'){
        t+='O';
      }
      flag=true;
      if(i==s.size()-2){
        t+=s.back();
        break;
      }
      i+=2;
    }else{
      t+=s[i-1];
      if(i==s.size()-1){
        t+=s.back();
        break;
      }
      i++;
    }
  }
  s=t;
  // cout<<"s "<<s<<endl;//
  return flag;
  
}

bool cvt2(string &s){
  string t;
  for(int i=1;i<s.size();i++){
    if(s[i]==s[i-1]){
      if(s[i]=='o'){
        t+='O';
        t+=s.substr(i+1);
        s=t;
        return true;
      }else{
        t+=s.substr(i+1);
        s=t;
        return true;
      }
    }
    t+=s[i-1];
  }
  return false;
}
int main()
{
   freopen("D:\\Project\\Algorithm\\Algorithm\\Algorithm\\input.txt","r",stdin);
  string t;
   while(cin>>t){
     string s2 = t;
     string s1 = t;
     while(cvt2(s1)){
       // cout<<s<<endl;//
     }
     // if(s.size()>0)
     cout<<s1<<endl;
     while(cvt(s2)){
       // cout<<s<<endl;//
     }
     
     cout<<s2<<endl;//
     if(s1!=s2)cout<<t<<endl;
     cout<<endl;
   }
   return 0;
}