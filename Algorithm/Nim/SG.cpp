//��������Ĵ��봫˵ ������ �ҹ���
//����ʱ�� : 2017��3��11�� 16 : 04   ������ : 2017��3��11�� 16 : 04   ʱ������ : 1000ms   �ڴ����� : 128M
//
//	����
//	��������n���ƣ�ÿ������a[i]���˿ˣ���������������˿ˣ�˭�õ����һ���˿ˣ�˭��ʤ���ˡ�
//
//	�����������е���֣����ǿ���ѡ��һ�����������˿��ƣ�����ѡ��ʹ��ĳһ���˿��Ʊ�����������С���˿��ơ�
//
//	������������˶��ǳ����ǵĻ���˭�ܻ�ʤ�أ�
//
//	����
//	��һ�а�����������T����ʾ��������������
//	������T��������ݣ�
//	��һ��һ��n����ʾ��n���ơ�
//	�ڶ���n������a[i]����ʾÿ���Ƶ�������
//
//	��֤n <= 1000000, a[i] <= 1e9
//
//	���
//	��һ����ʤ�����First player wins.
//	�ڶ�����ʤ�����Second player wins.
//��Уԭ�⡣Sg���������⡣
//
//sg[0] = 0
//
//��x = 8k + 7ʱsg[x] = 8k + 8��
//
//��x = 8k + 8ʱsg[x] = 8k + 7,
//
//����ʱ��sg[x] = x����k >= 0��
//http://www.cnblogs.com/qscqesze/p/6537820.html
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
	int T, n;
	scanf("%d", &T);
	while (T--)
	{
		int ans = 0;
		scanf("%d", &n);
		for (int i = 0; i<n; i++)
		{
			int x, sg;
			scanf("%d", &x);
			if (x % 8 != 0 && x % 8 != 7)
				sg = x;
			else
				if (x % 8 == 0) sg = x - 1; else sg = x + 1;
			ans ^= sg;
		}
		if (ans) printf("First player wins.\n"); else printf("Second player wins.\n");
	}
	return 0;
}