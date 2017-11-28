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
    data[0]=-1e9;
    for (int i = 1; i <=n; i++) 
    {
        cin>>data[i];
    }
    sort(data.begin(),data.end());
    data[0]=1e9;
    int beg=0,end = data.back()-data[1];
    while(beg<end)
    {
        int mid = (beg+end)>>1;
        vector<int> DP(n+1);
        DP[0]=1;
        vector<int> g(n+1);//前缀和
        g[0]=1;
        int j=1;//双指针法
        for (int i = 1; i <=n; i++) 
        {
            while(data[j]+mid<data[i])j++;
            if(i-j+1<k)
            {
                g[i]=g[i-1];
                DP[i]=0;
                continue;
            }
            int x = i-k+1;
            //这里处理j==1好好想想。
            if(j==1||(j-2>=0&&x-1>=0&&g[x-1]-g[j-2]>0))
            {
                DP[i]=1;
                g[i]=g[i-1]+1;
            }else{
                DP[i]=0;
                g[i]=g[i-1];
            }
        }
        if(DP[n]==1)
        {
            end=mid;
        }else{
            beg=mid+1;
        }
    }
    cout<<end<<endl;


    return 0;
}
