//一开始我还打算按人数一个一个塞到座位，而不是根据座位的多少安排人数，这种思路就是错的

#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>//这个sqrt要用
#include<queue>
using namespace std;
typedef long long LL;



int main()
{
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);

	LL n, k;
	cin >> n >> k;
	vector<LL> a(k);
	for (size_t i = 0; i < k; i++)
	{
		cin >> a[i];
	}

	LL seat2 = n * 2;
	LL seat4 = n;

	for (int i = 0; i < a.size(); i++)
	{
		int cut = min(seat4, a[i] / 4);
		seat4 -= cut;
		a[i] -= cut * 4;
	}

	for (int i = 0; i < a.size(); i++)
	{
		int cut = min(seat2, a[i] / 2);
		seat2 -= cut;
		a[i] -= cut * 2;
	}


	map<LL, LL> m;
	for (size_t i = 0; i < a.size(); i++)
	{
		m[a[i]]++;
	}

	for (auto i = m.begin(); i != m.end(); i++)
	{
		if (i->first >= 4 && i->second > 0)
		{
			cout << "NO" << endl;
			return 0;
		}
	}

	LL MIN = min(seat4, m[3]);
	m[3] -= MIN;
	seat4 -= MIN;
	if (m[3] > 0)
	{
		m[2] += m[3];
		m[1] += m[3];
		m[3] = 0;
	}

	//MIN = min(m[1], m[2]);
	//MIN= min(MIN,seat4);
	//m[1] -= MIN;
	//m[2] -= MIN;
	//seat4 -= MIN;

	//if (m[3] > 0) {
	//	cout << "NO" << endl;
	//	return 0;
	//}
	LL seat1 = 0;//这个seat1是很重要的思路

	if (m[2] > 0)
	{
		LL MIN = min(m[2], seat2);
		m[2] -= MIN;
		seat2 -= MIN;

		//这里逻辑是错的，即使m[2]大于seat4，也可以分一个人坐
		//if (m[2] > seat4)
		//	return cout << "NO" << endl, 0;
		//else {
		//	seat4 -= m[2];
		//	seat1 += m[2];
		//}
		LL MAX = min(seat4, m[2]);
		seat4 -= MAX;
		seat1 += MAX;
		m[1] += (m[2] - MAX) * 2;//这里一开始又没想到
	}

	if (seat4 * 2 + seat2 + seat1 >= m[1])
	{
		return cout << "YES" << endl, 0;
	}
	else {
		return cout << "NO" << endl, 0;
	}




	//if (seat2>=m[1]+m[2])
	//{
	//	cout << "YES" << endl;
	//}
	//else {
	//	cout << "NO" << endl;
	//}

	return 0;
}