#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<stack>
#include<set>
#include<functional>
#include<queue>
using namespace std;
const int maxn = 30;
const int INF = 10000000;
int w, h;
int maze[maxn][maxn];
int mincnt = INF;
int road[4][2] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };
int dfs(int x, int y, int step)
{
	if (step >= 10)return 0;
	if (step >= mincnt)return 0;//不加这句剪枝，似乎会超时tl
	int maze2[maxn][maxn]; //栈溢出了，函数内不能开这么大的数组（350*350）是不行的

	memcpy(maze2, maze, sizeof(maze));
	for (size_t dire = 0; dire < 4; dire++)
	{
		int immedita = 0;
		memcpy(maze, maze2, sizeof(maze));
		int xi = x, yi = y;
		for (;;)
		{
			if (xi >= h || xi < 0 || yi >= w || yi < 0)
				break;
			if (maze[xi][yi] == 3)
			{
				mincnt = min(step + 1, mincnt);
				return 0;
			}
			else if (maze[xi][yi] == 1)
			{
				if (immedita == 1)
					break;
				maze[xi][yi] = 0;
				xi -= road[dire][0];
				yi -= road[dire][1];
				dfs(xi, yi, step + 1);
				break;
			}
			xi += road[dire][0];
			yi += road[dire][1];
			immedita++;
		}

	}
	memcpy(maze, maze2, sizeof(maze));
	return 0;
}


int main()
{
	freopen("input.txt", "r", stdin);
	while (cin >> w >> h&&w != 0 && h != 0)
	{
		mincnt = INF;
		memset(maze, 0, sizeof(maze));
		int sx, sy, gx, gy;
		for (size_t i = 0; i < h; i++)
		{
			for (size_t j = 0; j < w; j++)
			{
				cin >> maze[i][j];
				if (maze[i][j] == 2) {
					sx = i; sy = j;
					maze[i][j] = 0;
				}
			}
		}
		//		dfs(4, 3, 0);
		dfs(sx, sy, 0);
		if (mincnt == INF)cout << -1 << endl;
		else cout << mincnt << endl;

	}

	return 0;
}