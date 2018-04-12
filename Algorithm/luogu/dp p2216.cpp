#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int a,b,n;
LL dat[1300][1300];

LL low[1300][1300];
LL up[1300][1300];

LL ylow[1300][1300];
LL yup[1300][1300];


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    cin>>a>>b>>n;
    
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin>>dat[i][j];
        }
    }
    
    for(int i=0;i<a;i++)
    {
        deque<pair<LL,LL> > q;
        deque<pair<LL,LL>> q2;
        
        for (int j = b-1; j >=0; j--) {
            while(q.size()>0&& q.front().first - j  >= n)q.pop_front();
            while(q.size()>0&&q.back().second <=dat[i][j]) q.pop_back();
            q.push_back({j,dat[i][j]});
            up[i][j] = q.front().second;
            // cout<<up[i][j]<<" ";
        }
        // cout<<endl;//
        for (int j = b-1; j >=0; j--) {
            while(q2.size()>0&& q2.front().first - j  >= n)q2.pop_front();
            while(q2.size()>0&&q2.back().second >=dat[i][j]) q2.pop_back();
            q2.push_back({j,dat[i][j]});
            low[i][j] = q2.front().second;
            // cout<<low[i][j]<<" ";
        }
        // cout<<endl;//
    }
    
    
    for (int j = 0; j < b; j++) {
        deque<pair<LL,LL> > q;
        deque<pair<LL,LL>> q2;
        // for (int i = 0; i < a; i++) {
        for(int i=a-1;i>=0;i--){
            while(q.size()>0&& q.front().first - i  >= n)q.pop_front();
            while(q.size()>0&&q.back().second <=up[i][j]) q.pop_back();
            q.push_back({i,up[i][j]});
            yup[i][j] = q.front().second;
        }
        
        for(int i=a-1;i>=0;i--){
            while(q2.size()>0&&  q2.front().first - i >= n)q2.pop_front();
            while(q2.size()>0&&q2.back().second >=low[i][j]) q2.pop_back();
            q2.push_back({i,low[i][j]});
            ylow[i][j] = q2.front().second;
        }
    }
    LL ans = 1e12;
    
    for (int i = 0; i < a-n+1; i++) {
        for (int j = 0; j < b-n+1; j++) {
            ans = min(ans,yup[i][j]-ylow[i][j]);
            cout<<yup[i][j]<<" "<<ylow[i][j]<<" ";
        }
        cout<<endl;//
    }
    
    cout<<ans<<endl;
    
    return 0;
}