#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
int dat1[100];
int dat2[100];
map<int,char> fle={{1,'A'},{2,'B'},{3,'C'}};
int cnt=0;
int dfs(int x,int pos,int root)
{
    if(x==1)
    {
        if(dat1[x]!=pos)
        {
            cnt++;
            cout<<"move "<<x<<" from "<<fle[dat1[x]]<<" to "<<fle[pos]<<endl;
            dat1[x] = pos;
        }
        return 0;
    }else{
        if(dat1[x]!=pos)
        {
            cnt++;
            int tmp = 0;
            for(int i=1;i<=3;i++)
            {
                if(i!=pos&&i!=dat1[x])
                {
                    tmp=i;
                    dfs(x-1,i,0);
                }
            }
            cout<<"move "<<x<<" from "<<fle[dat1[x]]<<" to "<<fle[pos]<<endl;
            dat1[x]=pos;
            if(root==0)
            {
                dfs(x-1,pos,0);
            }
        }else{
            dfs(x-1,pos,0);
        }
        
    }
    return 0;
}

int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    cin>>n;
    int t;
    int x;
    cin>>t; for(int i=0;i<t;i++)cin>>x,dat1[x]=1;
    cin>>t; for(int i=0;i<t;i++)cin>>x,dat1[x]=2;
    cin>>t; for(int i=0;i<t;i++)cin>>x,dat1[x]=3;
    cin>>t; for(int i=0;i<t;i++)cin>>x,dat2[x]=1;
    cin>>t; for(int i=0;i<t;i++)cin>>x,dat2[x]=2;
    cin>>t; for(int i=0;i<t;i++)cin>>x,dat2[x]=3;
    for(int i=n;i>=1;i--)
    {
        if(dat1[i]!=dat2[i])
        {
            dfs(i,dat2[i],1);
        }
    }
    cout<<cnt<<endl;
    
    return 0;
}