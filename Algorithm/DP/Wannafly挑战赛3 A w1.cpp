#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 1e9;
LL n,m;
LL cm;
vector<LL> vec;
vector<double> DP(100000+100);
double sub(int l)
{
//    if(l==4)
//    {
//        cout<<"a"<<endl;
//    }

    if(DP[l]>=0)
        return DP[l];
    LL sum = 0;
    int i;
    for(i=l;i<n;i++)
    {
        sum+=vec[i];
        if(sum>cm)break;
    }
    if(i-l==0)return DP[l]=0;
    double ans = 0;
    for(int j = l+1;j<=i;j++)
    {
        double ano = i-l;
        //这题我没考虑超过尾端的处理，导致要debug
        if(sub(j)==0.0&&j<n) return DP[l]=0;
        ans+= (1/(ano))*sub(j);
    }
    return DP[l]=ans+1;

}

int main()
{
//    freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);
//	ios::sync_with_stdio(false);
	//cin>>n>>m;
	scanf("%lld%lld",&n,&m);
	vec.resize(n);
    for(int i=0;i<n;i++)
        //cin>>vec[i];
        scanf("%lld",&vec[i]);
//    for(auto a:vec)
//        cout<<a<<" ";
//    vector<LL> pre;
//    pre.push_back(0);
//    for(auto a:vec)
//        pre.push_back(pre.back()+a);

    for(int kase=0;kase<m;kase++)
    {
        scanf("%lld",&cm);
        fill(DP.begin(),DP.end(),-1.0);
    //    cout<<sub(0)<<endl;
        double ans = sub(0);
//        for(int i=0;i<5;i++)
//        cout<<DP[i]<<" ";
//        cout<<endl;

        if(ans==0.0)
        {
            printf("YNOI is good OI!\n");
        }else
            printf("%.2f\n",ans);
    }



}
