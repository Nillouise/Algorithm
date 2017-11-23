#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int nxt[100000+10];
int val[100000+10];
int n;
int head;
vector<int> rem;//removed;
vector<int> ans;//没被过滤的

int main()
{
    freopen("input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    
    cin>>head>>n;
    for (int i = 0; i < n; i++) 
    {
        int pos,v,p;
        cin>>pos>>v>>p;
        nxt[pos]=p;
        val[pos]=v;
    }
    set<int> fil;
    int ch = head;
    while(ch!=-1)
    {
        if(fil.find(abs(val[ch]))==fil.end())
        {
            ans.push_back(ch);
        }else{
            rem.push_back(ch);
        }
        fil.insert(abs(val[ch]));
        ch=nxt[ch];
    }
    for (int i = 0; i < ans.size(); i++) 
    {
        printf("%05d %d ",ans[i],val[ans[i]]);
        if(i==ans.size()-1)printf("-1\n");
        else printf("%05d\n",ans[i+1]);
    }
    for (int i = 0; i < rem.size(); i++) 
    {
        printf("%05d %d ",rem[i],val[rem[i]]);
        if(i==rem.size()-1)printf("-1\n");
        else printf("%05d\n",rem[i+1]);
    }
    

    return 0;
}
