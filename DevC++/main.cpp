#include<cstdio>
#include<cstring>
using namespace std;

typedef long long LL;

const int MAXN = 1005;

double dp[MAXN][MAXN];
int n,m;
int main()
{
	
	while(~scanf("%d%d",&n,&m))
	{
		memset(dp,0,sizeof(dp));
		for(int i=n;i>=0;i--){
			for(int j=m;j>=0;j--)
			{
				if(i==n&&j==m){
					continue;
				}
//				dp[i][j] = (1.0*i/n*(m-j)/m * dp[i][j+1] + 1.0*(n-i)/n*j/m*dp[i+1][j] 
//							+ 1.0*(n-i)/n*(m-j)/m*dp[i+1][j+1] +1.0)/(1.0 - 1.0*i/n*j/m);
//							/(1.0 - 1.0*(i+j)/(n+m)); 这是错的 

     		   double p1, p2, p3, p4;  int s = m;
				p1 = 1.0*(n-i)*(s-j) / (n*s);  
                p2 = 1.0*(n-i)*j     / (n*s);  
                p3 = 1.0*i*(s-j)     / (n*s);  
                p4 = 1.0*i*j         / (n*s);  
				dp[i][j] = (p1*dp[i+1][j+1] + p2*dp[i+1][j]  // 状态转移  
							+ p3*dp[i][j+1]    + 1)  
							/ (1-p4);  
			}
		}
		
		printf("%.4lf\n", dp[0][0]);
	}
	

    return 0;
}
