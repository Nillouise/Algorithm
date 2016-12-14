#include "Chess.h"



Chess::Chess()
{
}


Chess::~Chess()
{
}
const int d[2][8] = { 1,2,2,1 ,-1,-2,-2,-1,2,1,-1,-2,-2,-1,1,2 };
int chess[5][6];
int count;
int sx, sy;
int Horse(int x, int y)
{
	sx = x;
	sy = y;
	return 0;
}

int dfs(int p1, int p2)
{
	int pi, pj;
	for (int i = 0; i<7; i++)
	{
		pi = p1 + d[0][i];
		pj = p2 + d[1][i];
		if (pi >= 0 && pi<6 && pj >= 0 && pj<5 && chess[pi][pj] == 0)
		{
			chess[pi][pj] = 1;
			dfs(pi, pj);
			chess[pi][pj] = 0;
		}
		else if (pi == sx&&pj == sy)
			count++;
	}

	return 0;
}

int Chess::run(int p1, int p2)
{
	Horse(p1, p2);
	dfs(p1, p2);

	return count;
}
