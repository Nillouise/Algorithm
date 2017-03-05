#include<iostream>
using namespace std;

void print_permutation(int *a, int length, int cur)
{
	if (cur == length)
	{
		for (size_t i = 0; i < length; i++) cout << a[i];
		cout << endl;
	}
	else
		for (size_t i = 1; i <= length; i++)
		{
			int ok = 1;
			for (size_t j = 1; j < cur; j++)
			{
				if (a[j] == i)
				{
					ok = 0;
					break;
				}
			}
			if (ok)
			{
				a[cur] = i;
				print_permutation(a, length, cur + 1);
			}

		}
}

void print_permutation_duplicate(int *P, int *a, int length, int cur)
{
	if (length == cur)
	{
		for (size_t i = 0; i < length; i++)cout << a[i];
		cout << endl;
	}
	else {
		for (size_t i = 0; i < length; i++)
			if(!i||P[i]!=P[i-1])
			{
				int c1 = 0;
				int c2 = 0;
				for (size_t j = 0; j < cur; j++)
					if (a[j] == P[i])
						c1++;
				for (size_t j = 0; j < length; j++)
					if (P[j] == P[i])
						c2++;
				if (c1 < c2)
				{
					a[cur] = P[i];
					print_permutation_duplicate(P, a, length, cur + 1);
				}
			}
	}

}