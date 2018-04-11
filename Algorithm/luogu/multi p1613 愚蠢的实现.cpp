#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m;
LL G[60][60];
LL flo[60][60];
LL flo2[60][60];


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    cin>>n>>m;
    for (int i = 0; i < m; i++) {
        int a,b;
        cin>>a>>b;a--,b--;
        G[a][b] = 1;
    }
    memcpy(flo,G,sizeof(G));
    LL cur = 1;
    int flag = 1;
    while(flag!=0)
    {
        flag=0;
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(flo[i][k] == flo[k][j]&&flo[i][k]==cur&&i!=j)
                    {
                        flo[i][j] = cur*2;
                        flag=1;
                        // cout<<i<<j<<endl;//
                    }
                }
            }
        }
        cur*=2;
        // getchar();
        // cout<<cur<<endl;//
    }
    
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout<<flo[i][j]<<" ";
    //     }
    //     cout<<endl;//
    // }
    
    memset(flo2,0x3f3f,sizeof(flo2));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(flo[i][j]!=0&&flo[i][j] - (flo[i][j]&(-flo[i][j])) ==0)
            {
                flo2[i][j] = 1;
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout<<flo2[i][j]<<" ";
    //     }
    //     cout<<endl;//
    // }
    
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