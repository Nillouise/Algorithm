#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int vis[200];
//此题用队列做好得多。

int otherman()
{

    int n,m,s=0;scanf("%d%d",&n,&m);//关键是这里的s，一开始为0
    bool visit[200]={0};//visit赋初始值 
    for(int k=0;k<n;k++){//总共要出队n次
        for(int i=0;i<m;i++){if(++s>n)s=1;if(visit[s])i--;}//类似取模，而因为序列是从1开始的，所以不取模，加判断；若visit过，则i--，使其继续循环
        printf("%d ",s);visit[s]=true;//输出，记录已出队
    }
    return 0;
}

int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int n,m;
    cin>>n>>m;
    if(m==0)
    {
        for (int i = 0; i < n; i++) {
            cout<<i+1<<" ";
        }
        return 0;
        
    }
    m--;
    m%=n;
    int c = 0;
    for (int t = 0; t < n; t++) {

        int k = 0;
        while(k<m)
        {
            if(vis[c]==0){
                k++;
                c++;
            }else{
                // cout<<"c"<<c<<" ";
                c++;    
            }
            if(c==n)c=0;
        }
        while(vis[c]==1){c++;c%=n;};//这里要处理当前打印的东西已经被vis了
        cout<< c+1<<" ";
        vis[c]=1;
    }
    
    
    
    return 0;
}