#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int ans=2000;
int HP,AP,HM,AM,B,D;

bool dfs(int dep,int hp,int ap,int hm,int am,int att)
{
    // cout<<"dep "<<dep<< hp<<ap<<endl;
    // printf("dep %d %d %d %d %d\n",dep,hp,ap,hm,am);
    if(dep>=ans)
    {
        return false;
    }
    // if(dep>40&&(HM-hm<10&&ap==AP&&AM == am))
    // {
    //     return false;
    // }
    int flag = 0;
    // if(hm<=0)
    // {
    //     if(dep<ans)
    //     {
    //         ans=dep;
    //         // cout<<"scucess1"<<endl;
    //         //     printf("dep %d %d %d %d %d\n",dep,hp,ap,hm,am);
    //         return true;
    //     }
    // }
    
    //attack
    int chm = hm - ap;
    if(chm<=0)
    {
        if(dep+1<ans)
        {
            // cout<<"scucess2"<<endl;
            //     printf("dep %d %d %d %d %d\n",dep,hp,ap,hm,am);
            ans=dep+1;
            flag= 1;
            return true;
        }
        return false;
    }
    int chp = hp-am;
    if(chp>0)
    {
        if(dfs(dep+1,chp,ap,chm,am,1))
        {
            flag=1;
        }
    }
    //heal
    if(hp<=am)
    {
        if(dfs(dep+1,HP-am,ap,hm,am,att))
        {
            flag=1;
        }
    }
    //booster
    if(hp>am&& B>0&&att==0)
    {
        if(dfs(dep+1,hp-am,ap+B,hm,am,att))
        {
            flag=1;
        }    
    }
    //downer
    if(hp>am&&am>0&&D>0&&att == 0)
    {
        // cout<<"downer ";
        //                 printf("dep %d %d %d %d %d\n",dep,hp,ap,hm,am);
        // if(dfs(dep+1,hp-am,ap,hm,max(0,am-D),att))//注意这里血量减去D是不对的！！！！！！！！！！！！！
        if(dfs(dep+1,hp-(am-D),ap,hm,max(0,am-D),att))
        {
            flag=1;
        }
    }
    if(flag==1)
    {
        return true;
    }
    return false;
}

int main()
{
    //freopen("I:\\Project\\acm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
        // freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        ans=2000;
        cout<<"Case #"<<i<<": ";
        cin>>HP>>AP>>HM>>AM>>B>>D;
        if(AP>=HM)
        {
            cout<<"1"<<endl;
            continue;
        }
        
        // if(HP<=AM-D)
        // {
        //     cout<<"IMPOSSIBLE"<<endl;
        //     return 0;
        // }
        // if(HP-(AM-D)<=AM-D)
        // {
        //     cout<<"IMPOSSIBLE"<<endl;
        //     return 0;
        // }
        if(!dfs(0,HP,AP,HM,AM,0))
        {
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }else{
            cout<<ans<<endl;
        }
    }
    
    return 0;
}