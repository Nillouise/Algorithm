#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int cnt=0;
int n,k;
int dfs(vector<char>& vec)
{
  if(cnt++==k)
  {
    for(int i=0;i<vec.size();i++)cout<<vec[i];
    cout<<endl;
    return 1;
  }
  for(char i='A';i<'A'+n;i++)
  {
    vec.push_back(i);
    int flag=1;
    for(int j=1;2*j<=vec.size();j++)
    {
      int equal=0;
      for(int k=0;k<j;k++)
      {
        int tail = vec.size()-1;
        if(vec[tail-k]!=vec[tail-k-j])
        {
          equal=1;
          break;
        }
      }
      if(equal==0)
        {
          flag=0;
          break;
        }
    }
    if(flag==0){vec.pop_back();continue;}
    if(dfs(vec))
      return 1;
      else{
        vec.pop_back();
      }
  }
  return 0;
}



int main()
{
//    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);

    while(cin>>k>>n,n!=0)
    {
      cnt=0;
      std::vector<char> vec;
      dfs(vec);
    }

    return 0;
}
