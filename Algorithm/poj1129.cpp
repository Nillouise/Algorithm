//���⻹�õ�����ɫ����
// Also, since the repeaters lie in a plane, the graph formed by connecting adjacent repeaters does not have any line segments that cross. 
//��仰��˵��ƽ��ͼ�ı߶����ཻ������˵������4ɫ�����ǰ�ᣬ���ԣ����ֻ��Ҫ4����ɫ
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<stack>
#include<set>
#include<functional>
#include<map>
#include<queue>
using namespace std;
const int maxn = 10000 + 10;
const int INF = 10000000;
int node[27];
int G[27][27];
int N;
int main()
{
	freopen("input.txt", "r", stdin);

	while (cin >> N&&N != 0)
	{
		memset(node, -1, sizeof(node));
		memset(G, 0, sizeof(G));
		for (size_t g = 0; g < N; g++)
		{
			string s;
			cin >> s;
			for (int i = 2; i < s.size(); i++)
			{
				G[s[0] - 'A'][s[i] - 'A'] = 1;
			}
		}
		int maxcolor = 0;
		for (size_t i = 0; i < N; i++)
		{
			int color[27] = { 0 };
			for (size_t j = 0; j < N; j++)
			{
				if (G[i][j] == 1)
				{
					if (node[j] != -1)
						color[node[j]] = 1;
				}
			}
			for (int j = 0; j < N; j++)
			{
				if (color[j] == 0)
				{
					node[i] = j;
					maxcolor = max(j, maxcolor);
					//������Լ���һ��4ɫ�����֦��һ��maxcolor ==3���ʹ����Ѿ���4����ɫ�ˣ���������������ü�������
					break;
				}
			}

		}
		maxcolor++;
		if (maxcolor == 1)
		{
			cout << "1 channel needed." << endl;
		}
		else {
			cout << maxcolor << " channels needed." << endl;
		}
	}



	return 0;
}