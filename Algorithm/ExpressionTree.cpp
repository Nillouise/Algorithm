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
		return nc;//������ԭ��д���ˣ�д��return begin�ˣ�����ʵҪreturn nc��Ҳ���Ƿ��ص�ǰ�ڵ�ĺ��롣
	}
	int c1 = -1;
	int c2 = -1;
	int bs = 0;//bracket state
	for (size_t i = begin; i <= end; i++)//�����Ǵ�begin ������end�������ĺ�����ҵ��������ұߵ�����������������ʽ�����ϵġ�
	{
		switch (s[i]) {
		case '(':bs++;break;
		case ')':bs--;break;
		case '+':case '-':if (!bs)c1 = i;break;
		case '*':case '/':if (!bs)c2 = i;break;
		}
	}

	if (c1 == c2&&c1 == -1)//���������ŵ����
	{
		return expression(s,begin + 1, end - 1);
	}

	int curC = c1 > -1 ? c1 : c2;
	nc++;
	int snap = nc;//�����snap �����һ����˼������ nc���ܻ��ں���������ı䣬���Կ���һ��.
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
