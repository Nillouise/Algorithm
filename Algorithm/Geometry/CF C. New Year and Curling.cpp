#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
int n,r;
vector<pair<double,double> > dat;

int main()
{
    cin>>n>>r;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        double MAX=r;
  //      cout<<"MAX"<<MAX<<endl;//
        for(auto a:dat)
        {
            if(abs(a.first-x)<=2*r)
            {
                double gap = 2.0*r*2*r - pow(abs(a.first-x),2.0);
    //            cout<<"gap "<<gap<<endl;//
                MAX = max(MAX,a.second+sqrt(gap));
            }
        }
        //cout<<MAX<<endl;//
        printf("%0.7f ",MAX);
        dat.push_back({x,MAX});

    }

    return 0;
}
