//���˫������һ��ʼ���������ƶ�һ�����ʱ��Ҫ�ֺ�ԭ����λ����
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
#include <bitset>
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 5;
int let[MAXN], rit[MAXN];
int inverse = 0;
int n, m;
void link(int x, int y)
{
	rit[x] = y;
	let[y] = x;
}


int main()
{
	freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(false);

	int t = 1;
	while (cin >> n >> m)
	{
		for (int i = 1; i <= n + 1; i++)
		{
			link(i - 1, i);
		}

		inverse = 0;
		while (m--)
		{
			int com, a, b;
			cin >> com;
			if (com == 4)
			{
				inverse = !inverse;
			}
			else
			{
				cin >> a >> b;

				//				int i = rit[0];
				//				int pos = 1;
				//				while (i != n + 1)
				//				{
				//									cout << i << " ";
				//					i = rit[i];
				//				}
				//				cout << endl;
				if (com == 3)
				{
					//���Ǵ��
					//					//һ��ʼ�����ֺ����la��//���ｻ���ǲ����ֺϵ�
					//					int la = let[a];
					//					int ra = rit[a];
					//					int lb = let[b];
					//					int rb = rit[b];
					//					//���ֺϣ�������������
					//					link(la, ra);
					//					link(lb, rb);
					//����Ҫ�Ƚ����ˣ������ҵ�
					if (rit[b] == a)swap(a, b);

					int lb = let[b];
					int rb = rit[b];
					int la = let[a];
					int ra = rit[a];

					//					//����Ҫ�ر��������������ڵ������
					//
					//					if (rit[b] == a)swap(a, b);
					if (rit[a] == b)
					{
						link(a, rb);
						link(b, a);
						link(la, b);
					}
					else
					{
						link(lb, a);
						link(a, rb);
						link(la, b);
						link(b, ra);
					}


					//					int lx = let[a];
					//					int rx = rit[a];
					//					int ly = let[b];
					//					int ry = rit[b];
					//					link(lx, b);
					//					link(b, rx);
					//					link(ly, a);
					//					link(a, ry);

				}
				else
				{
					if (inverse)
					{
						if (com == 1)com = 2; else com = 1;
					}
				}
				if (com == 1)
				{
					//�����link�ǻ�ı����let��ȡ�����ݵģ�����Ҫ���ֺ�
					//һ��ʼ�����ֺ����la��
					int la = let[a];
					int ra = rit[a];
					link(la, ra);

					int ly = let[b];
					//�����link�ǻ�ı����let��ȡ�����ݵ�
					link(ly, a);
					link(a, b);

				}
				//				else //�����com==3�����Ҳ���������ˣ��´�һ��Ҫд������
				else if (com == 2)
				{
					//�ǰ�a����������ǰ�b���
					//					int lb = let[b];
					//					int rb = rit[b];
					//					link(lb, rb);
					int la = let[a];
					int ra = rit[a];
					link(la, ra);

					int ry = rit[b];

					link(a, ry);
					link(b, a);



				}
			}
		}
		LL total = 0;
		if (!inverse)
		{
			int i = rit[0];
			int pos = 1;
			while (i != n + 1)
			{
				if (pos & 1)
					total += i;
				//				cout << i << " ";
				i = rit[i];
				pos++;
			}
		}
		if (inverse)
		{
			int i = let[n + 1];
			int pos = 1;
			while (i != 0)
			{
				if (pos & 1)
					total += i;
				//				cout << i<<" ";
				i = let[i];
				pos++;
			}
		}
		cout << "Case " << t++ << ": " << total << endl;

	}


	return 0;
}