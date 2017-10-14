#include <iostream>
#include <cstdio>
#include <cstring>
#include<string>
#include <algorithm>
#include<sstream>
#include<cmath>
#include<queue>
using namespace std;
const int maxn = 200;
const double INF = 1000000.0;
//#define DEBUG
char maze[16][11];
struct Point
{
	int x, y;
	Point(int x = 0, int y = 0) :x(x), y(y) {}
};

//好像是因为这个bfs太慢了
//int bfs(int x,int y,int fun)
//{

//	queue<Point> q;
//	q.push(Point(x, y));
//	vis[x][y] = 1;
//	int cnt = 1;
//	while (!q.empty())
//	{
//		Point p = q.front(); q.pop();
//		//原先这句话放错位置了，因为是用p生成其他的东西，也就说，这个p在这里没用了，应该在这里删除才对
//		//其实还是有用，因为我用maze判断颜色是否相同
//		//if (fun == 1)
//		//{
//		//	maze[p.x][p.y] = 0;
//		//}
//		int direct[4][2]={ {0,1},{1,0},{-1,0},{0,-1} };
//		for (size_t i = 0; i < 4; i++)
//		{
//			Point newP( p.x + direct[i][0],p.y + direct[i][1] );
//			if (newP.x >= 0 && newP.x < 15 && newP.y >= 0 && newP.y < 10)
//			{
//				if (!vis[newP.x][newP.y]&&maze[newP.x][newP.y]==maze[x][y])
//				{
//					q.push(newP);
//					vis[newP.x][newP.y] = 1;
//					cnt++;
//				}
//			}
//		}
//	}
//	if (fun == 1)
//	{
//		for (size_t i = 0; i < 15; i++)
//		{
//			for (size_t j = 0; j < 10; j++)
//			{
//				maze[i][j] = vis[i][j] == 1 ? 0 : maze[i][j];
//			}
//		}
//	}
//
//	return cnt;
//}
//
int vis[16][11];
int direct[4][2] = { { 0,1 },{ 1,0 },{ -1,0 },{ 0,-1 } };
int bfscnt = 0;
int bfs(int x, int y, int fun)
{
	vis[x][y] = 1;
	char color = maze[x][y];
	bfscnt++;
	for (size_t i = 0; i < 4; i++)
	{
		int nx = x + direct[i][0];
		int ny = y + direct[i][1];
		if (nx >= 0 && nx < 15 && ny >= 0 && ny < 10)
			if (vis[nx][ny] == 0)
				if (maze[nx][ny] == color)
					bfs(nx, ny, fun);
	}
	if (fun == 1)
		maze[x][y] = 0;
	return 0;
}

int searchArea(int &lx, int &ly, char &color)//左下角的坐标，返回数目
{
	int preCo = 0;
	int MAX = 0;
	int MAXx = 0;
	int MAXy = 0;
	char MAXco = 0;
	memset(vis, 0, sizeof(vis));

	for (int i = 0; i < 15; i++)
	{
		preCo = 0;//因为每列的开头和尾端根本没有关系的
		for (int j = 9; j >= 0; j--)
		{
			//			if (maze[i][j] != preCo&&maze[i][j] != 0)
			//			if (maze[i][j] != 0)
			if (maze[i][j] != 0 && vis[i][j] == 0)
			{
				bfscnt = 0;
				bfs(i, j, 0);
				int cnt = bfscnt;
				preCo = maze[i][j];
				if (cnt > MAX)
				{
					MAX = cnt;
					MAXx = i;
					MAXy = j;
					MAXco = maze[i][j];
				}
				else if (cnt == MAX && ((i<MAXx) || (i == MAXx&&j>MAXy)))
				{
					MAX = cnt;
					MAXx = i;
					MAXy = j;
					MAXco = maze[i][j];
				}
			}
		}
	}
	lx = MAXx;
	ly = MAXy;
	color = MAXco;
	return MAX;

}


int delArea(int x, int y)
{
	return bfs(x, y, 1);
}

int refresh()
{
#ifdef DEBUG
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 15; j++)
		{
			cout << maze[j][i];
		}
		cout << endl;
	}
	cout << endl;
#endif // DEBUG


	for (int i = 0; i < 15; i++)
	{
		//		for (int j = 1; j < 10 ; j--)//改完代码起码要看看同一行是怎么回事
		//这代码并不正确，不能使这东西沉下去，因为当有连续两行0的时候，就不行了
		//for (int j = 9; j >0; j--)
		//{
		//	if (maze[i][j] == 0)
		//	{
		//		if (maze[i][j - 1] != 0)
		//		{
		//			maze[i][j] = maze[i][j - 1];
		//			maze[i][j - 1] = 0;
		//		}
		//	}
		//}
		for (int j = 9; j >0; j--)
		{
			if (maze[i][j] != 0)continue;//忘记写这句了，只要当前是空格子时，才会需要沉降
			int k;
			for (k = j; k >= 0; k--)//找最贴近的不是0的格子
			{
				if (maze[i][k] != 0)break;
			}
			if (k != -1)
			{
				maze[i][j] = maze[i][k];
				maze[i][k] = 0;
			}
		}
	}
#ifdef DEBUG
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 15; j++)
		{
			cout << maze[j][i];
		}
		cout << endl;
	}
	cout << endl;
#endif // DEBUG
	for (int i = 0; i < 15; i++)
	{
		int flag = 1;
		for (int j = 0; j < 10; j++)
		{
			if (maze[i][j] != 0) { flag = 0; break; }
		}
		if (flag == 1)
		{
			int next;
			//			for ( next = i+1; next < 15; next++)
			//next这个变量不应该在这里++，
			//因为next下面会用到，而且还会在另一个范围内用到
			int ok = 0;
			for (next = i + 1; next<15;)
			{

				for (int j = 0; j < 10; j++)
				{
					if (maze[next][j] != 0)
					{
						ok = 1;
						break;
					}
				}
				if (ok)break;
				next++;
			}
			if (ok)
			{
				//				for (int  j = 0; j < 15; j++)//写错变量
				for (int j = 0; j<10; j++)
				{
					maze[i][j] = maze[next][j];
					maze[next][j] = 0;
				}
			}

		}
		//for (int k = i; k < 14; k++)//最后一列空行不用移动
		//{
		//	for (int j = 0; j < 10; j++)//这是错的，会改变顺序位置，要那一整列拿过来，就那么一列
		//	{
		//		maze[k][j] = maze[k + 1][j];
		//		maze[k + 1][j] = 0;
		//	}
		//}
	}

#ifdef DEBUG
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 15; j++)
		{
			cout << maze[j][i];
		}
		cout << endl;
	}
	cout << endl;
#endif // DEBUG

	return 0;
}


int main()
{
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	char c;
	//	scanf("%c", &c);
	for (size_t t = 1; t <= T; t++)
	{
		cout << "Game " << t << ":" << endl << endl;
		memset(maze, 0, sizeof(maze));
		//for (size_t i = 0; i < 15; i++)
		//{
		//	for (size_t j = 0; j < 10; j++)
		//没有思考 x代表什么，y代表什么
		for (size_t j = 0; j < 10; j++)
		{
			for (size_t i = 0; i < 15; i++)
			{
				cin >> maze[i][j];//要关闭加速才行//关闭了加速还是不行
								  //				scanf("%c", &maze[i][j]);//这样会吸入\n
			}
			//			scanf("%c", &c);//吸入\n
		}
		//		scanf("%c", &c);
		int score = 0, leftover = 10 * 15;
		for (int step = 1;; step++)
		{
			int x, y;
			char color;
			int curNum = searchArea(x, y, color);

			if (curNum < 2)
			{
				if (leftover == 0)score += 1000;
				printf("Final score: %d, with %d balls remaining. \n\n", score, leftover);
				break;
			}
			else {
				leftover -= curNum;
				score += (curNum - 2)*(curNum - 2);
				printf("Move %d at(%d, %d) : removed %d balls of color %c, got %d points.\n", step, 10 - y, x + 1, curNum, color, (curNum - 2)*(curNum - 2));
			}
			delArea(x, y);
			refresh();
		}
	}

	return 0;
}