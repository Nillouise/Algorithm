//这题我犯了一个错误，没有把二分法要用到的数据放全

#include <iostream>
#include <cstdio>
#include <cstring>
#include<string>
#include <algorithm>
#include<sstream>
#include<cmath>//这里有log 函数
using namespace std;
const int maxn = 50000 + 5;
int L, N, M;
int dist[maxn];

int main() {
	freopen("input.txt", "r", stdin);

	while (cin >> L >> N >> M)
	{
		dist[0] = 0;
		for (size_t i = 1; i < N + 1; i++) cin >> dist[i];
		dist[N + 1] = L;

		sort(dist, dist + N + 2);
		int low = L, height = L + 1;//二分法的上端最好是指向不可能的值
		for (size_t i = 1; i < N + 2; i++)
			low = min(dist[i] - dist[i - 1], low);
		//下面这种做法不科学的，会造成二分法用到的数组的数据不全
		//low = min(low, L - dist[N - 1]);//上面没有算最后一个石头到右边岸的距离
		//low = min(dist[0], low);//上面没有算开始的石头到左边岸的距离
		while (low < height - 1)
		{
			int mid = low + (height - low) / 2;
			int cnt = 0;
			int lefti = 0;
			//忘记比较两岸的距离
			//下面这种思路是不对的，lefti是最左边的石头在数组的下标，而河岸的坐标根本
			//不在数组里，这么写很容易出错
			//if (dist[0] < mid) {
			//	cnt++;
			//	lefti = 1;
			//}

			for (size_t i = lefti + 1; i < N + 2; i++)
			{
				if (dist[i] - dist[lefti] < mid)//这里我写错成>号，没有记清变量含义
				{
					cnt++;
					continue;
				}
				else {
					lefti = i;
				}
			}
			//错的			if (L - dist[lefti] < mid)cnt++;

			if (cnt > M) {
				height = mid;
			}
			else {
				low = mid;
			}

		}
		cout << low << endl;

	}



	return 0;
}