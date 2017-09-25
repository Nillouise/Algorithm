#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;
typedef long long LL;
int arr[200000 + 5];
vector<int> vec[200000 + 5];
int vis[200000 + 5];
int m[200000 + 5];
int main()
{
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		int c = 0;
		cin >> c;
		arr[i] = c;
		vis[c] = 1;
		vec[c].push_back(i);
		m[c]++;
	}

	vector<int> seed;
	for (size_t i = 1; i <= n; i++)
	{
		if (vis[i] == 0)seed.push_back(i);
	}

	int pos = 0;
	set<int> haspass;
	for (size_t i = 0; i < n; i++)
	{
		//if (pos == seed.size())break;//这里是因为错误的思路，才需要加这一句的
		if (m[arr[i]]>1)
		{
			//m[arr[i]]--;//这里错了，只有改了位置，才需要--；
			if (haspass.find(arr[i]) != haspass.end())
			{
				m[arr[i]]--;
				arr[i] = seed[pos++];
			}
			else {
				if (arr[i] < seed[pos])
				{
					haspass.insert(arr[i]);
				}
				else {
					m[arr[i]]--;
					arr[i] = seed[pos++];
				}
			}
		}
	}
	cout << seed.size() << endl;
	for (size_t i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}