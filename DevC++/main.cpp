#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
int dat[10000];


int ql,qr;
int query(int o,int L,int R)
{
	int M = L+(R-L)/2,ans = INF;
	if(ql<=L && R<= qr) return minv[o];
	
}


int dfs(int a,int b,int h)
{
	if(a>b)return 0;
	
	int shu = 0;
	for(int i=a;i<=b;i++)
	{
		if(dat[i]>h){
			shu++;
		}
	}
	int nh = 1e9;
	int ni = 0;
	for(int i=a;i<=b;i++)
	{
		if(dat[i]<nh){
			ni=i;
			nh=dat[i];
		}
	}
	int heng = dfs(a,ni-1,nh)+dfs(ni+1,b,nh);
	heng+=nh-h;
	return min(heng,shu);
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>dat[i];
	}
	cout<<dfs(0,n-1,0)<<endl;
	
	
	
	
}
