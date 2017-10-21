#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn = 1e9+100;
vector<int> vis;
typedef pair<int,int> pii;

struct Node
{
    int p1;
    int p2;
    int flag;
};

int main()
{
    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    
    int n,k;
    cin>>n>>k;
    
    int MIN=maxn,MAX=0;
    for (int i = 0; i < n; i++) {
        int a;
        cin>>a;
        vis.push_back(a);
        if(MIN>a)MIN=a;
        // else if(MAX<a)MAX=a;//这是错的，当只有一个数的时候就不能正确处理
        if(MAX<a)MAX=a;
    }
    sort(vis.begin(),vis.end());
    int begin=MAX-MIN,end=MAX-MIN;
    vector<int> vb;
    
    //下面的顺序语句错了
    if(k>1)
    {
        for (int i = 0; i+k < n; i++) {
            vb.push_back(vis[i+k-1]-vis[i]);
        }
        sort(vb.begin(),vb.end());
    }else if(k==1)
    {
        cout<<0<<endl;
        return 0;
    }else if(k>=n)
    {
        cout<<MAX-MIN<<endl;
        return 0;
    }
    
    if(vb.size()>0)
    {
            end=vb.back();
                begin=vb[0];
            if(begin>0)begin--;
            if(end<MAX-MIN)end++;
    }
    else 
    { 
        begin = 0;
        end = MAX-MIN;
    }
    while(begin<end)
    {
        int mid = begin+(end-begin)/2;

        stack<Node> stk;
        stk.push(Node{0,-1,0});//用-1标记初始化
        
        int flag=0;
        while(!stk.empty())
        {
            Node p = stk.top();
            stk.pop();
            // if(p.p2-p.p1+1<k)p.p2=p.p1+k-1;//数量应该是小于等于
            if(p.p2==-1)p.p2=p.p1+k-1;
            else p.p2++;
            
            if(p.p2==n-1&&vis[p.p2]-vis[p.p1]<=mid)
            {
                flag=1;
                break;
            }else if(p.p2>n-1)
            {
                continue;
            }else if(vis[p.p2]-vis[p.p1]>mid)
            {
                continue;
            }
            else
            {
                stk.push(p);
                stk.push(Node{p.p2+1,-1,0});
            }
        }
        if(flag)
        {
                end=mid;
        }else{

                begin=mid+1;

        }
                // cout<<end<<" "; //
        
    }
    cout<<end<<endl;
    
    
    return 0;
}
