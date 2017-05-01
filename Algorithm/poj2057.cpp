//ÿ���ڵ��Ҷ��������������ڵ���ӽڵ���Ŀ����û�и�����������
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N;
const int maxn = 1005;
vector<int> tree[maxn];
int worm[maxn];
int leaf[maxn];
double success[maxn];
double failure[maxn];
//comp�����ӽڵ㣬�Ϳ���ȷ���������ӽڵ�����˳���ˣ��������������ӽڵ���ʲô����û�й�ϵ)
bool comp(int a, int b)
{
	double afirst = 0;
	double bfirst = 0;
	double total = leaf[a] + leaf[b];
	//���Ǵ�ģ�Ҫ��a����û�н��������ܸ����Ͳ���Ҫ��success[a]��
	//֮ǰ����Ϊa�����ĳɹ��ڴ��������ܳ��Գɹ����ʣ���˼·������������û����ȫ����a�����ɹ�������Ϊ�ɹ��Ĳ���������һЩ��ʧ�������ʧ�ܵ�����
	//afirst +=1+ success[a] + leaf[b] / total*(failure[a] + 1 + 1 + success[b]);//ʧ��֮��ص�ԭ�� �ٵ�b̽����Ҫ+1+1;
	//bfirst +=1+ success[b] + leaf[a] / total*(failure[b] + 1 + 1 + success[a]);
	afirst += (leaf[a] / total)*(1 + success[a]) + leaf[b] / total*(failure[a] + 1 + 1 + 1 + success[b]);//ʧ��֮��ص�ԭ�� �ٵ�b̽����Ҫ+1+1;//����������
																										 //�ɹ���ʧ����������ȫ��ͬ��״̬����ȫ���Ը������߲�ͬ�Ĳ������Ը��Եĸ��ʣ�
																										 //����ʧ��������+1+1+1���� �� �ٽ���һ��
	bfirst += (leaf[b] / total)*(1 + success[b]) + leaf[a] / total*(failure[b] + 1 + 1 + 1 + success[a]);


	return afirst < bfirst;
}

double DP(int d, int state)
{
	if (state == 0)
	{
		if (worm[d] == 1)
			return failure[d] = 0;
		if (failure[d] >= 0)return failure[d];
		if (tree[d].size() == 0)return failure[d] = 0;
		double sum = 0;
		for (size_t i = 0; i < tree[d].size(); i++)
		{
			sum += DP(tree[d][i], 0) + 2;
		}
		return failure[d] = sum;
	}
	else {
		if (success[d] >= 0)return success[d];
		if (tree[d].size() == 0)return success[d] = 0;
		//		for (size_t i = 0; i < tree[i].size(); i++)
		for (size_t i = 0; i < tree[d].size(); i++)
		{
			DP(tree[d][i], 0);
			DP(tree[d][i], 1);
		}
		sort(tree[d].begin(), tree[d].end(), comp);
		//		double sum =  leaf[d]/total * (success[tree[d][0]]+1);
		//		double cur = total - leaf[tree[d][0]];
		//		for (size_t i = 1; i < tree[d].size(); i++)
		//		{
		//			int num = tree[d][i];
		//			int pre = tree[d][i - 1];
		////			sum += cur / total *(failure[pre]+1+1 + success[num]);
		//			
		//			cur -= leaf[num];
		//		}
		double sum = success[tree[d][tree[d].size() - 1]] + 1;
		double total = leaf[tree[d][tree[d].size() - 1]];

		//		for (int i = tree[d].size()-1-1; i >0;i--)
		for (int i = tree[d].size() - 1 - 1; i >= 0; i--)
		{
			int num = tree[d][i];
			double cur = total + leaf[num];
			sum = leaf[num] / cur*(success[num] + 1) + total / cur*(1 + failure[num] + 1 + sum);
			total = cur;
		}

		return success[d] = sum;
	}
}
//���ﲻ����ȷ����һ��Ҷ�����������ڵ��������
int dfs(int x)
{
	if (leaf[x] >= 0)return leaf[x];
	int sum = 0;
	for (size_t i = 0; i < tree[x].size(); i++)
	{
		sum += dfs(tree[x][i]);
	}
	return leaf[x] = (tree[x].size() == 0 ? 1 : sum);
}


double solve()
{
	fill(success, success + maxn, -1.0);
	fill(failure, failure + maxn, -1.0);
	memset(leaf, -1, sizeof(leaf));

	for (size_t i = 0; i < N; i++)
	{
		dfs(i);
	}

	return DP(0, 1);


}

int main()
{
	freopen("input.txt", "r", stdin);
	while (cin >> N&&N != 0)
	{
		memset(worm, 0, sizeof(worm));
		for (size_t i = 0; i < maxn; i++)
		{
			tree[i].clear();
		}
		for (size_t i = 0; i < N; i++)
		{
			int f;
			char w;
			cin >> f >> w;
			if (f != -1)
			{
				f--;
				tree[f].push_back(i);
			}
			worm[i] = (w == 'Y' ? 1 : 0);
		}
		printf("%0.4f\n", solve());
	}

}