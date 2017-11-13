//进制转换，感觉挺常用的
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);
    long long n;
    cin>>n;
    long long clonen = n;
    char c;
    cin>>c;
    int mal1;
    cin>>mal1;
    cin>>c;
    int mal2;
    cin>>mal2;

    long long decimal=0;

    int b=1;
    while(n)
    {
        decimal+= b*(n%10);
        b*=mal1;
        n/=10;
    }

    vector<int>ans;
    while(decimal)
    {
        int a = decimal%mal2;
        ans.push_back(a);
        decimal/=mal2;
    }
    cout<<clonen<<"<"<<mal1<<">=";
    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i];
    cout<<"<"<<mal2<<">";
    cout<<endl;

}
