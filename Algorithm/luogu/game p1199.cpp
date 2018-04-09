#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int N;
int dat[600][600];

int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    cin>>N;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
                cin>>dat[i][j];
        }
        for(int j=0;j<i;j++)
        {
            dat[i][j] = dat[j][i];
        }
        
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        sort(dat[i],dat[i]+N);
        ans = max(ans, dat[i][N-2]);
    }
    cout<<1<<endl;
    cout<<ans<<endl;
    
    
    return 0;
}