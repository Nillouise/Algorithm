//�����dp��û������������ֻ�Ǹ�dag���ѣ�����dp����ֻҪ��¼��ǰ��ֵ�ܲ��ܹ�������Ϳ�����
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
const int maxn = 20;//����һ��Ҫ������10000����Ȼ�������֡�5λ�������������´�����Ϊvis����ֻ����10000������runtime error
const int INF = 10000000;
int cash;
int N;
int bills[maxn];
int domin[maxn];
int dp[100000 + 10];//����һ��Ҫ+10����Ȼ��wa

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
		dp[0] = 1;//0�ǿ϶����Ե�
		int MAX = 0;
		for (int i = 0; i < N; i++)
		{
			//			for (int j = cash; j >= 0; j--)//�������j==cash ������MAX�Ż�
			for (int j = MAX; j >= 0; j--)
			{
				if (dp[j] == 1)//��dp[j]һ��Ҫ���������Ȼ tl
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