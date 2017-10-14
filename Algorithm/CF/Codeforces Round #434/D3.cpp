//http://codeforces.com/contest/861/problem/D
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//复习一下怎么写字符树，当然这题并不用，因为一个电话号码最多只有50个组合，所以只要暴力就可以了
class TreeNode
{
public:
	int pathcnt = 0;
	TreeNode *next[10] = { nullptr };
	int pre = -1;
	int extent(string s, int index)
	{
		if (index != pre)pathcnt++, pre = index;
		if (s.size() == 0)return 0;
		int offset = s[0] - '0';
		if (next[offset] == nullptr)
		{
			next[offset] = new TreeNode();
		}
		//if (index != pre)pathcnt++, pre = index;//把pathcnt放这里应该不行，因为这个treenode是永远有意义的，代表某个数字或者代表root，
		//也就是从头到结尾，都是要加，这里不能放在size()检查后面
		next[offset]->extent(s.substr(1), index);
		return 0;
	}

	int find(string s)
	{
		if (pathcnt == 1)return 1;
		if (s.size() == 0)return -11111;
		int offset = s[0] - '0';

		return next[offset]->find(s.substr(1)) + 1;
	}

};
int showtree(int indent, TreeNode ct)
{
	for (int i = 0; i < 10; i++)
	{
		if (ct.next[i] != nullptr)
		{
			for (int j = 0; j < indent; j++)cout << " ";
			cout << i << "  " << ct.next[i]->pathcnt << endl;
			showtree(indent + 1, *ct.next[i]);
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
	if (n == 1) { cout << v[0][0] << endl; return 0; }
	//这里不能正确处理只有一条电话的情况

	TreeNode root;
	for (int s = 0; s < v.size(); s++)
	{
		for (int i = 0; i < 10; i++)
		{
			//trees[v[s][i] - 'a'].extent(v[s].substr(i));//好笑，这里居然错了(-'a')，浪费我20分钟
			//trees[v[s][i] - '0'].extent(v[s].substr(i),s);
			//trees[v[s][i] - '0'].extent(v[s].substr(i + 1), s);
			root.extent(v[s].substr(i), s);
		}
	}

	for (int s = 0; s < v.size(); s++)
	{
		int MIN = 1000;
		string MINS;
		//for (int b = 0; b < 10; b++)
		for (int b = 0; b < 9; b++)
		{
			const string &cs = v[s].substr(b);//这里要用const修饰，好像是因为不能用引用改内容
											  //int len = trees[cs[0] - '0'].search(cs);
			int len = root.find(cs) - 1;
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