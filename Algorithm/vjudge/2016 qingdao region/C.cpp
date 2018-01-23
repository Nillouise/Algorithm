// https://www.cnblogs.com/wmrv587/p/6107134.html
//http://www.itdadao.com/articles/c15a835091p0.html
//或者纯湊，纯猜
#include<iostream>
using namespace std;
typedef long long LL;
int main()
{
  int T;
  cin>>T;
  while(T--)
  {
    double d,L;
    cin>>L>>d;
    // if(L<=d)
    // {
    //   printf("%0.6lf\n",0.0);
    //   continue;
    // }
    double lef=L-d;
    double pos = 1.0;
    double res = 0;
    for (size_t i = 0; i < 10; i++) {
      // pos *= lef/(lef+d);
      res += pos;
      pos *= lef/(lef+d);
      lef/=2.0;
      cout<<"pos "<<pos<<" lef "<<lef<<" "<<res<<endl;
    }
    printf("%0.6lf\n",res);
  }
  
}