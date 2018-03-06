#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int n,L;
int DP[100][200];
vector<int> G[100];
int cur=1;
int MAX=0;
void dfs(int x,int l)
{
    if(l>MAX)MAX=l;
    for(auto a:G[x]){
        dfs(a,l+1);
    }
}

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    cin>>n>>L;
    L++;
    memset(DP,-1,sizeof(DP));
    for(int i=0;i<n-1;i++){
        int a;
        cin>>a;
        G[a].push_back(i+1);
    }
    dfs(0,1);
    // cout<<MAX<<endl;
    int r = (L-MAX)/2;
    if(L<=MAX){
        cout<<L<<endl;
    }else if(r+MAX>n){
        cout<<n<<endl;
    }else{
        cout<<r+L<<endl;
    }
    
    
    return 0;
}
