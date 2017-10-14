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
#include <sstream>
#include <bitset>
using namespace std;
typedef long long LL;

vector<int> post;//后序遍历
vector<int> mids;//中序遍历

int let[10000 + 5];
int rit[10000 + 5];

//这里用L1,R1,L2,R2做标记应该比较合适
//这里的书上 ，不是用最后一位后一位的下标做结尾，而是用结尾哪一位的下标，感觉比我这样做好
int build(int bp, int ep, int bm, int em)
{
	//这里的入口检查又错了
	//	int root =  post[ep - 1];
	//	if (ep-bp == 1)return root;
	//	if (ep - bp == 0) return -1;
	if (ep - bp == 0)return -1;
	int root = post[ep - 1];
	if (ep - bp == 1)return root;//这里是必要的，因为这已经代表空了
	//上面这行是不必要的，我只是别的地方错了才觉得这东方必要

								 //	int pos = lower_bound(&mids[bm], &mids[em], root) - &mids[bm];//这里好蠢，em因为是标记最后的元素的后一位，会导致outofbound的
								 //	int pos = lower_bound(&mids + bm, &mids+em, root) - &mids - bm;//在vector的中半段找数还是不怎么合适用lower_bound
	int pos = bm;
	while (mids[pos] != root)pos++;
	pos = pos - bm;

	//这里的pos 由一开始的表示个数，变成真正的位置
	let[root] = build(bp, bp + pos, bm, bm + pos);
	rit[root] = build(bp + pos, ep - 1, bm + pos + 1, em);//-1，+1跳过树根

														  //	let[root] = build(bp, pos, bm, bm + pos - bp);
														  //	rit[root] = build(pos, ep - 1, bm + pos - bp+1, em);
	return root;
}
LL MIN = 1e20;
LL MINX = 1e20;

int dfs(int x, LL total)
{
	total += x;
	if (let[x] == -1 && rit[x] == -1)
	{
		if (MIN>total)
		{
			MIN = total;
			MINX = x;
		}
		else if (MIN == total&&MINX > x)
			MINX = x;
		return 0;
	}
	if (let[x] != -1)dfs(let[x], total);
	if (rit[x] != -1)dfs(rit[x], total);
	return 0;
}


int main()
{
	freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(false);

	string s;
	while (getline(cin, s))
	{
		mids.clear();
		post.clear();
		MIN = 1e20;
		MINX = 1e20;
		stringstream ss;

		ss << s;
		int a;
		while (ss >> a)
		{
			mids.push_back(a);
		}
		getline(cin, s);
		//	char c;
		//	ss >> c;
		//	ss << s;//这里的stringstream好像不能正确处理换行，导致第一个是换行符
		stringstream ss2;
		ss2 << s;
		while (ss2 >> a)
		{
			post.push_back(a);
		}
		memset(let, -1, sizeof(let));
		memset(rit, -1, sizeof(rit));
		build(0, post.size(), 0, mids.size());
		//	dfs(post.back(), post.back());
		dfs(post.back(), 0);//这里是0，因为是这个节点的父路径的和
		cout << MINX << endl;
	}




	return 0;
}