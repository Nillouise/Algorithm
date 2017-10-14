//������Ϊ�����ŵ��Է��ԣ�������Զ��ż����

//A detail worth mentioning is that xi xor yj may exceed 2��106 and become as large as 2097152 = 221. Thus the array should be of size 2097152 instead of 2��106 and if not, invalid memory access may take place.
//��������Ӧ�ÿ�����飬��������set����Ϊ2000*2000����ͦ���

#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>//���sqrtҪ��
#include<queue>
using namespace std;
typedef long long LL;



int main()
{
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v1(n);
	vector<int> v2(n);

	set<int> s;
	for (int i = 0; i < n; ++i)
	{
		cin >> v1[i];
		s.insert(v1[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> v2[i];
		s.insert(v2[i]);
	}

	int cnt = 0;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			if (s.find(v1[i] ^ v2[j]) != s.end())cnt++;
		}
	}
	if (cnt % 2 == 0)
	{
		cout << "Karen" << endl;
	}
	else
	{
		cout << "Koyomi" << endl;
	}



	return 0;
}