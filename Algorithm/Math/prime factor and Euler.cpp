//http://www.2cto.com/kf/201308/232597.html
//http://qscoj.cn/problem/163/
//�������Ӻ� ŷ��������Ӧ��

#include<iostream>
#include<list>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--)
	{
		long long N;
		cin >> N;
		long long ans = N;
		long long phi = N;
		// �����N��ûһ��ѭ�������ã���һ���������������ϵ�����ʱ������һ����<=sqrt(N)��
		//����ʣ��һ������ʱ�����ﲻ�ܴ���ã�������Ҫ��������if��䴦��
		for (long long i = 2; i <= sqrt(N); i++)
		{
			if (N%i == 0)
			{
				phi = phi / i*(i - 1);
				while (N%i == 0)N /= i;
			}
		}
		if (N>1) phi = phi / N *(N - 1);

		ans = phi / 2 * ans;//phi���ж��ٸ�����N���ʣ���Щ���ʵ������ǳɶԳ��֣�һ������Ӿ͵���N�������Ծ���Ҫ��������Ϳ�����
		cout << ans << endl;
	}

	return 0;
}