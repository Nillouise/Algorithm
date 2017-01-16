#include<iostream>
#include<vector>
#include<string>
using namespace std;
const int maxn = 100;
int lsubtree[maxn]; int rsubtree[maxn];
int nc = 0;//nodes count
char op[maxn];

int expression(string s,int begin, int end)
{
	if (begin == end) {
		nc++;
		lsubtree[nc] = rsubtree[nc] = 0;
		op[nc] = s[begin];
		return nc;//这里我原先写错了，写成return begin了，但其实要return nc，也就是返回当前节点的号码。
	}
	int c1 = -1;
	int c2 = -1;
	int bs = 0;//bracket state
	for (size_t i = begin; i <= end; i++)//这里是从begin 遍历到end，带来的后果是找到的是最右边的算符，所以整个表达式是左结合的。
	{
		switch (s[i]) {
		case '(':bs++;break;
		case ')':bs--;break;
		case '+':case '-':if (!bs)c1 = i;break;
		case '*':case '/':if (!bs)c2 = i;break;
		}
	}

	if (c1 == c2&&c1 == -1)//外面是括号的情况
	{
		return expression(s,begin + 1, end - 1);
	}

	int curC = c1 > -1 ? c1 : c2;
	nc++;
	int snap = nc;//这里的snap 表达了一个意思，就是 nc可能会在后续函数里改变，所以快照一下.
	lsubtree[snap] = expression(s,begin, curC - 1);
	rsubtree[snap] = expression(s,curC + 1, end);
	op[snap] = s[curC];
	return snap;
}


int main()
{
	string s = "4-(2*3+1)";
	expression(s,0, s.size() - 1);

	system("pause");
	return 0;
}
