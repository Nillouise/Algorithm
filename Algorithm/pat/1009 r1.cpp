#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
int data[10000+10];
int par[10000+10];
int tmp[10000+10];

int insertsort()
{
    memcpy(tmp,data,sizeof(tmp));
    int flag2=0;
    for (int i = 1; i < n; i++) 
    {
        int p = i+1;
        for (int j = 1; j <= i+1; j++) 
        {
            if(tmp[j]>tmp[p])
            {
                swap(tmp[j],tmp[p]);
            }
        }
        int flag=1;
        //这里还需要再进行一次的
        for (int i = 1; i <= n; i++) 
        {
            if(tmp[i]!=par[i]){flag=0;break;}
        }
        if(flag==1)
        {
            flag2=1;
            continue;
        }
        if(flag2 == 1)
        {
            memcpy(par,tmp,sizeof(tmp));
            return 1;
        }
    }
    return 0;
}
int heap()
{
    int pos=0;
    for (int i = 1; i <= n; i++) 
    {
        // if(par[i]>par[i/2]&&i!=0){pos=i-1;break;}
        if(par[i]>par[i/2]&&i!=1){pos=i-1;break;}//这里是i!=1而不是0，是禁止第一个数
    }
    swap(par[1],par[pos]);
    pos--;
    int x = 1;
    while(x<=pos)
    {
        int nxt = x;
        if(x*2<=pos&& par[x*2]>par[nxt])
        {
            nxt = x*2;
        }
        if(x*2+1<=pos&&par[x*2+1]>par[nxt])
        {
            nxt=x*2+1;
        }
        if(nxt==x)break;
        swap(par[x],par[nxt]);
        x=nxt;
    }
    return 0;
}
int main()
{
    freopen("input.txt","r",stdin);//

    ios::sync_with_stdio(false);

    cin>>n;
    for (int i = 1; i <= n; i++) 
    {
        cin>>data[i];
    }
    for (int i = 1; i <= n; i++) 
    {
        cin>>par[i];
    }
    if(insertsort())
    {
        cout<<"Insertion Sort"<<endl;
    }else{
        heap();
        cout<<"Heap Sort"<<endl;
    }
    for (int i = 1; i <=n; i++) 
    {
        cout<<par[i];
        if(i!=n)cout<<" ";
    }
    cout<<endl;
    


    return 0;
}
