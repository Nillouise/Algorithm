#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    string s;
    cin>>s;
    int x=0,y=0;
    int ans = 0;
    int st = -1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='U')
        {
            y++;
        }else{
            x++;
        }
        if(st==-1){st=x>y;continue;}
        if(x>y){
            if(st==0){
                st=1;
                ans++;
            }
        }else if(x<y){
            if(st==1){
                st=0;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    
    
    return 0;
}
