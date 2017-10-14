//return (bit&(1 << pos))>0;这句写错了，写成(bit&(1 << pos)) == 1，殊不知这种位运算产生的根本不是1，而是真而已
#include<algorithm>
#include<iostream>
#include<string>
#include<stack>
#include<set>
#include<functional>
#include<queue>
using namespace std;
const int maxn = 1000;
const int maxCharacter = 26;

struct Trie
{
	int ch[maxn][maxCharacter];
	int val[maxn];//标记有没有字符串在这里终结
	int sz;
	int d[maxn];
	Trie() {
		sz = 1;//0点是根节点
		memset(val, 0, sizeof(val));
		memset(d, -1, sizeof(d));
		memset(ch, 0, sizeof(ch));
	}

	void insert(string s)
	{
		int node = 0;
		for (size_t i = 0; i < s.length(); i++)
		{
			if (ch[node][s[i] - 'a'] == 0)
			{
				ch[node][s[i] - 'a'] = sz++;

			}
			node = ch[node][s[i] - 'a'];
		}
		val[node] = 1;
	}
	string text;

	int search(int n)
	{
		if (n >= text.size())return 0;
		if (d[n] != -1)
			return d[n];


		int node = ch[0][text[n] - 'a'];
		int sum = 0;
		for (size_t i = n; i<text.size(); i++)
		{
			if (val[node] != 0)
			{
				sum += search(i + 1);
			}
			node = ch[node][text[i] - 'a'];
			if (node == 0)
				break;
		}
		d[n] = sum;
		return d[n];
	}

	int solve(string t)
	{
		text = t;
		return search(0);
	}

};


int main()
{
	freopen("input.txt", "r", stdin);



	return 0;
}