#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(false);
    
    LL n,k;
    cin>>n>>k;
    vector<int> vec;
    vector<int> len;
    int MAX=0;
    for(int i=0;i<n;i++)
    {
        int p;
        cin>>p;
        if(MAX<p)MAX=p;
        vec.push_back(p);
    }
    int flag=0;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        int INF = 1000;
        //int cnt =0;//这里没有考虑跟前面的对战输了的情况。
        int cnt=(i==0?0:1);
        for(int j=i+1;j<n;j++)
        {
            if(vec[j]>vec[i])
            {
                break;
            }
            cnt++;

                    if(cnt>=k)
            {
                flag=1;
                ans=vec[i];
                goto fin;
            }
            }
    }
    fin:
        if(flag)
        {
            cout<<ans<<endl;
        }else{
        cout<<MAX<<endl;

        }

    return 0;
}
