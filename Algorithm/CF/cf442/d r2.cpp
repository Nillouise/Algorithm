#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int r,c,k;
int rs,cs,re,ce;
char G[1050][1050];
int dist[1050][1050];
set<int> R[1050];
set<int> C[1050];

void update(int cr,int cc)
{
    cout<<"update "<<cr<<" "<<cc<<endl;//
    R[cr].erase(cc);
    C[cc].erase(cr);
}

int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    cin>>r>>c>>k;
    for (int i = 0; i < r; i++) 
    {
        for (int j = 0; j < c; j++) 
        {
            cin>>G[i][j];
            R[i].insert(j);
            C[j].insert(i);
        }
    }
    cin>>rs>>cs>>re>>ce;
    rs--,cs--,re--,ce--;
    memset(dist,-1,sizeof(dist));
    queue<pair<int,int> > Q;
    update(rs,cs);
    Q.push({rs,cs});
    dist[rs][cs]=0;
    while(!Q.empty())
    {
        // cout<<"ok:"<<endl;
        auto cn = Q.front();Q.pop();
        int r1=cn.first,c1=cn.second;
        // auto it = R[r1].find(c1);//卧槽，set用find出来的不是有顺序的。要lower_bound才行
        auto it = R[r1].lower_bound(c1);
        
        while(it!=R[r1].begin() && c1 - *(--it)<=k&&G[r1][*it]=='.' )
        {
            // cout<<"disorder "<<*it<<endl;
            dist[r1][*it] = dist[r1][c1]+1;
            Q.push({r1,*it});
            update(r1,*it);
            it = R[r1].lower_bound(c1);
        }
        it = R[r1].lower_bound(c1);
        // cout<<"keypoint4:"<<endl;
        // for(auto a: R[r1])cout<<a<<" ";
        // cout<<endl;

        while(it!=R[r1].end()&& *it -c1<=k&&G[r1][*it]=='.')
        {
                    // cout<<" *it "<< *it<<endl;
            dist[r1][*it]=dist[r1][c1]+1;
            Q.push({r1,*it});
            update(r1,*it);
            it = R[r1].lower_bound(c1);//果然是刚刚改过的地方错了
        }
        
        it = C[c1].lower_bound(r1);
        while(it!=C[c1].begin()&& r1-*(--it)<=k&&G[*it][c1]=='.')
        {
            dist[*it][c1] = dist[r1][c1]+1;
            Q.push({*it,c1});
            update(*it,c1);
            it = C[c1].lower_bound(r1);
        }
        it = C[c1].lower_bound(r1);
        
        
        while(it!=C[c1].end()&& *it-r1 <=k&&G[*it][c1]=='.')
        {
            dist[*it][c1] = dist[r1][c1]+1;
            Q.push({*it,c1});
            update(*it,c1);
            it = C[c1].lower_bound(r1);
        }
        if(dist[re][ce]!=-1)
        {
            break;
        }
        
    }
    
    
    cout<<dist[re][ce]<<endl;


    return 0;
}
