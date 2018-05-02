#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

int dat[1000000];
int n;
vector<int> G[1000000];
vector<int> G2[1000000];
int ans1[1000000];
int ans2[1000000];

void dfs1(int x,int p,int v)
{
	if(p==-1){
		for(auto a:G[x])
		{
			dfs1(a,x,dat[a]);
		}
		ans1[x] = dat[x];
	}else{
		for(auto a:G[x]){
			if(a!=p)
				dfs1(a,x,__gcd(dat[x],v));
		}
		ans1[x] = __gcd(dat[x],v);
	}
}

void dfs2(int x,int p,map<int,int> rm,int dep)
{
	int MAX = 1;
	for(auto &a:rm){
		if(dat[x]%a.first==0){
			a.second++;
		}
		if(a.second>=dep-1){
			MAX = max(MAX,a.first);
		}
	}
	for(auto a:G[x]){
		if(a!=p)
			dfs2(a,x,rm,dep+1);
	}
	ans2[x] = MAX;
	
}



int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>dat[i+1];
	}
	for(int i=0;i<n-1;i++){
		int u,v;cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1,-1,0);
	map<int,int> rm;
	for(int i=1;i*i<=dat[1];i++){
		if(dat[1]%i==0){
			rm[i]++;
			rm[dat[1]/i]++;
			if(i*i==dat[1])rm[i]--; 
		}
	}
	dfs2(1,-1,rm,1);
	for(int i=1;i<=n;i++){
		cout<<max(ans1[i],ans2[i])<<" ";
	}
	cout<<endl;

	return 0;
}
