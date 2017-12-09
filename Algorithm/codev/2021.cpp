//位置加个数是 结尾的后一位//这题这么想是错的，这题是快速选择
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int N,Q;
int DP[1000+10][1000+10];
int dat[1000+10];

int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    cin>>N>>Q;
    for (int i = 0; i < N; i++) 
    {
        cin>>dat[i];
    }
    for (int k = 1; k < N+N%2; k+=2) 
    {
        if(k==1)
        {
            for (int i = 0; i < N; i++) 
            {
                DP[i][i]=dat[i];
            }
        }else for (int i = 0; i+k <= N; i++) //位置加个数是 结尾的后一位
        {
            int l = dat[i],r = dat[i+k-1];
            int o = DP[i][i+k-3],p = DP[i+1][i+k-2],q = DP[i+2][i+k-1];
            // cout<<"o "<< o<<" p "<<p<<" q "<<q<<endl;//
            // cout<<"mid"<<p<<endl;//
            // cout<<"l "<<l<<" r "<<r<<" o "<<o<<" p "<<p<<" q "<<q<<endl;//
            if((l<=p&&r>=p)||(l>=p&&r<=p))
            {
                DP[i][i+k-1] = p;
            }else{
                if(l>p&&r>p)
                {
                    if(o>p&&q>p)
                    {
                        DP[i][i+k-1] = min(o,q);
                    }else{
                        DP[i][i+k-1] = max(o,q);
                    }
                }
                if(l<p&&r<p)
                {
                    if(o<p&&q<p)
                    {
                        DP[i][i+k-1] = max(o,q);
                    }else{
                        DP[i][i+k-1] = min(o,q);
                    }
                }
            }
        }
    }
    
    
    for (int i = 0; i < Q; i++) 
    {
        int l,r;
        cin>>l>>r;
        cout<<DP[l-1][r-1]<<endl;
    }
    


    return 0;
}
