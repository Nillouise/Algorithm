#include<algorithm>
#include<iostream>
#include<string>
#include<stack>
#include<fstream>
#include<queue>
#include<vector>
using namespace std;
int N, M, S;
double V;
const int INF = 1000000;
const int maxn = 1000;//�������鿪С��
struct Edge
{
	int u, v;
	double com, rate;
	Edge(int u, int v, double com, double rate) :u(u), v(v), com(com), rate(rate) {}
};
vector<int> s[maxn];
double d[maxn];//�������ְ� doubleд��int������ע�����ĺ���
int vis[maxn];
vector<Edge> edges;

int Bellman()
{
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < maxn; i++)d[i] = 0.0;
	int cnt[maxn];
	//	memset(cnt, 0, sizeof(maxn)); //�Ҿ�Ȼ��maxn��ʼ������
	memset(cnt, 0, sizeof(cnt));
	queue<int> q;
	d[S] = V;
	q.push(S);
	while (!q.empty())
	{
		int node = q.front(); q.pop();
		vis[node] = 0;
		for (size_t i = 0; i < s[node].size(); i++)
		{
			int v = edges[s[node][i]].v;
			double com = edges[s[node][i]].com;//�����double �ִ�д��int����ȫû�п��Ǿ��Ǽ����ı���
			double rate = edges[s[node][i]].rate;

			if (d[v] < (d[node] - com)*rate)
			{
				d[v] = (d[node] - com)*rate;
				if (vis[v] == 0)
				{
					q.push(v);
					cnt[v]++;
					if (cnt[v] > N)
						q = queue<int>();
					vis[v] = 1;
				}
			}
		}
	}
	for (size_t i = 1; i <= N; i++)
	{
		if (cnt[i] > N)return 1;
	}
	return 0;


}
int main()
{
	freopen("input.txt", "r", stdin);
	while (cin >> N >> M >> S >> V)
	{
		edges.clear();
		for (size_t i = 0; i < maxn; i++)s[i].clear();
		for (size_t i = 0; i < M; i++)
		{
			int a, b;
			double Cab, Rab, Cba, Rba;
			cin >> a >> b >> Rab >> Cab >> Rba >> Cba;//�������ݵ� ���ʺ������ѵ�λ�ö�������

			Edge e1(a, b, Cab, Rab);
			Edge e2(b, a, Cba, Rba);
			edges.push_back(e1);
			s[a].push_back(edges.size() - 1);
			edges.push_back(e2);
			s[b].push_back(edges.size() - 1);

			//if (Bellman())
			//	cout << "YES" << endl;
			//else
			//	cout << "NO" << endl;�������Ȼ���������жϣ����붼û�����

		}
		if (Bellman())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}




	return 0;

}