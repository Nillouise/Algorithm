#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include <ctime>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int n, m, q;
int t, r1, c1, r2, c2;

//һ��ʼ���ݷ�ΧҲ������
LL G[3000][3000];

int add(int x, int y, LL val)
{
	//���Ǵ�ģ��ڶ�ά�����������ô�ɣ�y�ڱ���һ�κ�Ҫ���õ�
	//	for(;x<=m;x+=x&(-x))
	//	{
	//		for(;y<=n;y+=y&(-y))
	//		{
	//			G[y][x] += val;//������y��x
	//		}
	//	}
	for (int kx = x; kx <= m; kx += kx&(-kx))
	{
		for (int ky = y; ky <= n; ky += ky&(-ky))
		{
			G[ky][kx] += val;
		}
	}


	return 0;
}

LL query(int x, int y)
{
	LL ans = 0;

	for (int kx = x; kx; kx -= kx&(-kx))
	{
		for (int ky = y; ky; ky -= ky&(-ky))
		{
			ans += G[ky][kx];
		}
	}

	return ans;
}
int rd() {
	return rand() << 15 | rand();
}

int main()
{
	//	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	srand(time(NULL));
	//���ﲻ�Ǳ�Ҫ�ģ�����rand()�ķ�Χ̫С��Ҫ����Χ�Ǳ�Ҫ��
	//	for (int i = 0; i < 011; i++) {
	//		srand(rd());
	//	}

	cin >> n >> m >> q;
	while (q--)
	{
		cin >> t >> r1 >> c1 >> r2 >> c2;

		if (t == 1)
		{
			//��������rand()�ķ�Χ�Ǳ�Ҫ��
			LL val = (rand() << 15) + rand() + 1;//��ֹΪ0

												 //����add��ʾ���˶�ά��
												 //			add(c1, r1, val);
												 //			add(c2+1, r2+1, -val);
			add(c1, r1, val);
			add(c2 + 1, r2 + 1, val);
			add(c2 + 1, r1, -val);
			add(c1, r2 + 1, -val);

		}
		else if (t == 2)
		{
			LL cur = query(c1, r1);
			LL pre = query(c1 - 1, r1 - 1);
			add(c1, r1, pre - cur);
			add(c2 + 1, r2 + 1, pre - cur);
			add(c2 + 1, r1, cur - pre);
			add(c1, r2 + 1, cur - pre);
		}
		else
		{
			LL a1 = query(c1, r1);
			LL a2 = query(c2, r2);

			if (a1 == a2)
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}

	}





	return 0;
}