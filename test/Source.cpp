using namespace std; 
typedef long long LL;
#define MX 1005 
#define MOD 1000000007 
#include<cstdio>
#include<cstring>
LL C[MX][MX], bit[MX]; 
int N; 
char R[MX]; 
void init() 
{ 
	int i, j; 
	bit[0] = 1LL; 
	for (i = 1; i < MX; i ++) 
	{
		bit[i] = 2 * bit[i - 1] % MOD;
	} 
	C[0][0] = 1; 
	for (i = 1; i < MX; i ++) 
	{ 
		C[i][0] = C[i][i] = 1; 
		for (j = 1; j < i; j ++) 
		{ 
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
		} 
	}
} 
int main()
{ 
	init(); 
	int Tcase, i, one; 
	while (scanf("%d %s", &N, R) == 2)
	{ 
		int len = strlen(R); 
		int rlt = 0; 
		long long B = 0; 
		for (i = 0; i < len && N >= 0; i ++) 
		{ 
			if (R[i] == '1')
			{ 
				if (N <= len - i - 1) 
				{ 
					if (N) 
						rlt = (rlt + (long long) (bit[len - i - 1] - 1) * C[len - i - 2][N - 1] % MOD) % MOD; 
					rlt = (rlt + B * C[len - i - 1][N] % MOD) % MOD; 
					B += bit[len - i - 1]; 
					B %= MOD; 
					N --; 
				} 
			} 
		} 
		if (rlt < 0)
			rlt += MOD; 
		printf("%d\n", rlt); 
	} 
}