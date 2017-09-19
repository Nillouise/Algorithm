//Ϊʲô��Ҫ��������أ���Ϊǰ50�����ı�ĳЩ���ֺ󣬿��ܻ����һ����������һ��������Ҫ�ں�50������ı䣬��Ҫ���ٸ�������Ȼ��һ���ġ�
//��ģ�Ķ�����������������㡣
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

//Ϊʲô��Ҫ��������أ���Ϊǰ50�����ı�ĳЩ���ֺ󣬿��ܻ����һ����������һ��������Ҫ�ں�50������ı䣬��Ҫ���ٸ�������Ȼ��һ���ġ�
int dfs(int pos, int remainder, int chn)
{
	//�������˳���ܴ���Ϊ��鶼���һ�����ֺ�����-1��λ�ü��remainder��
	if (remainder == 0)
		return 1;
	//	if (pos <0)//�������һ�Σ�pos�ǵ�����
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
		if (pos == 0 && i == 0 && n.length()>1)continue;//�ų�ǰ��0���������ֻ��һ��0ʱ��������
		int c = n[pos] - '0';
		ouput[pos] = '0' + i;//�������ȴ����ʧ����Ҫ�ָ��ģ������ݴ�ȫ�ֱ�������β�Ƚϳ���Ҫ��ס
		if (c > i)
		{
			int nr = (remainder - mode[c - i][n.length() - pos - 1]) % k;//������һ��Ҫ�㣬���� ��+���Ǽ�������ݸĳɴ�������С������

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