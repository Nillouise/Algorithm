//return (bit&(1 << pos))>0;这句写错了，写成(bit&(1 << pos)) == 1，殊不知这种位运算产生的根本不是1，而是真而已
#include<algorithm>
#include<iostream>
#include<string>
#include<stack>
#include<set>
#include<functional>
#include<queue>
using namespace std;



int main()
{
	freopen("input.txt", "r", stdin);
	int N;
	while (cin >> N&&N != 0)
	{
		priority_queue<int, vector<int>, greater<int> > pq;
		for (size_t i = 0; i < N; i++)
		{
			int a;
			//			cin >> a;
			scanf("%d", &a);
			pq.push(a);
		}
		long long total = 0;
		//		while (!pq.empty())//查empty会导致超时//超时不是因为empty，而是因为本身剩余节点就要大于等于2才行（而不是>=1）

		while (pq.size()>1)//这里size 要等于 2才行，不然有什么效果？就是多加了根节点一次
		{
			int a1 = pq.top(); pq.pop();
			int a2 = pq.top(); pq.pop();
			int a3 = a1 + a2;
			pq.push(a3);
			total += a3;
		}
		cout << total << endl;
	}


	return 0;
}