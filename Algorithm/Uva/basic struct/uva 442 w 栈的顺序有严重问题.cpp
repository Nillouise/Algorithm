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
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;


int main()
{
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	map<char, pair<int, int>> m;
	for (int i = 0; i < N; ++i)
	{
		char c;
		int row, col;
		cin >> c >> row >> col;
		m[c] = pair<int, int>(row, col);
	}


	string s;
	getline(cin, s);

newone:
	while (getline(cin, s))
	{
		stack<pair<pii, LL> >stk;
		for (int i = 0; i<s.size(); i++)
		{
			if (s[i] == '(')
			{
				continue;
			}
			else if (s[i] == ')')
			{
				//				pair<pii, LL> pp1 = stk.top(); stk.pop();
				pair<pii, LL> pp2 = stk.top(); stk.pop();//这里把栈的顺序和读入的顺序搞错了
				pair<pii, LL> pp1 = stk.top(); stk.pop();
				if (pp1.first.second != pp2.first.first)
				{
					cout << "error" << endl;
					goto newone;
				}
				pii pp;
				LL cnt = pp1.first.first*pp1.first.second*pp2.first.second;
				cnt += pp1.second + pp2.second;
				pp.first = pp1.first.first;
				pp.second = pp2.first.second;

				stk.push(pair<pii, LL>(pp, cnt));

			}
			else
			{
				stk.push(pair<pii, LL>(m[s[i]], 0));
			}
		}
		//下面是不必要的，因为输入保证两个矩阵之间都有一对括号括着
		pair<pii, LL> p = stk.top(); stk.pop();
		while (!stk.empty())
		{
			pair<pii, LL> p2 = stk.top(); stk.pop();
			if (p.first.second != p2.first.first)
			{
				cout << "error" << endl;
				goto newone;
			}
			pair<pii, LL> p3;
			p3.second = p.first.first*p.first.second*p2.first.second;
			p3.second += p.second + p2.second;
			p3.first = pii(p.first.first, p2.first.second);
			p = p3;
		}
		cout << p.second << endl;
	}

	return 0;
}
