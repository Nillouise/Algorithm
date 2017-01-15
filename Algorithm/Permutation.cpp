#include "Permutation.h"
#include<iostream>
using namespace std;


void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void Permutation::run()
{
	int m;//how much number to permutation
	cin >> m;

	int element[100];
	int direction[100];
	for (int i = 0; i < 100; i++)
		element[i] = i + 1;
	memset(direction, -1, sizeof(direction));

	for (;;)
	{
		for (int i = 0; i < m; i++)
			cout << element[i] << " ";
		cout << endl;

		int maxIndex=-1;
		int maxNumber=0;
		for (int i = 0; i < m; i++)
		{
			int bia = direction[i] + i>=m ||direction[i]+i < 0  ? 0 : direction[i];
			if (element[bia + i] < element[i] && element[i] > maxNumber)
			{
				maxNumber = element[i];
				maxIndex = i;
			}
		}
		if (maxIndex == -1)
		{
			break;
		}
		else {
			for (int i = 0; i < m; i++)
			{
				if (element[i] > element[maxIndex])
				{
					direction[i] = direction[i] < 0 ? 1 : -1;
				}
			}
			swap(element[maxIndex], element[direction[maxIndex]+maxIndex]);
			swap(direction[maxIndex], direction[direction[maxIndex ] + maxIndex]);
		}

	}

}



