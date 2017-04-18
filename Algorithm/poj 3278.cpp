#include<algorithm>
#include<iostream>
#include<string>
#include<stack>
#include<set>
#include<functional>
#include<queue>
using namespace std;

int N, K;
int d[20 * 10000 + 5];


int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N >> K;
	memset(d, -1, sizeof(d));

	queue<int>q;
	d[N] = 0;
	q.push(N);
	while (!q.empty())
	{
		int c = q.front(); q.pop();
		if (c < K)
		{
			if (d[c + 1] == -1)
			{
				q.push(c + 1);
				d[c + 1] = d[c] + 1;
			}
			if (d[c * 2] == -1)//这里可能会导致溢出，为什么？因为最大的数*2之后会超出正常的数组
			{
				q.push(c * 2);
				d[c * 2] = d[c] + 1;
			}
		}
		if (c - 1 >= 0)
			if (d[c - 1] == -1)//这里边界处理 没处理好；可能导致数组下标为-1
			{
				q.push(c - 1);
				d[c - 1] = d[c] + 1;
			}
		if (d[K] != -1)
		{
			cout << d[K] << endl;
			break;
		}
	}


	return 0;
}