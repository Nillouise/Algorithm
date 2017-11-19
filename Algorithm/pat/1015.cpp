#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m,k;
int school[200];
int rschool[200];
struct App
{
    int ge,gi,id,vis;
    vector<int> pre;
    bool operator<(const App& t)const
    {
        if(ge+gi>t.ge+t.gi)return true;
        if(ge+gi==t.ge+t.gi)
        {
            pair<int,int> p1=make_pair(ge,gi);
            pair<int,int> p2=make_pair(t.ge,t.gi);
            return p1>p2;
             
        }else{
            return false;
        }
    }
    bool equal(const App& t)const
    {
        return ge==t.ge&&gi==t.gi;
    }
};
vector<App> apps;
vector<App> myrank[50000];//rank 这名字好像被stl用了
vector<int> ans[50000];
 
int main()
{
  //  freopen("input.txt","r",stdin);//
 
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for (int i = 0; i < m; i++)
    {
        cin>>school[i];
    }
    for (int i = 0; i < n; i++)
    {
        App a;
        a.id=i;
        a.pre.resize(k);
        cin>>a.ge>>a.gi;
        for (int i = 0; i < k; i++)
        {
            cin>>a.pre[i];
        }
        apps.push_back(a);
    }
    sort(apps.begin(),apps.end());
    // for(auto a:apps)
    //     cout<<a.ge<<" "<<a.gi<<endl;//
     
    int len=0;
    myrank[len].push_back(apps[0]);
    for(int i=1;i<apps.size();i++)
    {
        if(!apps[i].equal(apps[i-1]))
        {
            len++;
        }
        myrank[len].push_back(apps[i]);
    }
     
//    for(int i=0;i<=len;i++)
//    for(auto a:myrank[i])cout<<i<<" "<<a.id<<" "<<a.ge<<" "<<a.gi<<endl;//
    memcpy(rschool,school,sizeof(school));
    for(int i=0;i<=len;i++)
    {
        //这里简直脑残，在同一个rank下，志愿的优先顺序并不会影响学校会不会录取你
        // for(int j=0;j<k;j++)
        // {
        //     for(auto &a:myrank[i])
        //     {
        //         if(a.vis==0&&rschool[a.pre[j]]>0)
        //         {
        //             ans[a.pre[j]].push_back(a.id);
        //             a.vis=1;
        //         }
        //     }
        //     for(int i=0;i<m;i++)
        //     {
        //         rschool[i] = school[i]-ans[i].size();
        //     }
        // }
        for(auto &a:myrank[i])
        {
            for(auto b:a.pre)
            {
                if(a.vis==0&&rschool[b]>0)
                {
                    ans[b].push_back(a.id);
                    a.vis=1;
                    break;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            rschool[i] = school[i]-ans[i].size();
        }
    }
     
    for(int i=0;i<m;i++)
    {
        sort(ans[i].begin(),ans[i].end());
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j];
            if(j!=ans[i].size()-1)cout<<" ";
        }
        cout<<endl;
    }
 
 
    return 0;
}
