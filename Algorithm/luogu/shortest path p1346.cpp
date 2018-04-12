#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int N,d[200][200],A,B;



int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    memset(d,0x3f3f,sizeof(d));    
    cin>>N>>A>>B;A--,B--;
    for (int i = 0; i < N; i++) {
        int k;
        cin>>k;
        for (int j = 0; j < k; j++) {
            int x;
            cin>>x;x--;
            if(j==0)
            {
                d[i][x] = 0;
            }else{
                d[i][x]=1;
            }
        }
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
    if(d[A][B]>=0x3f3f)
    {
        cout<<-1<<endl;
    }else{
        cout<<d[A][B]<<endl;
    }
    
    
    return 0;
}