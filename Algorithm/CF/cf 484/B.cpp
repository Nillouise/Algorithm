#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

pair<int,int> dat[200000+10];


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int n;cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>dat[i].first;
        dat[i].second=i+1;
    }
    sort(dat,dat+n);
    priority_queue<pair<int,int>> pq;
    string s;cin>>s;
    int i=0;
    for(auto a:s){
        if(a=='0'){
            pq.push({dat[i].first,dat[i].second});
            cout<<dat[i].second<<" ";
            i++;
        }else{
            cout<<pq.top().second<<" ";
            pq.pop();
        }
    }
    
    
    
    return 0;
}