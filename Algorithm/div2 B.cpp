#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	string str;
	cin >> str;
	set<char> cnt;
	int MAX = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'A'&&str[i] <= 'Z')
		{
			if (cnt.size() > MAX) {
				MAX = cnt.size();
			}
			cnt.clear();
		}
		else {
			cnt.insert(str[i]);
			//注意这里要判断最后的截断
			if (cnt.size() > MAX) {
				MAX = cnt.size();
			}
		}
	}
	cout << MAX << endl;


	return 0;
}