//return (bit&(1 << pos))>0;���д���ˣ�д��(bit&(1 << pos)) == 1���ⲻ֪����λ��������ĸ�������1�����������
#include<algorithm>
#include<iostream>
#include<string>
#include<stack>
#include<set>
#include<functional>
#include<queue>
using namespace std;



int main()
{
	freopen("input.txt", "r", stdin);
	int N;
	while (cin >> N&&N != 0)
	{
		priority_queue<int, vector<int>, greater<int> > pq;
		for (size_t i = 0; i < N; i++)
		{
			int a;
			//			cin >> a;
			scanf("%d", &a);
			pq.push(a);
		}
		long long total = 0;
		//		while (!pq.empty())//��empty�ᵼ�³�ʱ//��ʱ������Ϊempty��������Ϊ����ʣ��ڵ��Ҫ���ڵ���2���У�������>=1��

		while (pq.size()>1)//����size Ҫ���� 2���У���Ȼ��ʲôЧ�������Ƕ���˸��ڵ�һ��
		{
			int a1 = pq.top(); pq.pop();
			int a2 = pq.top(); pq.pop();
			int a3 = a1 + a2;
			pq.push(a3);
			total += a3;
		}
		cout << total << endl;
	}


	return 0;
}