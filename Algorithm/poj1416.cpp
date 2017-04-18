#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<stack>
#include<set>
#include<functional>
#include<queue>
using namespace std;
const int maxn = 1000;
int target;
int goodpath[1000];
int pathsize = 0;
int closet = 0;
int cloestflag = 0;
int path[maxn];
int getInt(string s)
{
	stringstream ss;
	ss << s;
	int r;
	ss >> r;
	return r;
}
void dfs(string s, int sum, int depth)
{
	if (s.size() == 0)
	{
		if (sum > closet&&sum <= target)
		{
			cloestflag = 0;
			closet = sum;
			for (size_t i = 0; i < maxn; i++)
				goodpath[i] = path[i];
			pathsize = depth;
			return;
		}
		if (sum == closet)
		{
			cloestflag = 1;
			return;
		}
		return;
	}
	if (sum > target)return;
	if (sum + getInt(s) < closet)return;
	for (size_t i = 0; i < s.size(); i++)
	{
		path[depth] = getInt(s.substr(0, i + 1));
		int newsum = sum + getInt(s.substr(0, i + 1));
		dfs(s.substr(i + 1, s.npos), newsum, depth + 1);
	}
	return;
}

int main()
{
	freopen("input.txt", "r", stdin);

	string s;
	while (cin >> target >> s&&target != 0)
	{
		closet = 0;
		dfs(s, 0, 0);
		if (closet != 0 && cloestflag != 1)
		{
			cout << closet << " ";
			for (size_t i = 0; i < pathsize; i++)
			{
				cout << goodpath[i] << " ";
			}
			cout << endl;
		}
		else if (closet == 0)
		{
			cout << "error" << endl;
		}
		else if (cloestflag == 1)
			cout << "rejected" << endl;
	}


	return 0;
}