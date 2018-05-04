#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=1e6+100;
vector<LL> path;


int main()
{
	ios::sync_with_stdio(false);
	LL m;cin>>m;
	int c = m;
	vector<int> ans;
	while(c){
		ans.push_back(c/2+c%2);
		c/=2;
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for(auto a:ans){
		cout<<a<<" ";
	}
	
    return 0;
}

