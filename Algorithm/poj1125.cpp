#include<iostream>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<algorithm>
#include<iterator>
#include<sstream>
#include <cstring>  
#include <cstdio>  
using namespace std;

int gra[110][110];






int main()
{
	int n;
	while (~scanf("%d", &n) && n)
	{
		memset(gra, -1, sizeof(gra));//�� ��ͨ��· ��ʼ��Ϊ-1������ز����á�
		for (int sn = 0; sn < n; sn++)
		{
			int ctn;
			cin >> ctn;
			for (int i = 0; i < ctn; i++)
			{
				int point, t;
				cin >> point >> t;
				gra[sn][point - 1] = t;
			}
		}

		//solve

		//���floddy ��д����һ�Σ��м�� һ��Ҫ��������ѭ����
		for (size_t j = 0; j < n; j++)
		{
			for (size_t i = 0; i < n; i++)
			{
				for (size_t k = 0; k < n; k++)
				{
					if (gra[i][j] != -1 && gra[j][k] != -1)
						if (gra[i][k] == -1 || gra[i][k] > gra[i][j] + gra[j][k])
							gra[i][k] = gra[i][j] + gra[j][k];
				}
			}
		}
		int gst = -1, gti = 1061109567;
		for (size_t i = 0; i < n; i++)
		{
			int longest = -1;
			int ok2 = 1;
			for (size_t j = 0; j < n; j++)
			{
				if (i == j)continue;
				if (gra[i][j] == -1) { ok2 = 0;  break; }
				if (longest < gra[i][j]) longest = gra[i][j];
			}
			if (ok2 == 0)continue;
			if (longest != -1 && longest < gti) { gst = i; gti = longest; }
		}

		cout << gst + 1 << " " << gti << endl;

	}

	return 0;
}