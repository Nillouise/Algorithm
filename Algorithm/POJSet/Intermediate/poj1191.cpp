#include<iostream>
#include<algorithm>
using namespace std;
double INF = 100000;
double chess[8][8];
double dp[8][8][8][8];
int n;
double ave;
double dfs(int x1, int y1, int x2, int y2, int sects)
{
	if (dp[x1][y1][x2][y2] != INF)
	{
		return dp[x1][y1][x2][y2];
	}
	double MIN = INF;
	for (int x = x1; x < x2; x++)
	{
		double cur = 0;
		for (int j = y1; j <= y2; j++)
		{
			for (int i = x1; i <= x; i++)
			{
				cur += pow((chess[i][j] - ave), 2);
			}
		}
		MIN = min(MIN, dfs(x + 1, y1, x2, y2, sects - 1) + cur);


		cur = 0;
		for (int j = y1; j <= y2; j++)
		{
			for (int i = x + 1; i <= x2; i++)
			{
				cur += pow((chess[i][j] - ave), 2);
			}
		}
		MIN = min(MIN, dfs(x1, y1, x, y2, sects - 1) + cur);
	}
	for (int y = y1; y < y2; y++)
	{

	}
}
int main()
{
	while (cin >> n&&n != 0)
	{
		double sum = 0;
		for (size_t i = 0; i < 8; i++)
		{
			for (size_t j = 0; j < 8; j++)
			{
				cin >> chess[i][j];
				sum += chess[i][j];
			}
		}

		ave = sum / 64;



	}



	cout << "fdsfds";
}