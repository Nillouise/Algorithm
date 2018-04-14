#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int dat[100][100];



int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int T;
    cin>>T;
    for (int TT = 0; TT < T; TT++) {
        int r,c;cin>>c>>r;
        int tr = r,tc = c;
        memset(dat,0,sizeof(dat));
        string s;cin>>s;
        for(auto a:s)
        {
            if(a=='.')break;
            if(a=='E')
            {
                dat[r-1][c] = 1;
                c++;
            }else if(a=='N')
            {
                dat[r][c]=1;
                r++;
                
            }else if(a=='W')
            {
                dat[r][c-1]=1;
                c--;
            }else if(a=='S')
            {
                dat[r-1][c-1]=1;
                r--;
            }
        }
        for (int i = 31; i >=0; i--) {
            for (int j = 0; j < 32; j++) {
                if(dat[i][j])cout<<"X";
                else cout<<".";
            }
            cout<<endl;
        }
        
    }
    
    
    return 0;
}