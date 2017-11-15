//用栈维护即可。对应BFS序列映射出了每个节点和根节点的距离，遍历dfs序列，对当前节点和栈顶节点比较，如果该节点距离根节点更远，则说明该节点为栈顶节点个孩子节点，则记录后将节点放入栈中。否则弹掉栈顶元素继续比较。需要注意一点，即当元素与栈顶元素的距离值刚好相差1的时候要视为相等,因为它们属于兄弟节点

//我的理解：为什么这样干可以？因为dfs的一颗树是聚在一起的，这样假如层序遍历时，刚好相差一的话，完全可以把当前结点当作时没有子节点的叶子结点，然后把在dfs序列后一位的数当作时兄弟结点，而bfs中，相邻的两结点只有两个可能，一个是后者是前者的兄弟，一个是后者是新一层的第一个。
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
int DFS[2000];
int BFS[2000];
int DIST[2000];
vector<int> G[2000];


int main()
{
 //   freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);
	while(cin>>n)
    {
        for(int i=0;i<n;i++)
            cin>>BFS[i];
        for(int i=0;i<n;i++)
            DIST[BFS[i]]=i;
        for(int i=0;i<n;i++)
            cin>>DFS[i];
        for(int i=0;i<2000;i++)G[i].clear();

        stack<int> stk;
        stk.push(DFS[0]);
        for(int i=1;i<n;i++)
        {
            while(true)
            {
                int u = stk.top();
                int x = DFS[i];

                if(u==DFS[0] || DIST[u]+1<DIST[x])
                {
                    stk.push(x);
                    G[u].push_back(x);
                    break;
                }else{
                    stk.pop();
                }
            }
        }
        for(int i= 1;i<=n;i++)
        {
            cout<<i<<":";
            for(auto a:G[i])
                cout<<" "<<a;
            cout<<endl;
        }
    }



	return 0;
}
