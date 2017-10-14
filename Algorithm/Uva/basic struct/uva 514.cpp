//一开始我还理解错了数据（把一个变量当成另一个变量的意思），导致连样例都看不懂，还怀疑样例
//以后看错样例要注意这一点
#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;
typedef long long LL;



int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);

	int N;
	while (cin >> N, N != 0)
	{
		for (;;)
		{
			vector<int> v(N);
			cin >> v[0];
			if (v[0] == 0)
			{
				cout << endl;
				break;
			}
			for (int i = 1; i < N; i++)
			{
				cin >> v[i];
			}

			stack<int> s;
			int j = 0;
			int i = 1;
			int flag = 1;

			while (true)
			{
				if (j == N) { break; }//一开始还忘记判断成功的退出条件
				else if (v[j] == i) { i++, j++; }
				else if (!s.empty() && s.top() == v[j]) { s.pop(); j++; }
				else if (i <= N) { s.push(i); i++; }
				else { flag = 0; break; }
			}

			if (flag == 0)
			{
				//cout << "NO" << endl;//万万没想到，这个对大小写敏感
				cout << "No" << endl;
			}
			else
			{
				cout << "Yes" << endl;
			}
		}


	}







	return 0;
}
