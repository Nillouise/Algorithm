//��=��=��a ����
//coverse�����жϱ߽�
//��converse x y��д��converse x2,y2�ˣ��������������ĸ��ż��Ҳ����ĵ��µ�
//û�п���Ŀ���� Impossible �����
//impossible û�ж���ɳ���INF
//û�п��Ǳ߽������û�б�check ��
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int m[4][4];
const int INF = 10000;
int minGold = INF;


void coverse(int x, int y)
{
	if (x - 1 >= 0)
		m[x - 1][y] = !m[x - 1][y];
	if (x + 1<4)
		m[x + 1][y] = !m[x + 1][y];
	m[x][y] = !m[x][y];
	if (y - 1 >= 0)
		m[x][y - 1] = !m[x][y - 1];
	if (y + 1<4)
		m[x][y + 1] = !m[x][y + 1];


}

int check()
{
	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
		{
			if (m[i][j] != m[0][0])
				return 0;
		}
	return 1;

}

int dfs(int x, int y, int cnt)
{
	if (check())
	{
		minGold = min(cnt, minGold);
		return 0;
	}
	if (x >= 4 || y >= 4)
		return 0;
	int x2 = (x + 1) % 4;
	int y2 = (y)+(x + 1) / 4;
	dfs(x2, y2, cnt);
	coverse(x, y);
	dfs(x2, y2, cnt + 1);
	coverse(x, y);

	//if (x == 0 && y == 1)
	//	for (int i = 0; i<4; i++)
	//	{

	//		for (int j = 0; j<4; j++)
	//			cout << m[i][j] << " ";
	//		cout << endl;
	//	}
	return 0;
}

int main()
{
	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
		{
			char c;
			cin >> c;
			m[i][j] = (c == 'b' ? 0 : 1);
		}
	dfs(0, 0, 0);
	if (minGold == INF)
		cout << "Impossible" << endl;
	else
		cout << minGold << endl;
	return 0;
}
