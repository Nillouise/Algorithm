// https://www.luogu.org/problemnew/solution/P2024?page=2
//这题有意思

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int N,K;

int fa[50000*5+100];

int find(int x)
{
    // if(x==fa[x])return x;
    // return fa[x] = find(fa[x]);
    return x==fa[x]?x:fa[x] = find(fa[x]);

}


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    // ios::sync_with_stdio(false);
    
    cin>>N>>K;
    for(int i=0;i<50000*5+100;i++)fa[i]=i;
    int a,b,x;
    int ans = 0;
    for (int i = 0; i < K; i++) {
        cin>>x>>a>>b;
        // x= Input(),a=Input(),b=Input();
        if(a>N||b>N||a<1||b<1){ans++;continue;}
        if(x==2&&a==b){ans++;continue;}
        int a1 = find(a),b1 = find(b);
        int a2 = find(a+N),b2 = find(b+N);
        int a3 = find(a+2*N),b3 = find(b+2*N);
        if(x==1)
        {
            if(a1==b2||a1==b3){ans++;continue;}
            fa[a1] = b1;
            fa[a2]=b2;
            fa[a3]=b3;
            // fa[b1]=a1;
            // fa[b2]=a2;
            // fa[b3]=a3;
        }else{
            if(b1==a2||b2==a3||a1==b3){ans++;continue;}
            // if(a1==a2){ans++;continue;}//一开始写错了这里，导致mle，应该是导致无限递归了。
            if(a1==b1){ans++;continue;}
            fa[a1] = b2;
            fa[a2]=b3;
            fa[a3]=b1;
            // fa[b2] = a1;
            // fa[b3]=a2;
            // fa[b1]=a3;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}