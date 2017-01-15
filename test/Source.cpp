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
map<Set, int> setMap;

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
		string op;
		cin >> op;
		stack<int> s;
		if (op[0] == 'P')s.push(getID( Set()));
		if (op[0] == 'D')s.push(s.top());
		else {
			Set x1 = setCache[s.top()]; s.pop();
			Set x2 = setCache[s.top()]; s.pop();
			Set x;
			if (op[0] == 'U')set_union(ALL(x1), ALL(x2), INS(x));
			if (op[0] == 'I')set_intersection(ALL(x1), ALL(x2), INS(x));
			if (op[0] == 'A') { x2.insert(getID(x1)); x = x2; }
			s.push(getID(x));
		}
		cout << setCache[s.top()].size();

	}
}