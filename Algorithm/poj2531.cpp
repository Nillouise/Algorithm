#include<algorithm>
#include<iostream>
#include<string>
#include<stack>
#include<set>
#include<functional>
#include<queue>
using namespace std;
int N;
int g[30][30];
//������Ǵ�ģ����ұ�ʾ���ϣ�Ҳ��Ҫ�� vector���ֱ��صĶ������᲻�ϸ���Ԫ��
int dfs(int calindex, vector<int> a1, vector<int> b2, int ans)
{
	int reans = ans;
	for (size_t k = calindex; k < a1.size(); k++)
	{
		vector<int> a(a1); vector<int> b(b2);
		int newans = 0;
		for (size_t i = calindex; i < a.size(); i++)
		{
			for (size_t j = 0; j < b.size(); j++)
			{
				//				if(i!=calindex)//�����������˱����ĺ��壬calindex�Ǿ�̬��������k���ǳ��Եġ����ϸı�ı���
				if (i != k)
					newans += g[a[i]][b[j]];
			}
		}
		for (size_t i = 0; i < a.size(); i++)
		{
			newans += g[a[k]][a[i]];//��Ϊi��i�ľ�����0,���Կ����������� a[k]
		}

		if (newans >= ans)
		{
			b.push_back(a[calindex]);
			a.erase(a.begin() + k);
			reans = max(max(dfs(k, a, b, newans), newans), reans);
		}
	}
	return reans;

}

int subset[25];
int n, G[25][25];
int ans;//�����ȫ�ֱ�������¼���Ĵ�
		//�������Ѳ���������Ԫ�ؼ���������ĳ������������ûʲô��ͬ��ֻ����Ҫ��¼�ѹ��Ǹ�λ�ã�ת����ʱ��Ҫ�õ���Щλ�ã�subset��
void dfs2(int id, int sum)
{
	int co = sum;
	subset[id] = 1;
	for (int i = 0; i < n; i++)
		if (subset[i])
			sum -= G[id][i];
		else
			sum += G[id][i];
	if (sum > ans)
		ans = sum;
	if (sum < co)return;//������Լ�֦����Ϊ�����idԪ���õ���һ�飬��С�Ͳ����������Ž�
	for (int i = id + 1; i < n; i++)
	{
		dfs2(i, sum);
		subset[i] = 0;
	}
}
int main()
{
	freopen("input.txt", "r", stdin);

	cin >> N;
	n == N;
	memset(g, 0, sizeof(N));
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			cin >> g[i][j];
			G[i][j] == g[i][j];
		}
	}
	vector<int> a;
	for (size_t i = 0; i < N; i++)
	{
		a.push_back(i);
	}
	cout << dfs(0, a, vector<int>(), 0) << endl;

	return 0;
}