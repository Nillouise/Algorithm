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
const int INF = 10000000;
int W, L;
int dp[maxn];
vector<string> dict;
string s;
int dfs(int index)
{
	if (index >= s.size())return 0;
	if (dp[index] != INF)
		return dp[index];
	for (int i = 0; i < dict.size(); i++)
	{
		string word = dict[i];
		int j = 0, k = 0;
		int flag = 0;
		for (;;)
		{
			if (k >= word.size())
			{
				flag = 1;
				break;
			}
			if (j + index >= s.size())//这里没有考虑好，要是这种情况下，dp应该怎么算？
				break;
			if (s[index + j] == word[k])
			{
				j++; k++;
			}
			else {
				j++;
			}
		}
		if (flag == 1)
		{
			dp[index] = min(dfs(index + j) + (j - k), dp[index]);
		}
		else {
			dp[index] = min((int)s.size() - index, dp[index]);
		}
	}
	return dp[index];
}


int main()
{
	freopen("input.txt", "r", stdin);

	while (cin >> W >> L)
	{
		dict.clear();

		cin >> s;
		for (size_t i = 0; i < maxn; i++) dp[i] = INF;
		string word;
		for (size_t i = 0; i < W; i++)
		{
			cin >> word;
			dict.push_back(word);
		}
		cout << dfs(0) << endl;
	}

	return 0;
}