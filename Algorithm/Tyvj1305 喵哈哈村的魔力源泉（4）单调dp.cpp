#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

long long a[1000000 + 5];
int main()
{
	freopen("input.txt", "r", stdin);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)//������1��ͷ��Ϊʲô����Ҫ��������Ϊ�������������Ҫ��0����ʾǰ�����������
	{
		int t;
		scanf("%lld", &a[i]);//long long Ҫ��lld����
		a[i] += a[i - 1];
	}
	list<int> q;
	long long MAX = 0;
	q.push_front(0);//����������Ǳ����һ����һֱ����ȥ��
	for (int i = 1; i <= n; i++)
	{
		while (!q.empty() && a[q.front()] >= a[i]) {
			q.pop_front();
		}
		q.push_front(i);//����������pushfront����Ϊǰ�涼�Ǹ���ʱ���ʹ���ɶ���䶼��Ҫ�ˣ�iҲ��Ҫ�ˣ�����iΪ��β�������ֱ�Ӳ�Ҫ����0
		while (!q.empty() && q.back()< i - k)q.pop_back();
		MAX = max(MAX, a[i] - a[q.back()]);

	}
	cout << MAX << endl;

	return 0;
}