//�����ҷ���һ������û�аѶ��ַ�Ҫ�õ������ݷ�ȫ

#include <iostream>
#include <cstdio>
#include <cstring>
#include<string>
#include <algorithm>
#include<sstream>
#include<cmath>//������log ����
using namespace std;
const int maxn = 50000 + 5;
int L, N, M;
int dist[maxn];

int main() {
	freopen("input.txt", "r", stdin);

	while (cin >> L >> N >> M)
	{
		dist[0] = 0;
		for (size_t i = 1; i < N + 1; i++) cin >> dist[i];
		dist[N + 1] = L;

		sort(dist, dist + N + 2);
		int low = L, height = L + 1;//���ַ����϶������ָ�򲻿��ܵ�ֵ
		for (size_t i = 1; i < N + 2; i++)
			low = min(dist[i] - dist[i - 1], low);
		//����������������ѧ�ģ�����ɶ��ַ��õ�����������ݲ�ȫ
		//low = min(low, L - dist[N - 1]);//����û�������һ��ʯͷ���ұ߰��ľ���
		//low = min(dist[0], low);//����û���㿪ʼ��ʯͷ����߰��ľ���
		while (low < height - 1)
		{
			int mid = low + (height - low) / 2;
			int cnt = 0;
			int lefti = 0;
			//���ǱȽ������ľ���
			//��������˼·�ǲ��Եģ�lefti������ߵ�ʯͷ��������±꣬���Ӱ����������
			//�����������ôд�����׳���
			//if (dist[0] < mid) {
			//	cnt++;
			//	lefti = 1;
			//}

			for (size_t i = lefti + 1; i < N + 2; i++)
			{
				if (dist[i] - dist[lefti] < mid)//������д���>�ţ�û�м����������
				{
					cnt++;
					continue;
				}
				else {
					lefti = i;
				}
			}
			//���			if (L - dist[lefti] < mid)cnt++;

			if (cnt > M) {
				height = mid;
			}
			else {
				low = mid;
			}

		}
		cout << low << endl;

	}



	return 0;
}