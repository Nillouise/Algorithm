#include<iostream>
#include<fstream>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int d[50000][20];
int d2[50000][20];

#define DEBUG

int main(void)
{
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#endif // 


	int N, Q;
	cin >> N >> Q;
	for (size_t i = 0; i < N; i++) { cin >> d[i][0]; d2[i][0] = d[i][0]; };
	for (size_t j = 1; (1 << j) <= N; j++)//j��ʼֵҪ����1����Ϊ�������ֵķ�Χ�Ѿ�����
	{
		for (size_t i = 0; i + (1 << j) - 1 < N; i++)
		{
			d[i][j] = min(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
			d2[i][j] = max(d2[i][j - 1], d2[i + (1 << (j - 1))][j - 1]);//����Ҫ�� ���Ÿ�<<��Ȼ�Ǵ����
		}
	}



	for (size_t i = 0; i < Q; i++)
	{
		int A, B;
		scanf("%d%d", &A, &B);//�����кܶ��������ݣ����ǳ���ĳ�scanf��
		A--; B--;
		if (A > B)swap(A, B);
		int k = 0;
		while ((1 << (k + 1)) <= B - A + 1)//����kҪ+1����Ϊkֻ�� һ����ѣ�
		{
			k++;
		}
		int height = max(d2[A][k], d2[B - (1 << k) + 1][k]);//������B-����Ϊ�Ӻ���ǰ�� ��ξ���
		int low = min(d[A][k], d[B - (1 << k) + 1][k]);
		cout << (height - low) << endl;
	}
#ifdef DEBUG
	getchar();
	while (true)
	{

	}
#endif // 

	return 0;
}