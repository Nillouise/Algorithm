//这题要用前缀和的思路，把状态转移的数量减少掉，达到O(n)的复杂度
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

vector<LL> suf(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            suf[i]=suf[i+1]+vec[i];
        }
    for(int kase=0;kase<m;kase++)
    {
        scanf("%lld",&cm);
        fill(DP.begin(),DP.end(),-1.0);
    //    cout<<sub(0)<<endl;
//        double ans = sub(0);
//        for(int i=0;i<5;i++)
//        cout<<DP[i]<<" ";

        vector<double> suf2(n+1,0);//保存概率的前缀和

        int j=n-1;
        int flag=1;
        for(int i=n-1;i>=0;i--)
        {
            while(suf[i]-suf[j+1]>cm)j--;
            if(j<i)
            {
                flag=0;
                break;
            }
//            double curPossible = (1.0/double(j-i+1))*((double)(suf2[i]-suf[j+1]))+1;//这里把suf2[j+1]打成了suf[j+1],我猜到这里出错了，就要专心在这里找才行。

            //double curPossible = (1.0/double(j-i+1))*((double)(suf2[i+1]-suf2[j+1]))+1;//这里是j+2才对，因为一刀两断后，右边第一的也要算进去
            double curPossible = (1.0/double(j-i+1))*((double)(suf2[i+1]-suf2[j+2]))+1;
            suf2[i]=curPossible+suf2[i+1];
        }

//        for(auto a:suf2)
//            cout<<a<<" ";//

        if(flag==0)
        {
            printf("YNOI is good OI!\n");
        }else//因为这是前缀和，所以要suf2[0]-suf2[1];
            printf("%.2f\n",suf2[0]-suf2[1]);
    }



}
