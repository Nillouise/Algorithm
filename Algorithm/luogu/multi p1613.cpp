#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL flo[60][60][40];
LL G[60][60];
LL flo2[60][60];

int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++) {
        int a,b;
        cin>>a>>b;a--,b--;
        G[a][b] = 1;
        flo[a][b][0] = 1;
    }
    //这里最多会有2^40是因为可能存在环
    for (int t = 1; t < 40; t++) {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(flo[i][k][t-1]==1&&flo[k][j][t-1]==1)
                    {
                        flo[i][j][t]=1;
                    }
                }
            }
        }
    }
    memset(flo2,0x3f3f,sizeof(flo2));
    for (int k = 0; k < 40; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(flo[i][j][k] == 1)
                {
                    flo2[i][j] = 1;
                }
            }
        }    
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                flo2[i][j] = min(flo2[i][j],flo2[i][k]+flo2[k][j]);
            }
        }
    }
    cout<<flo2[0][n-1]<<endl;
    
    
    
    return 0;
}