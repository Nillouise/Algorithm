//���������������Ƿ�ע����ָ�������������û�п���
//����ϵ�仯���Ǻ���Ϥ���任����һ��
//getPos����û�п��Ǻñ߽磬�����Ǵ�1��ʼ��ŵ�
#include<algorithm>
#include<iostream>
#include<string>
#include<stack>
#include<fstream>
using namespace std;
const int width = 1000;
const int height = 1000;
int N, M;
int A, B;
struct Robot
{
	int direction = -1;
	int Number = 0;
};
int goforward[4][2] = { 0,1,1,0,0,-1,-1,0 };

Robot chess[width][height];
int getPos(int &x, int &y, int Num)
{
	for (size_t i = 0; i <= A; i++)
		for (int j = 0; j <= B; j++)
			if (chess[i][j].Number == Num)
			{
				x = i;
				y = j;
				return 1;
			}
	return 0;
}

int checkcrash(int x, int y)
{

	if (x<1 || x>A || y<1 || y>B)
		return 1;
	if (chess[x][y].Number != -1)
		return 2;
	return 0;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int K;
	cin >> K;
	for (int k = 1; k <= K; k++)
	{
		for (size_t i = 0; i < width; i++)for (int j = 0; j < height; j++) { chess[i][j].direction = -1; chess[i][j].Number = -1; }
		cin >> A >> B;
		cin >> N >> M;

		int x, y;
		string s = "NESW";
		char direction;
		for (size_t j = 0; j < N; j++)
		{
			cin >> x >> y >> direction;
			chess[x][y].direction = s.find(direction);
			chess[x][y].Number = j + 1;
		}
		int flag = 1;
		for (size_t j = 0; j < M; j++)
		{
			int Num, rep;
			char instrusion;
			cin >> Num >> instrusion >> rep;
			if (flag == 0)continue;
			int x, y, curdirection;
			getPos(x, y, Num);
			curdirection = chess[x][y].direction;
			for (size_t r = 0; r < rep; r++)
			{
				chess[x][y].direction = -1;
				chess[x][y].Number = -1;
				switch (instrusion)
				{
				case 'L':
					curdirection = (curdirection - 1 + 4) % 4;//v����ע��Ҫ+4��
					break;
				case 'R':
					curdirection = (curdirection + 1) % 4;
					break;
				case 'F':
					x += goforward[curdirection][0];
					y += goforward[curdirection][1];
					break;
				}
				if (checkcrash(x, y) && flag == 1)
				{
					flag = 0;
					switch (checkcrash(x, y))
					{
					case 1:
						cout << "Robot " << Num << " crashes into the wall" << endl;
						break;
					case 2:
						cout << "Robot " << Num << " crashes into robot " << chess[x][y].Number << endl;
						break;
					}
				}
				else {
					chess[x][y].direction = curdirection;
					chess[x][y].Number = Num;
				}
			}

		}
		if (flag)
			cout << "OK" << endl;
	}

	return 0;

}