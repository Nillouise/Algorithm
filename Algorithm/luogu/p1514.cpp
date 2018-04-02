#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int DP[20*100+10];


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int fil[30]={0};
    int n,m;
    cin>>n>>m;
    int w[30]={};
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
    for(int i=0;i<m;i++)
    {
        fil[i]=1;
    }
    sort(fil,fil+n);
    int ans = 0;
    do
    {
        // for(int i=0;i<n;i++)
        //     cout<<fil[i]<<" ";
        //     cout<<endl;
        memset(DP,0,sizeof(DP));
        DP[0]=1;
        for(int i=0;i<n;i++)
        {
            if(fil[i]==0)
            {
                for(int j=20*100;j>=w[i];j--)
                {
                    if(DP[j-w[i]]==1)DP[j]=1;
                }
            }
        }
        int c = 0;
        for(int i=1;i<20*100;i++)
        {
            c+=DP[i];
        }
        if(ans<c)ans=c;
        
    }while(next_permutation(fil,fil+n));
    cout<<ans<<endl;
    
    
    
    return 0;
}