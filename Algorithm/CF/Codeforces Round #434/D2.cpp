//未完成
#include<cmath>
#include <string>
#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

class Tree
{
public:
	Tree *z[10];
	long long cnt = 0;
	int pre = -1;
	Tree()
	{
		for (int i = 0; i < 10; i++)z[i] = nullptr;
	}
	int extent(string &s, int index)
	{
		if (s.length() == 0)return 0;
		if (s[0] - '0' == 9)
		{
			cout << 9;
		}
		if (z[s[0] - '0'] == nullptr)
		{
			z[s[0] - '0'] = new Tree();
		}
		if (index != pre)
		{
			cnt++;
			pre = index;
		}
		z[s[0] - '0']->extent(s.substr(1), index);
		return 0;
	}

	int search(string &s)
	{
		//if (cnt == 0)//这里没考虑到，字符串中途时，至起码是1,1就代表只有一条字符串了,0的话就表示结尾的字符串
		//上面的判断是错的，要是两个字符串完全相同，结尾的tree 的cnt也一样是0
		if (cnt <= 1)
		{
			return 1;
		}
		if (s.size() == 0)
		{
			return -1000000;
		}
		//return search(s.substr(1)) + 1;//这样只是在当前的节点搜，不符合在树上搜的本意
		return z[s[1] - '0']->search(s.substr(1)) + 1;
	}
};

//Tree trees[10];
//这种根节点用10个表示，应该是不好的


int showtree(int indent, Tree ct)
{
	for (int i = 0; i < 10; i++)
	{
		if (ct.z[i] != nullptr)
		{
			for (int j = 0; j < indent; j++)cout << " ";
			cout << i << "  " << ct.z[i]->cnt << endl;
			showtree(indent + 1, *ct.z[i]);
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	//trees[0].z[5] = new Tree();
	//Tree* tree = new Tree();
	//tree->z[0] = new Tree();

	int n;
	cin >> n;
	vector<string> v;
	for (int i = 0; i<n; i++)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}
	Tree root;
	for (int s = 0; s < v.size(); s++)
	{
		for (int i = 0; i < 10; i++)
		{
			//trees[v[s][i] - 'a'].extent(v[s].substr(i));//好笑，这里居然错了(-'a')，浪费我20分钟
			//trees[v[s][i] - '0'].extent(v[s].substr(i),s);
			//trees[v[s][i] - '0'].extent(v[s].substr(i + 1), s);
			root.extent(v[s], s);
		}
	}

	showtree(0, root);

	for (int s = 0; s < v.size(); s++)
	{
		int MIN = 1000;
		string MINS;
		//for (int b = 0; b < 10; b++)
		for (int b = 0; b < 9; b++)
		{
			string &cs = v[s].substr(b);
			//int len = trees[cs[0] - '0'].search(cs);
			int len = root.search(cs);
			if (len < 0)continue;
			if (len < MIN)
			{
				MINS = cs.substr(0, len);
				MIN = len;
			}
		}
		cout << MINS << endl;
	}



	return 0;
}