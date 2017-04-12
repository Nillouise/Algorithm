//���д�������������x��y
//�����check�����Ǹı�ȫ����С������ �������ֵ
//û���ڼ�����С����ʱ�����޸ı���ı���
//���ڻ��Ǵ��
//׼���ô�ӡ����+�ϵ� ����
//û�п��Ǳ߽��������Ϊ��Ҫ��check֮��ż��߽�ģ���Ȼ���һ��ı�󣬸���û�л���check��
#include<iostream>
#include<memory.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int m[4][4];
int content[20][2];
int ulcontent[20][2];
const int INF = 10000;
int ming = INF;
int turnout(int x, int y)
{
	m[x][y] = !m[x][y];
	for (int i = 0; i<4; i++)
	{
		m[x][i] = !m[x][i];
		m[i][y] = !m[i][y];
	}
	return 0;

}
int check()
{
	int ok = 1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			if (m[i][j] == 0)
				ok = 0;
	}


	if (ok == 0)
		return ok;
	return 1;
}

void log(int x, int y)
{
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (i == x && j == y)
				cout << "[";
			cout << m[i][j] << "��";
			if (i == x && j == y)
				cout << "]";
		}
		cout << endl;
	}
	cout << endl;
}

int dfs(int x, int y, int cnt)
{
	if (check())
	{
		if (ming>cnt) {
			memcpy(ulcontent, content, sizeof(ulcontent));//�ص�
			ming = cnt;
		}
		return 0;
	}

	if (x >= 4 || y >= 4)return 0;
	if (cnt >= ming)return 0;

	int x2 = (x + 1) % 4;
	int y2 = y + (x + 1) / 4;

	turnout(x, y);
	//	log(x, y);
	content[cnt][0] = x;
	content[cnt][1] = y;
	dfs(x2, y2, cnt + 1);
	turnout(x, y);

	dfs(x2, y2, cnt);


	return 0;

}

int main()
{
	freopen("input.txt", "r", stdin);
	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
		{
			char c;
			cin >> c;
			m[i][j] = (c == '-' ? 1 : 0);
		}
	//turnout(0, 0);
	//log(0,0);
	//turnout(0, 2);
	//log(0, 0);
	//turnout(0, 3);
	//log(0, 0);
	//turnout(3, 0);
	//log(0, 0);
	//turnout(3, 2);
	//log(0, 0);
	//turnout(3, 3);
	//log(0, 0);

	dfs(0, 0, 0);

	cout << ming << endl;
	for (int i = 0; i<ming; i++)
	{
		cout << ulcontent[i][0] << " " << ulcontent[i][0] << endl;
	}
	return 0;
}
