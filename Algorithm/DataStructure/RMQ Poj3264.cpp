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
	for (size_t j = 1; (1 << j) <= N; j++)//j初始值要等于1，因为单个数字的范围已经算了
	{
		for (size_t i = 0; i + (1 << j) - 1 < N; i++)
		{
			d[i][j] = min(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
			d2[i][j] = max(d2[i][j - 1], d2[i + (1 << (j - 1))][j - 1]);//这里要加 括号给<<不然是错误的
		}
	}



	for (size_t i = 0; i < Q; i++)
	{
		int A, B;
		scanf("%d%d", &A, &B);//这题有很多输入数据，还是趁早改成scanf吧
		A--; B--;
		if (A > B)swap(A, B);
		int k = 0;
		while ((1 << (k + 1)) <= B - A + 1)//这里k要+1，因为k只是 一半而已，
		{
			k++;
		}
		int height = max(d2[A][k], d2[B - (1 << k) + 1][k]);//这里是B-，因为从后往前算 半段距离
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