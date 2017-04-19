//这题的dp并没有容量这个概念，只是个dag而已，所以dp数组只要记录当前的值能不能构造出来就可以了
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<stack>
#include<set>
#include<functional>
#include<map>
#include<queue>
using namespace std;
const int maxn = 20;//这里一定要贴近到10000，不然会加入奇怪、5位数的质数，导致错误（因为vis数组只开了10000，导致runtime error
const int INF = 10000000;
int cash;
int N;
int bills[maxn];
int domin[maxn];
int dp[100000 + 10];//这里一定要+10，不然会wa

int main()
{
	freopen("input.txt", "r", stdin);

	while (cin >> cash >> N)
	{
		for (size_t i = 0; i < N; i++)
		{
			cin >> bills[i] >> domin[i];
		}

		memset(dp, 0, sizeof(dp));
		dp[0] = 1;//0是肯定可以的
		int MAX = 0;
		for (int i = 0; i < N; i++)
		{
			//			for (int j = cash; j >= 0; j--)//这里这个j==cash 可以用MAX优化
			for (int j = MAX; j >= 0; j--)
			{
				if (dp[j] == 1)//判dp[j]一定要放在这里，不然 tl
					for (int k = 1; k <= bills[i]; k++)
					{
						if (j + k*domin[i] <= cash)
						{
							dp[j + k*domin[i]] = 1;
							MAX = max(j + k*domin[i], MAX);
						}
						else {
							break;
						}
					}
			}
		}
		cout << MAX << endl;
	}



	return 0;
}