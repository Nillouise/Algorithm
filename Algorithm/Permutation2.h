#pragma once
#include<iostream>
using namespace std;
class Permutation2
{
	void run()
	{

	}
	void dfs(int curPos,int total,int *a)
	{
		if (curPos == total)
		{
			for (size_t i = 0; i < total; i++)
			{
				cout << a[i]<< " ";
			}
			cout << endl;
		}
		for (size_t i = 1; i <= total; i++)
		{
			int ok = 1;
			for (size_t j = 0; j < curPos; j++)
			{
				if (a[j]==i)
				{
					ok = 0;
					break;
				}
			}
			if (ok == 1)
			{
				dfs(curPos + 1, total, a);
			}
		}


	}

};