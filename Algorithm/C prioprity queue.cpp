//优先队列

#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;
typedef long long LL;
const int maxc = 1e7 + 5;
struct F
{
	LL cost;
	LL start;
	LL next;
	bool operator < (const F &f) const  //这里要写const，代表不会修改变量
	{
		return cost < f.cost;
	}
};

F cost[maxc];


int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (size_t i = 0; i < n; i++)
	{
		cin >> cost[i].cost;
		cost[i].start = i;
	}
	priority_queue<F> Q;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		Q.push(cost[i]);
		if (Q.size() > k)
		{
			F f = Q.top();
			cost[f.start].next = i;
			Q.pop();
		}
	}
	while (!Q.empty())
	{
		F f = Q.top();
		cost[f.start].next = i++;
		Q.pop();
	}
	LL total = 0;
	for (int i = 0; i < n; i++)
	{
		//这里一开始我用的cost不是longlong，被爆掉了
		total += cost[i].cost * (cost[i].next - cost[i].start);//这里的next和start是个丑陋的想法，我没想好一个号的模型
	}
	cout << total << endl;
	for (size_t i = 0; i < n; i++)
	{
		cout << cost[i].next + 1 << " ";
	}
	cout << endl;



	return 0;
}