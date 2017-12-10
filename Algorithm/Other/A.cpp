// https://www.nowcoder.com/acm/contest/36/A
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int dat[100000+10];
int pre[100000+10];

int but[100000*10+1];


int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) 
    {
        cin>>dat[i+1];
    }
    for (int i = 1; i <= n; i++) 
    {
        pre[i] = pre[i-1]+dat[i];
    }
    LL cnt = 0;
    for (int i = n; i >= 1; i--) 
    {
        but[pre[i]]++;
        for (int j = 0; pre[i-1]+ j*j <= pre[n]; j++) 
        {
            cnt+=but[pre[i-1]+j*j];
        }
    }
    cout<<cnt<<endl;

    return 0;
}
