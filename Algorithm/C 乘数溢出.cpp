#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>//这个sqrt要用
#include<queue>
using namespace std;
typedef long long LL;

LL ab[5000 + 10];
LL ac[5000 + 10];
LL bc[5000 + 10];

LL C[5000 + 10][5000 + 10];
LL A[5000 + 10];
LL MOD = 998244353l;

void init()
{
	C[0][0] = 1;

	for (int i = 1; i<5000 + 5; i++)
	{
		C[i][0] = 1;
		for (int j = 1; j<i + 5; j++)
		{
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			C[i][j] %= 998244353l;
		}
	}

	A[0] = 1;
	A[1] = 1;
	for (LL i = 2; i<5000 + 5; i++)
	{
		A[i] = A[i - 1] * i;
		A[i] %= 998244353l;
	}

}


int main()
{
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);

	init();

	LL a, b, c;
	cin >> a >> b >> c;

	LL total = 1;
	//a与b连线
	//	for(int i=0;i<=min(a,b);i++)
	//	{
	//		//a与c连线
	//		for(int j=0;j<=min(a,c);j++)
	//		{
	//
	////			int k = 500;
	//			for(int k=0;k<=min(b,c);k++)
	//			{
	//				LL cnt = 1;
	//				cnt *= C[a][i] * A[i] * C[b][i];
	//				cnt *= C[a][j] * A[j] * C[c][j];
	//				cnt *= C[b][k] * A[k] * C[c][k];
	//				cnt %= 998244353l;
	//
	//				total += cnt;
	//				total%= 998244353l;
	//			}
	//		}
	//	}

	LL cnt = 0;
	for (int i = 0; i <= min(a, b); i++)
	{
		cnt += ((C[a][i] * A[i]) % MOD) * C[b][i] % MOD;//这里会溢出
	}
	cnt %= 998244353l;
	total = cnt;
	cnt = 0;
	for (int j = 0; j <= min(a, c); j++)
	{
		cnt += C[a][j] * A[j] % MOD * C[c][j] % MOD;
	}
	cnt %= 998244353l;
	total *= cnt;
	total %= 998244353l;
	cnt = 0;
	for (int k = 0; k <= min(b, c); k++)
	{
		cnt += C[b][k] * A[k] % MOD * C[c][k] % MOD;
	}
	cnt %= 998244353l;
	total *= cnt;
	total %= 998244353l;

	cout << total << endl;

	return 0;
}
