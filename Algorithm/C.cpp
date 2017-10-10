//Let us show that if a solution exists, then there is always a solution that uses at most two problems.First, if there is a problem not known to any of the teams, that we can just take this only problem in the set.Next, suppose that there is a problem known only to one of the teams.If there is a problem this team doesn't know, then these two problems make a good set. Otherwise, the team knows all the problems, hence we cannot find a good set.
//
//In the rest case, each problem is known to at least two of the teams.Now, if there is a good set of problems, then each of the problems in the set must be known to exactly two of the teams.Indeed, let pi be the number of teams that knows the problem.If a good set contains k problems, then we must have, since otherwise we would have a team that knows more than half of the problems by pigeonhole principle.We also have pi ≥ 2, hence, and only the case pi  = 2 is possible.
//
//At this point, if we can find a pair of problems with pi  = 2 and non - intersecting set of teams, then we are done.Otherwise, we can show that a good set does not exist by case analysis.
//
//To avoid O(n2) solution, we can leave at most 24 problems with unique types(sets of teams) and do pairwise checking on them.This solution has O(n) complexity.
//上面这个分析的前提是，只有4个队伍，所以只需要最多两题，论证中的那个2的意思是，最多有4个队，4个对乘以题目数K 再乘以一半，就是2K


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
		if (i>12) i = (i % 12) + 1;
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

	int n, k;
	cin >> n >> k;
	set<int> s;
	for (int i = 0; i<n; i++)
	{
		int c = 0;
		for (int i = 0; i<k; i++)
		{
			int a;
			cin >> a;
			//c=(c << i) + a;
			c = (a << i) + c;
		}
		s.insert(c);
	}

	vector<int> v;
	for (auto i : s)
	{
		v.push_back(i);
	}

	int flag;
	for (int i = 0; i<v.size(); i++)
	{
		if (v[i] == 0)return cout << "YES" << endl, 0;

		for (int j = i + 1; j<v.size(); j++)
		{
			flag = 1;
			for (int o = 0; o<k; o++)
			{
				//if ((v[i] & (1 << o)>0) && (v[j] & (1 << o)>0)) //这里运算符号优先序不对
				if (((v[i] & (1 << o))>0) && ((v[j] & (1 << o))>0))
				{
					flag = 0;
					break;
				}
			}
			//i&&j&&(!(v[i]&v[j])) //这么判断最好

			if (flag == 1)
			{
				if (n == 10000)
				{
					for (auto a : v)
					{
						cout << a << " ";
					}
				}

				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;

	return 0;
}