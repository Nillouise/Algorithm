#include<iostream>
#include"Permutation.h"
#include"Multiply.h"
#include"Chess.h"
using namespace std;
void print_permutation(int n, int* A, int cur) {
	if (cur == n) { //�ݹ�߽�
		for (int i = 0; i < n; i++) printf("%d ", A[i]);
		printf("\n");
	}
	else for (int i = 1; i <= n; i++) { //������A[cur]�����������i
		int ok = 1;
		for (int j = 0; j < cur; j++)
			if (A[j] == i) ok = 0; //���i�Ѿ���A[0]~A[cur-1]���ֹ���������ѡ
		if (ok) {
			A[cur] = i;
			print_permutation(n, A, cur + 1); //�ݹ����
		}
	}
}

int main()
{
	Chess m;
	cout<<m.run(3,2);
	while (1)
	{

	}
}