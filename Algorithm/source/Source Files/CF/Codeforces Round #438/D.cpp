//����õ��͵��ַ���ģ��ѽ������10��Σ�����debug�������������Ŀ�Ĺ���
#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include <ctime>
#include <bitset>
using namespace std;
typedef long long LL;
const int MAXK = 13;
struct Token
{
	int len;
	string pre;
	string suf;
	bitset<(1 << (MAXK + 2))> vis;
};
int span[MAXK + 1];

int main()
{
	//		freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);

	span[1] = 1;
	for (int i = 2; i <= MAXK; i++)
	{
		span[i] = (1 << (i - 1)) + span[i - 1];
	}

	int n;
	cin >> n;
	vector<Token> v;
	for (int t = 0; t<n; t++)
	{
		string str;
		cin >> str;
		Token node;
		for (int i = 0; i<str.size(); i++)
		{
			int mask = 0;
			for (int j = i; j < str.size() && j - i + 1 <= MAXK; j++)
			{
				mask = (mask << 1) | (str[j] - '0');
				node.vis.set(span[j - i + 1] + mask);
			}
		}
		if (str.size()>MAXK)
		{
			//			node.pre = str.substr(MAXK);//������ȫ������substr���÷���java���е㲻һ��
			node.pre = str.substr(0, MAXK);
			node.suf = str.substr(str.size() - MAXK, MAXK);
		}
		else
		{
			node.pre = node.suf = str;
		}
		v.push_back(node);
	}

	int m;
	cin >> m;
	for (int t = 0; t<m; t++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		string str = v[a].suf + v[b].pre;

		Token node;
		//һ��ʼ��Ȼ�����д��䣬����Ҫ��ȡ�������־��ڲ��ֶε���ϣ�����ͷβ��ϵ��ڲ��ַ��������ܻ����Щ�ڲ����
		node.vis = v[a].vis | v[b].vis;
		for (int i = 0; i<str.size(); i++)
		{
			int mask = 0;
			for (int j = i; j < str.size() && j - i + 1 <= MAXK; j++)
			{
				mask = (mask << 1) | (str[j] - '0');
				node.vis.set(span[j - i + 1] + mask);
			}
		}

		//�������ص�,ƴ�Ӷ���
		if (v[a].pre.size()<MAXK)
		{
			node.pre = str.substr(0, MAXK);
		}
		else
		{
			node.pre = v[a].pre;
		}

		if (v[b].suf.size()<MAXK)
		{
			//���������max
			node.suf = str.substr(max(0, (int)str.size() - MAXK), MAXK);
		}
		else
		{
			node.suf = v[b].suf;
		}


		//		node.pre = v[a].pre;
		//		node.suf = v[b].suf;
		//������Υ���߼��Ĵ���
		//		if (str.size()>MAXK)
		//		{
		//			//������Υ���߼��Ĵ���
		////			node.pre = str.substr(0, MAXK);
		////			node.suf = str.substr(str.size() - MAXK, MAXK);
		//		}
		//		else
		//		{
		//			node.pre = node.suf = str;
		//		}
		//		//ԭ���Ұ��������������ǻ����ԭ���Ľ��ѽ
		//		node.vis = v[a].vis | v[b].vis;
		v.push_back(node);
		int res = 0;
		for (int i = 1; i <= MAXK; i++)
		{
			int flag = 0;
			for (int j = 0; j<(1 << i); j++)
			{
				//				flag+= node.vis[ span[i] + j];
				flag += !node.vis[span[i] + j];
			}

			if (!flag)res = i;
		}
		cout << res << endl;
	}





	return 0;
}