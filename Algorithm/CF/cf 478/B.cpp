#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

LL dat[15];
LL tmp[15];
int main()
{
	ios::sync_with_stdio(false);
	for(int i=0;i<14;i++)
	{
		cin>>dat[i];
	}
	LL ans = 0;
	for(int i=0;i<14;i++)
	{
		if(dat[i]==0)continue;
		
		LL all = dat[i]/14;
		LL rem = dat[i]%14;
		
		memcpy(tmp,dat,sizeof(dat));
		dat[i]=0;//注意这里，要清零！！！ 
		for(int j = 1;j<14&&rem>0;j++)
		{
			dat[(i+j)%14]++; 
			rem--;
		}
		LL cs = 0;
		for(int i=0;i<14;i++)
		{
			if((all+dat[i])%2==0)
			{
				cs+=all+dat[i];
			}
		}
		ans = max(ans,cs);
		memcpy(dat,tmp,sizeof(dat));
	}
	cout<<ans<<endl;
	
	

	return 0;
}