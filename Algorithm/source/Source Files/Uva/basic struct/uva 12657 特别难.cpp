//这个双向链表，一开始还忘记了移动一个结点时，要弥合原来的位置了
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
const int MAXN = 100000 + 5;
int let[MAXN], rit[MAXN];
int inverse = 0;
int n, m;
void link(int x, int y)
{
	rit[x] = y;
	let[y] = x;
}


int main()
{
	freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(false);

	int t = 1;
	while (cin >> n >> m)
	{
		for (int i = 1; i <= n + 1; i++)
		{
			link(i - 1, i);
		}

		inverse = 0;
		while (m--)
		{
			int com, a, b;
			cin >> com;
			if (com == 4)
			{
				inverse = !inverse;
			}
			else
			{
				cin >> a >> b;

				//				int i = rit[0];
				//				int pos = 1;
				//				while (i != n + 1)
				//				{
				//									cout << i << " ";
				//					i = rit[i];
				//				}
				//				cout << endl;
				if (com == 3)
				{
					//这是错的
					//					//一开始忘记弥合这个la了//这里交换是不用弥合的
					//					int la = let[a];
					//					int ra = rit[a];
					//					int lb = let[b];
					//					int rb = rit[b];
					//					//先弥合，后解决其他问题
					//					link(la, ra);
					//					link(lb, rb);
					//好像要先交换了，才能找点
					if (rit[b] == a)swap(a, b);

					int lb = let[b];
					int rb = rit[b];
					int la = let[a];
					int ra = rit[a];

					//					//这里要特别处理这两点是相邻的情况。
					//
					//					if (rit[b] == a)swap(a, b);
					if (rit[a] == b)
					{
						link(a, rb);
						link(b, a);
						link(la, b);
					}
					else
					{
						link(lb, a);
						link(a, rb);
						link(la, b);
						link(b, ra);
					}


					//					int lx = let[a];
					//					int rx = rit[a];
					//					int ly = let[b];
					//					int ry = rit[b];
					//					link(lx, b);
					//					link(b, rx);
					//					link(ly, a);
					//					link(a, ry);

				}
				else
				{
					if (inverse)
					{
						if (com == 1)com = 2; else com = 1;
					}
				}
				if (com == 1)
				{
					//这里的link是会改变后面let获取的内容的，索引要先弥合
					//一开始忘记弥合这个la了
					int la = let[a];
					int ra = rit[a];
					link(la, ra);

					int ly = let[b];
					//这里的link是会改变后面let获取的内容的
					link(ly, a);
					link(a, b);

				}
				//				else //这里把com==3的情况也包括进来了，下次一定要写请条件
				else if (com == 2)
				{
					//是把a割掉，而不是把b割掉
					//					int lb = let[b];
					//					int rb = rit[b];
					//					link(lb, rb);
					int la = let[a];
					int ra = rit[a];
					link(la, ra);

					int ry = rit[b];

					link(a, ry);
					link(b, a);



				}
			}
		}
		LL total = 0;
		if (!inverse)
		{
			int i = rit[0];
			int pos = 1;
			while (i != n + 1)
			{
				if (pos & 1)
					total += i;
				//				cout << i << " ";
				i = rit[i];
				pos++;
			}
		}
		if (inverse)
		{
			int i = let[n + 1];
			int pos = 1;
			while (i != 0)
			{
				if (pos & 1)
					total += i;
				//				cout << i<<" ";
				i = let[i];
				pos++;
			}
		}
		cout << "Case " << t++ << ": " << total << endl;

	}


	return 0;
}