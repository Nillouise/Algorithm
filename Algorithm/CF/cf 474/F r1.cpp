#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m;
map<int,int> mc[100000+100];

//此函数配合lowerbound，做出的是关于w的什么效果？ 就是找比w小的最长链（而不是找以w为结尾的最长链） 
int get(int x,int w)
{
	 auto it = mc[x].lower_bound(w);
	 if(it==mc[x].begin())return 0;
	 it--;
	 return it->second;
}



int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	int ans = 0;
	for(int i=0;i<m;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		int len = get(a,w);
		if(len<get(b,w+1))continue;
		mc[b][w]=len+1;
		auto it = mc[b].upper_bound(w);
		//LIS注意点，更新时需要考虑删除 
		while(it!=mc[b].end()&&it->second<=len+1)
		{
			it = mc[b].erase(it);
		}
		ans = max(ans,len+1);
	}
	cout<<ans<<endl;
	
}