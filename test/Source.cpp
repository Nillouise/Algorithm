#include<iostream>
using namespace std;

int main()
{
	int maxX = 100, maxY = 110;
	int cnt = 0;
	int maxlen = 20;

	for (long long i = 0; i < (1L<< maxlen); i++)
	{
		long long next = i;
		int cntX = 0, cntY = 0;
		int ok = 1;
		for (int j = maxlen-1; j >= 0; j--)
		{
			for (int k = 0; k <= j; k++)
			{
				cout << ((next&(1L << k)) ? 1 : 0);
				if (next&(1L << k)) cntX++;
				else cntY++;
			}
			cout << endl;
			if (cntX > maxX || cntY > maxY)
			{
				ok = 0;
	//			break;
			}
			long long t1 = next >> 1;
			long long t2 = next &  (((1L) << j) ^ -1L);
			next = t1^t2;

		}
		if (ok = 1)
			cnt++;
	}
	cout << cnt;
	system("pause");
}