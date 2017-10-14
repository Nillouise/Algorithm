
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

int clw(int b, int m, int e)
{
	//for(int i=b;i<=e;i++)
	for (int i = b; i != e; i++)
	{
		if (i>12) i = (i % 12) + 1;//这里错了
		if (i == m)
		{
			return 0;
		}
	}
	return 1;
}


int clw2(int b, int m, int e)
{
	//for (int i = b; i <= e; i++)
	for (int i = b; i != e; i++)
	{
		i = (i % 60);
		if (i == m)
		{
			return 0;
		}
	}
	return 1;


}
int h, m, s, t1, t2;
//int clw3()
//{
//	for (int i=s;;i++)
//	{
//		if (i == 60)i == 0, m++;
//		if (m == 60)m == 0, h++;
//		if()
//	}
//}




int main()
{
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);

	cin >> h >> m >> s >> t1 >> t2;

	int cnt[2] = { 0,0 };
	cnt[clw(t1, h, t2)]++;
	t1 %= 12, t2 %= 12;
	cnt[clw2(t1 * 5, m, t2 * 5)]++;
	cnt[clw2(t1 * 5, s, t2 * 5)]++;

	//if(!cnt[0]||!cnt[0])
	if (!cnt[0] || !cnt[1])
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

	return 0;
}