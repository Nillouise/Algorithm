#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int maze[200][200];


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int n,m;
    cin>>n>>m;
    for (int i = 1; i <= n; i++) {
        string s;cin>>s;
        for (int j = 1; j <= m; j++) {
            if(s[j-1]=='.')maze[i][j]=0;
            else if(s[j-1]=='*')maze[i][j]=10;
            else maze[i][j]=s[j-1]-'0';
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(maze[i][j]!=10){
                int cnt=0;
                for (int k = -1; k < 2; k++) {
                    for (int l = -1; l < 2; l++) {
                        if(maze[i+k][j+l]==10){
                            cnt++;
                        }
                    }
                }
                if(cnt!=maze[i][j]){
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"YES"<<endl; 

    
    return 0;
}