//有一个总量，然后每次遍历某种条件扣一次这个总量，当这个总量少于0时就结束，这样做的最好方法是扣这个总量

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
	ios::sync_with_stdio(false);

	LL k;
	cin >> k;


	string s;
	cin >> s;

	vector<int> v;

	for (auto a : s)
		v.push_back(a - '0');
	sort(v.begin(), v.end());

	int cut = k;
	for (auto a : v)
		cut -= a;

	int cnt = 0;
	//这个写法就很蠢了，因为v已经排好了。
	//这里这么写会导致算法变成n的平方的复杂度
	//while (cut>0)
	//{
	//	for (auto&a : v)
	//	{
	//		if (9 - a > 0)
	//		{
	//			cut -= 9 - a, a = 9;
	//			break;
	//		}
	//	}
	//	cnt++;
	//}

	for (auto a : v)
	{
		if (cut <= 0)break;
		cut -= 9 - a;
		cnt++;
		//if (cut <= 0)break;
	}

	cout << cnt << endl;


	return 0;
}