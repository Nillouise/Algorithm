#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int n;
string s;
LL dp[10000+100];

int tri[30000+100][30][2];
int vis[10000+100];

LL dfs(int x)
{
	if(x==s.size())
	{
//		cout<<"end"<<x<<endl;
		return 0;
	}else if(x>s.size())
	{
		return -0x3f3f3f;
	}
	if(vis[x]==1)
	{
		return dp[x];
	}
	
	vis[x]=1;
	
//	for(auto a:m)
//	{
//		int flag=1;
//		if(x + a.first.size() > s.size())continue;
//		for(int b = x; b< a.first.size();b++)
//		{
//			if(s[b]!=a.first[b-x])
//			{
//				flag=0;
//				break;
//			}
//		}
//		if(flag==1)
//		{
////			getchar();
////			cout<<x<< " " <<a.first<<endl;//
//			dp[x]= max(dfs(x+a.first.size())+a.second,dp[x]);
//		}
//	}
	int be = 0,len = 0;
	for(;;)
	{
		if(x+len>=s.size())break;
//		cout<<" be"<<be<<endl;
		
		if(tri[be][s[x+len] -'a'+1 ][0]!=-1)
		{
//			cout<<x<<"x "<<x+len<<" "<<tri[be][s[x+len] -'a'+1 ][0]<<endl;
			dp[x]  = max(dfs(x+len+1)+tri[be][s[x+len] -'a'+1 ][0],dp[x]);
		}
		be = tri[be][s[x+len] -'a'+1 ][1];
		if(be == -1)
		{
			break;
		}
		len++;
	}					     
	

//	for(auto a:G[x])
//	{
//		dp[x] = max(dfs(x+a.first)+a.second,dp[x]);
//	}
	
	return dp[x];
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
//freopen("input.txt","r",stdin);
	while(cin>>n>>s)
	{
		memset(dp,-0x3f3f3f,sizeof(dp));
		memset(tri,-1,sizeof(tri));
		memset(vis,0,sizeof(vis));
		int len = 1;
		
		for(int i=0;i<n;i++)
		{
			string t;int w;
			cin>>t>>w;
			int be = 0;
			for(int j = 0;j<t.size();j++)
			{
				char a = t[j];
				if(j==t.size()-1)
				{
					tri[be][a-'a'+1][0] = w;
					break;
				}
				
				if(tri[be][a-'a'+1][1]==-1){
					tri[be][a-'a'+1][1] = len;
					len++;
				}
				be = tri[be][a -'a'+1][1];
			}
		}
		
		
		dfs(0);
		if(dp[0]<0)
		{
			cout<<-1<<endl;
		}else{
			cout<<dp[0]<<endl;
		}
	}
	return 0;
}
