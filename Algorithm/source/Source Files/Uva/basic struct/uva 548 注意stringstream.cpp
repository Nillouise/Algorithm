//����ע���õ��ǿո��������ڵ�ķָ��������Կ�����д
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

vector<int> post;//�������
vector<int> mids;//�������

int let[10000 + 5];
int rit[10000 + 5];

//������L1,R1,L2,R2�����Ӧ�ñȽϺ���
//��������� �����������һλ��һλ���±�����β�������ý�β��һλ���±꣬�о�������������
int build(int bp, int ep, int bm, int em)
{
	//�������ڼ���ִ���
	//	int root =  post[ep - 1];
	//	if (ep-bp == 1)return root;
	//	if (ep - bp == 0) return -1;
	if (ep - bp == 0)return -1;
	int root = post[ep - 1];
	if (ep - bp == 1)return root;//�����Ǳ�Ҫ�ģ���Ϊ���Ѿ��������
	//���������ǲ���Ҫ�ģ���ֻ�Ǳ�ĵط����˲ž����ⶫ����Ҫ

								 //	int pos = lower_bound(&mids[bm], &mids[em], root) - &mids[bm];//����ô���em��Ϊ�Ǳ������Ԫ�صĺ�һλ���ᵼ��outofbound��
								 //	int pos = lower_bound(&mids + bm, &mids+em, root) - &mids - bm;//��vector���а���������ǲ���ô������lower_bound
	int pos = bm;
	while (mids[pos] != root)pos++;
	pos = pos - bm;

	//�����pos ��һ��ʼ�ı�ʾ���������������λ��
	let[root] = build(bp, bp + pos, bm, bm + pos);
	rit[root] = build(bp + pos, ep - 1, bm + pos + 1, em);//-1��+1��������

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
		//	ss << s;//�����stringstream��������ȷ�����У����µ�һ���ǻ��з�
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
		dfs(post.back(), 0);//������0����Ϊ������ڵ�ĸ�·���ĺ�
		cout << MINX << endl;
	}




	return 0;
}