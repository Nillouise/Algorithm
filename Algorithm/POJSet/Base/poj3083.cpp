//这题最后也是wa，但讨论版发的测试数据都过了，不管了
//当然，这题我的代码写得相当烂，说不定参考一下别人怎么写得比较好
//wa 的原因应该是我的空格打成是中文的空格了
#include<algorithm>
#include<iostream>
#include<string>
#include<stack>
#include<set>
#include<functional>
#include<queue>
using namespace std;

char maze[50][50];
int vis[50][50];
int w, h;

int direct[4][2] =
{ { -1,0 },
{ 0,1 },
{ 1,0 },
{ 0,-1 }
};

struct human
{
	int x, y;
	int direction;
	human(int x = 0, int y = 0, int direction = 0) :x(x), y(y), direction(direction) {}
};

int searchleft(human start)
{
	memset(vis, 0, sizeof(vis));
	int cnt = 1;//因为从起点开始就是1，算路径的
	human hu = start;
	for (;;)
	{
		int newdirect = (hu.direction + 4 - 1) % 4;//记得要+4避免负数
		int leftx = hu.x + direct[newdirect][0];
		int lefty = hu.y + direct[newdirect][1];
		//		if (maze[leftx][lefty] != '#'&&leftx<h&&leftx>=0&&lefty<w&&lefty>=0)
		if (maze[leftx][lefty] != '#')
		{
			cnt++;
			if (maze[leftx][lefty] == 'E')return cnt;

			hu.x = leftx;
			hu.y = lefty;
			hu.direction = newdirect;
		}
		else {
			int upx = hu.x + direct[hu.direction][0];
			int upy = hu.y + direct[hu.direction][1];
			if (maze[upx][upy] == '#')
			{
				//				hu.direction = (hu.direction - 1 + 4) % 4;//向左向上都不行时，就要向右
				hu.direction = (hu.direction + 1 + 4) % 4;
				//				break;//这里是continue，进入下一个循环
				continue;
			}
			cnt++;
			if (maze[upx][upy] == 'E')return cnt;
			hu.x = upx;
			hu.y = upy;

		}
	}
}

int searchright(human start)
{
	memset(vis, 0, sizeof(vis));
	int cnt = 1;//因为从起点开始就是1，算路径的
	human hu = start;
	for (;;)
	{
		int newdirect = (hu.direction + 4 + 1) % 4;//记得要+4避免负数
		int leftx = hu.x + direct[newdirect][0];
		int lefty = hu.y + direct[newdirect][1];
		//		if (maze[leftx][lefty] != '#'&&leftx<h&&leftx>=0&&lefty<w&&lefty>=0)
		if (maze[leftx][lefty] != '#')
		{
			cnt++;
			if (maze[leftx][lefty] == 'E')return cnt;

			hu.x = leftx;
			hu.y = lefty;
			hu.direction = newdirect;
		}
		else {
			int upx = hu.x + direct[hu.direction][0];
			int upy = hu.y + direct[hu.direction][1];
			if (maze[upx][upy] == '#')
			{
				hu.direction = (hu.direction - 1 + 4) % 4;
				//				break;//这里是continue，进入下一个循环
				continue;
			}
			cnt++;
			if (maze[upx][upy] == 'E')return cnt;
			hu.x = upx;
			hu.y = upy;

		}
	}
}

int searchshort(human start)
{
	memset(vis, -1, sizeof(vis));

	queue<human> q;
	q.push(start);
	vis[start.x][start.y] = 1;
	while (!q.empty())
	{
		human hu = q.front(); q.pop();
		if (maze[hu.x][hu.y] == 'E')return vis[hu.x][hu.y];
		human h1(hu.x + direct[0][0], hu.y + direct[0][1]);

		//下面这里写错了，应该用一个循环代替
		if (h1.x >= 0 && h1.x < h&&h1.y >= 0 && h1.y < w&&vis[h1.x][h1.y] == -1 && maze[h1.x][h1.y] != '#')
		{
			q.push(h1);
			vis[h1.x][h1.y] = vis[hu.x][hu.y] + 1;
		}
		h1.x = hu.x + direct[1][0]; h1.y = hu.y + direct[1][1];
		if (h1.x >= 0 && h1.x < h&&h1.y >= 0 && h1.y < w&&vis[h1.x][h1.y] == -1 && maze[h1.x][h1.y] != '#')
		{
			q.push(h1);
			vis[h1.x][h1.y] = vis[hu.x][hu.y] + 1;
		}
		h1.x = hu.x + direct[2][0]; h1.y = hu.y + direct[2][1];
		if (h1.x >= 0 && h1.x < h&&h1.y >= 0 && h1.y < w&&vis[h1.x][h1.y] == -1 && maze[h1.x][h1.y] != '#')
		{
			q.push(h1);
			vis[h1.x][h1.y] = vis[hu.x][hu.y] + 1;
		}
		h1.x = hu.x + direct[3][0]; h1.y = hu.y + direct[3][1];
		if (h1.x >= 0 && h1.x < h&&h1.y >= 0 && h1.y < w&&vis[h1.x][h1.y] == -1 && maze[h1.x][h1.y] != '#')
		{
			q.push(h1);
			vis[h1.x][h1.y] = vis[hu.x][hu.y] + 1;
		}
	}
	return 2;
}

int main()
{
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;
	while (T--)
	{
		cin >> w >> h;
		human start;
		for (size_t i = 0; i < h; i++)
		{
			for (size_t j = 0; j < w; j++)
			{
				cin >> maze[i][j];
				if (maze[i][j] == 'S')
				{
					start.x = i;
					start.y = j;
					if (i == 0)start.direction = 2;
					if (i == h - 1)start.direction = 0;
					if (j == 0)start.direction = 1;
					if (j == w - 1)start.direction = 3;
				}
			}
		}
		cout << searchleft(start) << " " << searchright(start) << " " << searchshort(start) << endl;
	}


	return 0;
}