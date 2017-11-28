#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int n,k;
vector<int> data;

int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);

    cin>>n>>k;
    data.resize(n+1);
    data[0]=1e9;
    for (int i = 1; i <= n; i++) 
    {
        cin>>data[i];
    }
    sort(++data.begin(),data.end());
    
    int beg=0,end = data.back()-data[1];
    
    while(beg<end)
    {
        int mid = (beg+end)>>1;
        vector<int> DP(n+1,0);
        vector<int> preDP(n+1,0);
        preDP[0]=1;
        DP[0]=1;
        int cflag=1;
        for (int i = 1; i <= n; i++) 
        {
            int x=i-k;
            int flag=0;
            
            //这里这么写是错的，应该用双指针法，也就是随着i增长，pos也会增长。
            int pos = lower_bound(++data.begin(),data.end(),data[i]-mid) - data.begin();
            if(pos<=x&&preDP[x]>preDP[pos])
            {
                DP[i]=1;
            }
            
            if(DP[i])
            {
                preDP[i]=preDP[i-1]+1;
            }else{
                preDP[i]=preDP[i-1];
            }
            
            // while(x>=0&&data[i]-data[x]<=mid)
            // {
            //     if(DP[x]==1)
            //     {
            //         DP[i]=1;
            //         flag=1;
            //         break;
            //     }
            //     x--;
            // }
            // if(flag==0)
            // {
            //     cflag=0;
            //     break;
            // }
        }
        if(DP[n]==1)cflag=1;
        else cflag=0;
        
        if(cflag==0)
        {
            beg=mid+1;
        }else{
            end=mid;
        }
    }
    
    

    return 0;
}
