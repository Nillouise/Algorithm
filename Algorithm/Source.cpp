#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int r,c,k;
int rs,cs,re,ce;
char G[1050][1050];
int dist[1050][1050];
set<int> R[1050];
set<int> C[1050];


int main()
{
  freopen("D:\\Project\\Algorithm\\Algorithm\\Algorithm\\input.txt","w",stdout);
  srand(time(0));
  for(int i=0;i<30;i++)
  {
    
    int n = rand()%30+1;
    char a[2] = {'o','O'};
    for(int i=0;i<n;i++){
      cout<<a[rand()%2];
    }
    cout<<endl;
  }
  return 0;
}
