#include<bits/stdc++.h>
using namespace std;
vector<string> maze;
    int r1,c1,r2,c2;

    int r,c,k;
vector<set<int>> vsr;
vector<set<int>> vsc;


void update(int r,int c)
{
    vsr[r].erase(c);
    vsc[c].erase(r);
}

int solve1()
{
    r1--,c1--,r2--,c2--;
    vsr.resize(r);
    vsc.resize(c);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            vsr[i].insert(j);
            vsc[j].insert(i);
        }
    }

    queue<pair<int,pair<int,int> > >Q;
//    Q.push(make_pair(0,make_pair(r1,c1)));//make_pair可以用{}初始化。
    Q.push({0,{r1,c1}});
    update(r1,c1);

    while(!Q.empty())
    {
        int nr=Q.front().second.first,nc=Q.front().second.second,step=Q.front().first;
//        cout<<nr<<" "<<nc<<endl; //
        Q.pop();
        if(nr==r2&&nc==c2)
        {
            cout<<step<<endl;
            return 0;
        }
        //auto it = lower_bound(vsr[nr].begin(),vsr[nr].end(),nc);这里的set直接有lower_bound的
        auto it = vsr[nr].lower_bound(nc);
        while(it!=vsr[nr].end()&&*it-nc<=k&&maze[nr][*it]=='.')
        {
            //Q.push(make_pair(step+1,make_pair(nr,*it)));
            Q.push({step+1,{nr,*it}});
            //it++;//感觉这句必须放在udate前面//这里有更新语句就别用++了
            update(nr,*it);
            it=vsr[nr].lower_bound(nc);
        }
        it = vsr[nr].lower_bound(nc);
        while(it!=vsr[nr].begin() &&nc-*(--it)<=k&&maze[nr][*it]=='.')//注意这里是*(--it)而且还可以跟begin比较，为什么？（提示，也跟上一个while语句有关联）
        {
            Q.push({step+1,{nr,*it}});
            update(nr,*it);
            it = vsr[nr].lower_bound(nc);
        }
        it = vsc[nc].lower_bound(nr);
//        while(it!=vsc[nc].begin()&&*it-nr<=k&&maze[*it][nc]=='.')//好蠢，打代码总是记不住每个变量的含义，这里又达成了begin了
        while(it!=vsc[nc].end()&&*it-nr<=k&&maze[*it][nc]=='.')
        {
            Q.push({step+1,{*it,nc}});
            update(*it,nc);
            it = vsc[nc].lower_bound(nr);
        }
        it = vsc[nc].lower_bound(nr);
        while(it!=vsc[nc].begin()&&nr-*(--it)<=k&&maze[*it][nc]=='.')
        {
            Q.push({step+1,{*it,nc}});
            update(*it,nc);
            it=vsc[nc].lower_bound(nr);
        }
    }
    cout<<-1<<endl;
    return 0;

}


int main()
{
    ios::sync_with_stdio(false);

    cin>>r>>c>>k;
    for(int i=0;i<r;i++)
    {
        string s;
        cin>>s;
        maze.push_back(s);
    }

    cin>>r1>>c1>>r2>>c2;
    solve1();


    return 0;
}
