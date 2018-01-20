#include<iostream>
using namespace std;
typedef long long LL;

int C[6][4];

bool check()
{
  
}

void pre()
{
  int T[4];
  memcpy(T,C[1],sizeof(C[0]));
  for (size_t i = 1; i < 4; i++) {
    memcpy(T,C[i],sizeof(C[i]));
    memcpy(C[i],C[i-1],sizeof(C[i]));
  }
  memcpy(C[0],T,sizeof(C[i]));
  int tl[4] = {1,3,0,2};
  int tr[4] = {2,0,3,1};
  int l[4],r[4];
  for(int i=0;i<4;i++)
  {
    l[tl[i]]=C[4][i];
  }
  memcpy(C[4],l,sizeof(l));
  for(int i=0;i<4;i++)
  {
      r[tr[i]]=C[5][i];
  }
  memcpy(C[5],r,sizeof(r));
}

void left()
{
  
}

int main()
{
  int T;
  cin>>T;
  while(T--)
  {
    for (size_t i = 0; i < 6; i++) {
      cin>>C[i][0]>>C[i][1]>>C[i][2]>>C[i][3];
    }
    for(int i=0;i<4;i++)
    {
      pre();
    }
    
    
  }
  
}