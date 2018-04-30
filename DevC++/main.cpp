#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m;


int main()
{
	ios::sync_with_stdio(false);
	
	int T;cin>>T;
	while(T--)
	{
		LL x;cin>>x;
		int flag = 0;
		for(LL i=1;i*i<10+x;i++)
		{
			cout<<"i "<<i<<endl;//
			LL a = sqrt(i*i+x);
			if(a >36514 )
			{
				cout<<"OK"<<a<<endl;
			}
			
			if(a*a == i*i+x){
				int zu = (a)/i;
				if( zu * i+zu-1 >= a&& zu*i <= a    ){
					flag = 1;
					cout<<a<<" "<<zu<<endl;
					break;
				}
			}
		}
		if(flag==0){
			cout<<-1<<endl;
		}
		
	}
	
	
		
}
