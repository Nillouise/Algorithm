// UVa12096 The SetStack Computer
// Rujia Liu
#include<iostream>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

typedef set<int> Set;
map<Set, int> IDcache; // 把集合映射成ID
vector<Set> Setcache; // 根据ID取集合

					  // 查找给定集合x的ID。如果找不到，分配一个新ID
int ID(Set x) {
	if (IDcache.count(x)) return IDcache[x];
	Setcache.push_back(x); // 添加新集合
	return IDcache[x] = Setcache.size() - 1;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		stack<int> s; // 题目中的栈
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string op;
			cin >> op;
			if (op[0] == 'P') s.push(ID(Set()));
			else if (op[0] == 'D') s.push(s.top());
			else {
				Set x1 = Setcache[s.top()]; s.pop();
				Set x2 = Setcache[s.top()]; s.pop();
				Set x;
				if (op[0] == 'U') set_union(ALL(x1), ALL(x2), INS(x));
				if (op[0] == 'I') set_intersection(ALL(x1), ALL(x2), INS(x));
				if (op[0] == 'A') { x = x2; x.insert(ID(x1)); }
				s.push(ID(x));
			}
			cout << Setcache[s.top()].size() << endl;
		}
		cout << "***" << endl;
	}
	return 0;
}

//我自己的版本
#include<iostream>
#include<algorithm>
#include<stack>
#include<set>
#include<iterator>
#include<string>
#include<vector>
#include<map>
using namespace std;
typedef set<int> Set;
vector<Set> setCache;
map<Set, int> setMap;//这个名字不是很好，不应该写类型名作为变量名的一部分

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

int getID(Set s)
{
	if (setMap.count(s) > 0)
		return setMap[s];
	else {
		setCache.push_back(s);
		setMap[s] = setCache.size() - 1;
		return setCache.size() - 1;
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		stack<int> s;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string op;
			cin >> op;

			if (op[0] == 'P')s.push(getID(Set()));
			else if (op[0] == 'D')s.push(s.top());
			else {
				Set x1 = setCache[s.top()]; s.pop();
				Set x2 = setCache[s.top()]; s.pop();
				Set x;
				if (op[0] == 'U')set_union(ALL(x1), ALL(x2), INS(x));
				if (op[0] == 'I')set_intersection(ALL(x1), ALL(x2), INS(x));
				if (op[0] == 'A') { x2.insert(getID(x1)); x = x2; }
				s.push(getID(x));
			}
			cout << setCache[s.top()].size()<<endl;
		}
	}
}