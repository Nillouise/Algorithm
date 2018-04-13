#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL A[100000+100],B[100000+100];
int N;


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    cin>>N;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > q;
    for (int i = 0; i < N; i++) {
        cin>>A[i];
    }
    sort(A,A+N);
    for (int i = 0; i < N; i++) {
        cin>>B[i];
    }
    sort(B,B+N);
    for (int i = 0; i < N; i++) {
        q.push({A[i]+B[0],0});
    }
    int cnt = 0;
    while(cnt<N)
    {
        pair<int,int> p = q.top();q.pop();
        cout<<p.first<<" ";
        
        q.push({p.first-B[p.second]+B[p.second+1],p.second+1});
        cnt++;
    }
    cout<<endl;
    
    
    
    return 0;
}