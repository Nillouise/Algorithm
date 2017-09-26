#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	map<int, int> m;
	m.clear();
	for (size_t i = 0; i < n; i++)
	{
		int card;
		cin >> card;
		m[card]++;
	}
	if (m.size() != 2)cout << "NO" << endl;
	else
	{
		map<int, int>::iterator it = m.begin();
		map<int, int>::iterator it2 = --m.end();
		if (it->second == it2->second)
		{
			cout << "YES" << endl;
			cout << it->first << " " << it2->first << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}


	return 0;
}