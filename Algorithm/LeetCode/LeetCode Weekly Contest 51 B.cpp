#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;



int main()
{
	string time = "19:34";
	int dig[4];
	dig[0] = time[0] - '0';
	dig[1] = time[1] - '0';
	dig[2] = time[3] - '0';
	dig[3] = time[4] - '0';

	vector<vector<int>> v;
	for (int i = 0; i < 4 * 4 * 4 * 4; i++)
	{
		int t = i;
		int t1 = t % 4;
		int t2 = (t / 4) % 4;
		int t3 = (t / 16) % 4;
		int t4 = (t / 64) % 4;

		vector<int> cur;
		cur.push_back(dig[t1]);
		cur.push_back(dig[t2]);
		cur.push_back(dig[t3]);
		cur.push_back(dig[t4]);
		//check
		if (cur[0] * 10 + cur[1] >= 24)
			continue;
		if (cur[2] * 10 + cur[3] > 60)continue;
		//add
		v.push_back(cur);
	}

	//find min
	int MIN[4] = { 9,9,9,9 };

	for (size_t i = 0; i < v.size(); i++)
	{
		bool big = false;
		for (size_t j = 0; j < 4; j++)
		{
			if (dig[j] == v[i][j])continue;
			if (dig[j] < v[i][j])
			{
				big = true;
				break;
			}
			else {
				break;
			}
		}
		if (!big)continue;

		bool flag = false;
		for (size_t j = 0; j < 4; j++)
		{
			if (MIN[j] > v[i][j])flag = true;
			if (MIN[j] < v[i][j])break;
		}
		if (flag)
		{
			for (size_t j = 0; j < 4; j++)
			{
				MIN[j] = v[i][j];
			}
		}
	}
	if (MIN[0] != 9)
	{
		string ret = "";
		ret += to_string(MIN[0] * 10 + MIN[1]) + ":" + to_string(MIN[2] * 10 + MIN[3]);

		return 0;
	}

	for (size_t i = 0; i < 4; i++)
	{
		MIN[i] = 9;
	}
	for (size_t i = 0; i < v.size(); i++)
	{
		bool flag = false;
		for (size_t j = 0; j < 4; j++)
		{
			if (MIN[j] > v[i][j])flag = true;
		}
		if (flag)
		{
			for (size_t j = 0; j < 4; j++)
			{
				MIN[j] = v[i][j];
			}
		}
	}



	string ret = "";
	ret += to_string(MIN[0] * 10 + MIN[1]) + ":" + to_string(MIN[2] * 10 + MIN[3]);

	return 0;
}