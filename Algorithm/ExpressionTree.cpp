#include<iostream>
#include<vector>
#include<string>
using namespace std;
const int maxn = 100;
int chl[maxn]; int chr[maxn];
int nc = 0;
char op[maxn];

int expression(int begin, int end, string s)
{
	if (begin == end) {
		nc++;
		chl[nc] = chr[nc] = 0;
		op[nc] = s[begin];
		return nc;//这里我原先写错了，写成return begin了，但其实要return nc，也就是返回当前节点的号码。
	}
	int c1 = -1;
	int c2 = -1;
	int bracket = 0;
	for (size_t i = begin; i <= end; i++)
	{
		switch (s[i]) {
		case '(':bracket++;
			break;
		case ')':bracket--;
			break;
		case '+':
		case '-':
			if (bracket == 0)
			{
				c1 = i;
			}
			break;
		case '*':
		case '/':
			if (bracket == 0)
			{
				c2 = i;
			}
			break;
		}
	}
	int curC;
	if (c1 == c2&&c1 == -1)
	{
		return expression(begin + 1, end - 1, s);
	}

	curC = c1 > -1 ? c1 : c2;
	nc++;
	int d = nc;
	chl[d] = expression(begin, curC - 1, s);
	chr[d] = expression(curC + 1, end, s);
	op[d] = s[curC];
	return d;
}


int main()
{
	string s = "4-(2*3+1)";
	expression(0, s.size() - 1, s);

	system("pause");
	return 0;
}
