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
#include <ctime>
#include <bitset>
using namespace std;
typedef long long LL;



int main()
{
	freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(false);
	int T;
	cin >> T;


	while (T--)
	{
		int D, I;
		cin >> D >> I;
		int cnt = I - 1;
		int ind = 1;
		//最后叶子节点没得选择，只会选择D-1次的
		for (int d = 0; d<D - 1; d++)
		{
			if (cnt % 2 == 0)
			{
				ind *= 2;
				cnt = cnt / 2;
			}
			else
			{
				ind = ind * 2 + 1;
				cnt = cnt / 2;
			}
		}
		cout << ind << endl;
	}
	return 0;
}