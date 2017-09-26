
//这题做的时候太急了， 有了一点错误思路也写代码


//We will use an array cnt where we will store how many times the numbers from 1 to n met in the given array a.Put all numbers that never occur in the array a in a vector need — we must add this numbers in the array a to make a permutation.
//
//We will add numbers from need in ascending order because we want to get lexicographically minimal permutation.Let pos is a pointer on the current number needpos which we need to add on the current move.Initially, pos  = 0.
//
//We will iterate through the array a.Let the current number equals to ai.If cntai  = 1, we move to the next number in the array.If we added not all numbers from need, and ai > needpos or there already was ai on the prefix of the array(to check it we can use, for example, boolean array), then we put needpos in the current position, decrease cntai on one, increase pos and answer on one.If we do not change anything on that step we mark that ai already was on the prefix of the array.After that we move to the next number in array a.

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