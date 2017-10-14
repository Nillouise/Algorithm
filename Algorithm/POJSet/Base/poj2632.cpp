//对于求余数处理是否注意出现负数的情况；这点没有考虑
//坐标系变化不是很熟悉，变换错了一次
//getPos函数没有考虑好边界，这题是从1开始编号的
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
		return 1;//走出了范围
	if (chess[x][y].Number != -1)
		return 2;//撞了别的机器
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
					curdirection = (curdirection - 1 + 4) % 4;//v这里注意要+4；
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
					flag = 0;//设0后就不再会计算了
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