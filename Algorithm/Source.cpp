#include<iostream>
#include"Permutation.h"
#include"Multiply.h"
#include"Bracket.h"
#include"Chess.h"
#include"FenZhiXianJie.h"
using namespace std;
#include<time.h>


#include<iostream>
using namespace std;

int main()
{
	int n = 65536, m = 655360;
	double total = 0;
	for (int i = n; i <= m; i++)
	{
		if ((i - n) % 1000 == 0)
		{
			int a=100;
		}
		total += (1.0 / i)*(1.0 / i);
	}
	cout << total;
	while (true)
	{

	}
}