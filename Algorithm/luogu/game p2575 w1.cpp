#include<bits/stdc++.h>
using namespace std;
typedef long long LL;



//这是错的，要用sg函数+nim游戏做的
int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int pre = 0;
        for(int i=0;i<n;i++)
        {
            int line;
            cin>>line;
            vector<int> c(25);
            for(int j=0;j<line;j++)
            {
                int x;
                cin>>x;
                c[x]=1;
            }
            int empty=0;
            int flag=0;
            for(int i=1;i<=20;i++)
            {
                if(c[i])flag=1;
                if(flag&&c[i]==0)
                {
                    empty++;
                }
            }
            if(empty==1)pre++;
        }
        if(pre%2)
        {
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    
    
    
    return 0;
}