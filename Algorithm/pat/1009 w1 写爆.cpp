//猜测排序宣布写爆
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int data[10000+10];
int par[10000+10];

int dfs(int x,int e)
{
    int u=x;
    while(u<=e)
    {
        int v=-1;
        int maxn = -1;
        if(u*2<=e){
            v=par[u*2];
            maxn = u*2;
        }
        if(u*2+1<=e&&par[u*2+1]>v)
        {
            v=par[u*2+1];
            maxn=u*2+1;
        }
        if(maxn==-1|| v<par[u])
        {
            break;
        }else{
            swap(par[u],par[maxn]);
            u=maxn;
        }
    }
    return 0;
}

int main()
{
    freopen("input.txt","r",stdin);//

    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    for (int i = 0; i < n; i++) 
    {
        cin>>data[i];
    }
    for (int i = 0; i < n; i++) 
    {
        cin>>par[i];
    }
    int pos;
    for (int i = n-1; i >=0; i--) 
    {
        if(par[i]!=data[i])
        {
            pos=i;
            break;
        }
    }
    int flag=0;
    for (int i = 1; i <= pos; i++) 
    {
        if(par[i]<par[i-1])
        {
            flag=1;
            break;
        }
    }
    if(flag)
    {
        cout<<"Heap Sort"<<endl;
        
        int pos = 0;
        //这是错的，后半段有序不代表他们就是在有序区，因为他们可能不是最大的那一批数。
        for(int i=n-2;i>=0;i--)
        {
            if(par[i]<=par[i+1])
            {
                pos=i;
            }else{
                break;
            }
        }
        int cmax = 0;
        for(int i=0;i<n;i++)
        {
            if(cmax<par[i])
            {
                cmax = par[i];
                if(i>=pos){pos=i;break;}
            }
        }
        
        // for(;;pos++)//以为只要跟父节点对比一下就行了，真是蠢
        // {
        //     if(par[pos]<par[(pos+1)/2+1])continue;
        //     else break;
        // }
        // cout<<"swap "<<par[pos-1]<<endl;//
        swap(par[0],par[pos-1]);
        
        dfs(0,pos-2);
    }else{
        cout<<"Insertion Sort"<<endl;
        // cout<<pos+1<<endl;
        for(int i=1;i<n;i++)
            if(par[i]<par[i-1]){pos = i;break;}
                sort(par,par+pos+1);
    }
    for (int i = 0; i < n; i++) 
    {
        cout<<par[i];
        if(i!=n-1)
            cout<<" ";
    }
    cout<<endl;
    
    


    return 0;
}
