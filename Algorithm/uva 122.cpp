//这题注意用的是空格做两个节点的分隔符，可以靠这点读写
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

struct Token
{
	vector<char> v;
	int val;
};

struct Node
{
	Node* let = NULL;
	Node* rit = NULL;
	int val = -1;

	int extent(vector<char> v, int start, int nval)
	{
		if (start == v.size())
		{
			if (val == -1)
			{
				val = nval;
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			if (v[start] == 'L')
			{
				if (let == NULL)
				{
					let = new Node();
				}
				return let->extent(v, start + 1, nval);
			}
			else
			{
				if (rit == NULL)
				{
					rit = new Node();
				}
				return rit->extent(v, start + 1, nval);
			}
		}
	}

};

int main()
{
	freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(false);

	for (;;)
	{

		vector<Token> vn;
		for (;;)
		{
			string s;
			if (!(cin >> s))
				exit(0);
			//这里不及时跳出，下面的代码会出错
			if (s == "()")break;
			int val = stoi(s.substr(1, s.find(',', 1) - 1));
			vector<char> v;
			for (int i = s.find(',') + 1; i<s.size() - 1; i++)
			{
				v.push_back(s[i]);
			}
			vn.push_back({ v,val });
		}
		int flag = 1;
		Node head;
		for (auto a : vn)
		{
			if (head.extent(a.v, 0, a.val) == 0)flag = 0;
		}
		queue<Node> Q;
		Q.push(head);
		vector<int> vp;

		while (!Q.empty())
		{
			Node node = Q.front(); Q.pop();
			if (node.val == -1)
			{
				flag = 0;
				break;
			}
			vp.push_back(node.val);

			if (node.let != NULL)
			{
				Q.push(*node.let);
			}
			if (node.rit != NULL)
			{
				Q.push(*node.rit);
			}
		}

		if (flag)
		{
			for (int i = 0; i<vp.size(); i++)
			{
				cout << vp[i];
				//这里居然不能打印最后一个空格。好蠢
				if (i != vp.size() - 1)cout << " ";
			}
			cout << endl;
		}
		else
		{
			cout << "not complete" << endl;
		}
	}

	return 0;
}