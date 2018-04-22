#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int T;cin>>T;
    while(T--)
    {
        int len,x;string s;
        cin>>len>>x>>s;
        if(x==1||x==len){
            cout<<0<<endl;
        }else{
            int ans = 1e8;
            int cnt1 =0;
            for(int i=1;i<x;i++)//注意不用考虑第一个字母
            {
                if(s[i]=='R'){
                    cnt1++;
                }
            }
            int cnt2=0;
            for(int i=len-2;i>=x-1;i--)//注意不用考虑最后一个字母
            {
                if(s[i]=='L'){
                    cnt2++;
                }
            }
            cout<<min(cnt1,cnt2)<<endl;
            
        }
        
        
        
    }
    
    
    
    return 0;
}