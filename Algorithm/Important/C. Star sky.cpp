//这题的重点在于把不同种类的数据（尽管看起来他们只是稍有不同），按不同方法处理
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int G[200][200][15];
int cnt[200][200][15];

int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);

    int n,q,c;
    cin>>n>>q>>c;
    for (int i = 0; i < n; i++) 
    {
        int r,c,s;
        cin>>r>>c>>s;
        G[r][c][s]++;
    }
    for (int i = 0; i <= c; i++) 
    {
        for (int r = 1; r < 102; r++) 
        {
            for (int c = 1; c < 102; c++) 
            {
                cnt[r][c][i]=G[r][c][i]+ cnt[r-1][c][i] +cnt[r][c-1][i]- cnt[r-1][c-1][i];
            }
        }
    }
    for (int i = 0; i < q; i++) 
    {
        int t,x1,y1,x2,y2;
        cin>>t>>x1>>y1>>x2>>y2;
        int total = 0;
        for (int i = 0; i <= c; i++) 
        {
            int col = (i+t)%(c+1);
            total+= col*cnt[x2][y2][i];
            total-=col *cnt[x1-1][y2][i];
            total-=col*cnt[x2][y1-1][i];
            total+=col*cnt[x1-1][y1-1][i];
        }
        cout<<total<<endl;
    }


    return 0;
}
