#include "Chess.h"
#include<iostream>


const int d[2][8] = { {1,2,2,1 ,-1,-2,-2,-1}
					,{2,1,-1,-2,-2,-1,1,2 } };
int chess[5][6];
int count;
int sx, sy;
int Horse(int x, int y)
{
	sx = x;
	sy = y;
	chess[y][x] = 1;
	return 0;
}

int dfs(int px, int py)
{
	int cx, cy;
	for (int i = 0; i < 8; i++)
	{
		cx = px + d[0][i];
		cy = py + d[1][i];
		if (cx == sx&&cy == sy)
			count++;
		else
		if (cx >= 1 && cx < 6 && cy >= 1 && cy < 5 && chess[cy][cx] == 0)
		{
			chess[cy][cx] = 1;
			dfs(cx, cy);
			chess[cy][cx] = 0;
		}
		//else if (cx == sx&&cy == sy)
		//	count++;
	}

	return 0;
}

int Chess::run()
{

	int mx, my;//coordinate of the horse
	std::cin >> mx >> my;
	Horse(mx, my);
	dfs(mx, my);
	std::cout << count;

	return count;
}
