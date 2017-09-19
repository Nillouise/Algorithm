//������ֵ��� Ҫ �������������Ϊ ������ֵ����ǰ����˳ʱ�����ʱ�����ã����� ������ֵ���

#include<algorithm>
#include<iostream>
#include<string>
#include<stack>
#include<set>
#include<functional>
#include<queue>
using namespace std;

int p, q;
int chess[50][50];
struct point
{
	int x, y;
	point(int x = 0, int y = 0) :x(x), y(y) {}
};
point path[1000];
int inning[8][2] = {
	{ -2,-1 },
	{ -2,1 },
	{ -1,-2 },
	{ -1,2 },
	{ 1,-2 },
	{ 1,2 },
	{ 2,-1 },
	{ 2,1 }
};

bool dfs(int x, int y, int step)
{
	if (x == 3 && y == 4)
	{
		int a = 0;
	}

	if (x<1 || x>p || y<1 || y>q)
		return false;
	path[step] = point(x, y);
	if (chess[x][y] == 1)return false;
	if (step == p*q) return true;
	chess[x][y] = 1;
	for (size_t i = 0; i < 8; i++)
	{
		if (dfs(x + inning[i][0], y + inning[i][1], step + 1) == true)
			return true;
	}
	chess[x][y] = 0;
	return false;
}
int printPath()
{
	for (size_t k = 1; k <= p*q; k++)
	{
		char x = 'A' + path[k].x - 1;
		int y = path[k].y;
		cout << x << y;
	}
	cout << endl;
	return 0;
}

int main()
{
	freopen("input.txt", "r", stdin);

	int N;
	cin >> N;
	for (size_t n = 1; n <= N; n++)
	{
		memset(chess, 0, sizeof(chess));
		cin >> q >> p;//����� p q�ǵ�ת˳�����ģ���Ϊ���ҵĳ���x���ϵ��� ABCD��y���ϵ������֣�����Ŀ��p�����֣�q����ĸ
					  //���Ҫ��ת�����������棬x���������һά�ﻹ��2ά ��û�й�ϵ
		cout << "Scenario #" << n << ":" << endl;
		int flag = 0;
		for (size_t i = 1; i <= p; i++)
		{
			for (size_t j = 1; j <= q; j++)
			{
				if (dfs(i, j, 1) == true)
				{
					flag = 1;
					printPath();
					break;
				}
			}
			if (flag)break;
		}
		if (!flag)cout << "impossible" << endl;
		cout << endl;
	}


	return 0;
}