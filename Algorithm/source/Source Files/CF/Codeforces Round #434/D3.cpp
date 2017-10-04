//http://codeforces.com/contest/861/problem/D
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//��ϰһ����ôд�ַ�������Ȼ���Ⲣ���ã���Ϊһ���绰�������ֻ��50����ϣ�����ֻҪ�����Ϳ�����
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
		//if (index != pre)pathcnt++, pre = index;//��pathcnt������Ӧ�ò��У���Ϊ���treenode����Զ������ģ�����ĳ�����ֻ��ߴ���root��
		//Ҳ���Ǵ�ͷ����β������Ҫ�ӣ����ﲻ�ܷ���size()������
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
	//���ﲻ����ȷ����ֻ��һ���绰�����

	TreeNode root;
	for (int s = 0; s < v.size(); s++)
	{
		for (int i = 0; i < 10; i++)
		{
			//trees[v[s][i] - 'a'].extent(v[s].substr(i));//��Ц�������Ȼ����(-'a')���˷���20����
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
			const string &cs = v[s].substr(b);//����Ҫ��const���Σ���������Ϊ���������ø�����
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