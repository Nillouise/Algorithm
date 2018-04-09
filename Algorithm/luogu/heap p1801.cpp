#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL dat[200000+100];
LL u[200000+100];

int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    priority_queue<LL> down;
    priority_queue<LL,vector<LL>,greater<LL>> up;
    
    int M,N;
    cin>>M>>N;
    for (int i = 0; i < M; i++) {
        cin>>dat[i];
     }
    for (int i = 0; i < N; i++) {
        cin>>u[i];
    }
    int k=0;
    for (int i = 0; i < M; i++) {
        // if(k>=N)break;
        if(u[k]==i)
        {
            cout<<up.top()<<endl;
            down.push(up.top());
            up.pop();
            k++;
            // i--;//这么干是错的，因为会重复push进一个东西！！！
        }else{
            down.push(dat[i]);
            up.push(down.top());
            down.pop();
        }
    }
    // int b = 0;
    // for (int i = 0; i < N; i++) {
    //     for(;b<u[i];b++)
    //     {
    //         down.push(dat[b]);
    //         up.push(down.top());
    //         down.pop();
    //     }
    //     cout<<up.top()<<endl;
    //     down.push(up.top());
    //     up.pop();
    // }
    
    
    
    return 0;
}