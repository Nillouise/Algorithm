#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int vis[50000+100];
struct Token
{
    int cnt,x;
    bool operator < (const Token& t)const
    {
        if(cnt==t.cnt)
        {
            // return x<t.x;// 优先队列似乎是把大的数先出
            return x>t.x;
        }else{
            // return cnt>t.cnt;
            return cnt<t.cnt;
        }
    }
};

int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    priority_queue<Token > pq;
    for (int i = 0; i < n; i++) 
    {
        int a;
        cin>>a;
        if(i!=0)
        {
            cout<<a<<":";
            set<int> but;
            while(!pq.empty()&&but.size()<k)
            {
                Token u = pq.top(); pq.pop();
                if(but.find(u.x)==but.end())
                {
                    cout<<" "<<u.x;
                    but.insert(u.x);
                }
            }
            cout<<endl;
            vis[a]++;
            but.insert(a);
            for(auto a:but)
            {
                pq.push({vis[a],a});
            }
        }else{
            vis[a]++;
            pq.push({1,a});
        }
    }
    

    return 0;
}
