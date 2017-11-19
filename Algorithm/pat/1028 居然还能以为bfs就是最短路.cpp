//都写完雏形才发现没有好好研究数据。
//写到最后才发现要用dijkstra,卧槽，我还以为bfs就行，这种拉紧真是蠢得很。
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m,ks,service;

// map<string,vector<pair<string,int> > > G;
vector<pair<int,int>> G[2000];
int cvt(string s)
{
//    cout<<s<<"e"<<endl;
    if(s[0]=='G')
    {
        s=s.substr(1);
        return n+stoi(s);
    //    return stoi("0");
    }
    return stoi(s);
//    return stoi("0");
}

int read(char *s)
{
    int x = -1;
    if(s[0] == 'G') {
        sscanf(s + 1, "%d", &x);
        x += n; //n ~ (n+m-1)
    } else {
        sscanf(s, "%d", &x);
    }
    return x;
}


int main()
{
    freopen("input.txt","r",stdin);//

//    ios::sync_with_stdio(false);
    cin>>n>>m>>ks>>service;
    if(n==0||m==0)
    {
        cout<<"No Solution"<<endl;
        return 0;
    }
//    cout<<"road"<<ks<<endl;//
    // roads-=100;
    for (int i = 0; i < ks; i++) 
    {
//        cout<<ks<<" "<<"i"<<i<<endl;
        string u,v;
    
        int dist;
        cin>>u>>v>>dist;
        if(u==""||v==""){cout<<"break";break;}        
//        cout<<"i"<<i<<"m"<<u<<" "<<v<<"e"<<endl;
        
        int iu=cvt(u);
        int iv=cvt(v);
    //    int iu=0;int iv=0;
        G[iu].push_back({iv,dist});
        G[iv].push_back({iu,dist});
    
    // char s1[16], s2[16];
    // int u, v, d;
    // scanf("%s %s %d\n", s1, s2, &d);
    // u=read(s1);
    // v=read(s2);
    //     G[u].push_back({v,d});
    //     G[v].push_back({u,d});
    }
    
    int minS=0;
    double minVal = 0;
    double minAvg = 1e10;
    
    for(int i=1;i<=m;i++)
    {
        int c = i+n;
        queue<int> Q;
        Q.push(c);
        vector<int> vis(n+3+m);
        fill(vis.begin(),vis.end(),(int)1e9);
        vis[c]=0;
        int cnt = 0;
        while(!Q.empty())
        {
            int u = Q.front();Q.pop();
            for(auto a:G[u])
            {
                if(vis[a.first]>vis[u]+a.second)
                {
                    vis[a.first]=vis[u]+a.second;
                    Q.push(a.first);
                    if(a.first<=n)
                    {
                        cnt++;//这里cnt不能正确更新了几个节点，只会记录更新了几次节点
                    }
                }
            }
        }
        int flag=0;
        
        double cVal = 1e10;
        double total = 0;
        for(int i=1;i<=n;i++)
        {
            total+=vis[i];
            if(vis[i]==(int)1e9||vis[i]>service){flag=1;break;}
            cVal = min(cVal,(double)vis[i]);
        }
        if(flag==1)continue;
        double cAvg = total/(double)n;
        if(cVal>minVal||(cVal==minVal&&cAvg<minAvg))
        {
            minS=i;
            minVal = cVal;
            minAvg = cAvg;    
        }
    
    }
    if(minS==0)return cout<<"No Solution"<<endl,0;
    cout<<"G"<<minS<<endl;//这题要输出G，看看输出要求才行
//    printf("%.1lf %.1lf\n",minVal,(minAvg*100+5)/100);//这里对double进行round，应该直接比较才对
    if(((int)(minAvg*100))%10>=5)
    {
        printf("%.1lf %.1lf\n",minVal,minAvg+0.1);//这里对double进行round，应该直接比较才对
    }else{
        printf("%.1lf %.1lf\n",minVal,minAvg);//这里对double进行round，应该直接比较才对

    }
    
    


    return 0;
}
