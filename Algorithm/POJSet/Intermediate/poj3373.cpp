//为什么需要这个数组呢？因为前50个数改变某些数字后，可能会产生一样的余数，一样的余数要在后50个数里改变，需要多少个数字自然是一定的。
//讲模的东西基本都会碰上这点。
#include <iostream>
#include <cstdio>
#include <cstring>
#include<string>
#include <algorithm>
#include<sstream>
#include<cmath>
using namespace std;
string n;
int k;
string ouput;
int mode[10][100 + 5];

int init()
{
	for (size_t i = 0; i < 10; i++)
	{
		mode[i][0] = i % k;
	}
	for (size_t j = 1; j < 100 + 5; j++)
	{
		for (size_t i = 0; i < 10; i++)
		{
			mode[i][j] = (mode[i][j - 1] * (10 % k)) % k;
		}
	}
	return 0;
}
int vis[100 + 5][10000 + 5];

//为什么需要这个数组呢？因为前50个数改变某些数字后，可能会产生一样的余数，一样的余数要在后50个数里改变，需要多少个数字自然是一定的。
int dfs(int pos, int remainder, int chn)
{
	//这两句的顺序不能错，因为检查都最后一个数字后，是在-1的位置检查remainder的
	if (remainder == 0)
		return 1;
	//	if (pos <0)//这里错了一次，pos是递增的
	if (pos >= n.length())
		return 0;
	if (chn <= 0)
		return 0;
	if (vis[pos][remainder] >= chn)
	{
		return 0;
	}
	for (int i = 0; i < 10; i++)
	{
		if (pos == 0 && i == 0 && n.length()>1)continue;//排除前导0的情况，但只有一个0时，又启用
		int c = n[pos] - '0';
		ouput[pos] = '0' + i;//这里改了却忘记失败是要恢复的，这种暂存全局变量的手尾比较长，要记住
		if (c > i)
		{
			int nr = (remainder - mode[c - i][n.length() - pos - 1]) % k;//这里是一个要点，余数 是+还是减，会根据改成大数还是小数决定

			if (dfs(pos + 1, nr, chn - 1))
				return 1;
		}
		else if (c < i)
		{
			int nr = (remainder + mode[i - c][n.length() - pos - 1]) % k;
			if (dfs(pos + 1, nr, chn - 1))
				return 1;
		}
		else
		{
			if (dfs(pos + 1, remainder, chn))
				return 1;
		}
	}

	vis[pos][remainder] = chn;
	ouput[pos] = n[pos];
	return 0;
}



int main() {
	//	freopen("input.txt", "r", stdin);


	while (cin >> n >> k)
	{
		ouput = n;
		int remainder = 0;
		memset(vis, 0, sizeof(vis));
		init();
		for (size_t i = 0; i < n.length(); i++)
		{
			remainder = (remainder + (mode[n[i] - '0'][n.length() - i - 1])) % k;
		}
		for (size_t i = 0; i < 6; i++)
		{
			if (dfs(0, remainder, i))
			{
				cout << ouput << endl;
				break;
			}
		}
	}
	return 0;
}