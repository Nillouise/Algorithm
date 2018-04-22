#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

string s1 = "CCC";
string s2 = "PCPC";
string s3 = "CCPP";
string s4 = "CPC";
string s5 = "CCP";

int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int T;cin>>T;
    while(T--)
    {
        int flag=0;int n;string s;cin>>n>>s;
        int pos = -1;
        int cnt =0;
        do
        {
        	pos = s.find("CCPC",pos+1);
        	
			if(pos==s.npos)break;
        	else cnt++;
        	s[pos+1]='X';s[pos+2]='X';
		}while(pos!=s.npos);
        
        if(s.find("CCC")!=s.npos){
        	flag=1;
		}else if(s.find("CPC")!=s.npos)
		{
			flag=1;
		}else if(s.find("CCP")!=s.npos){
			flag=1;
		}
        
        
        cout<<cnt+flag<<endl;//
        
    }
    
    
    
    
    
    
    return 0;
}