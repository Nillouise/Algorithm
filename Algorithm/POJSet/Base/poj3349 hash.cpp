//return (bit&(1 << pos))>0;这句写错了，写成(bit&(1 << pos)) == 1，殊不知这种位运算产生的根本不是1，而是真而已
#include<algorithm>
#include<iostream>
#include<string>
#include<stack>
using namespace std;
int n;
const int maxstate = 1200010;
const int hashsize = 1200007;
struct snow
{
	int f[6];
	int next;
};
int head[hashsize];
snow hashtable[maxstate];
int hashID(int *a)
{
	int h = 0;
	for (size_t i = 0; i < 6; i++)
	{
		h += a[i];
		h %= hashsize;
	}
	return h;
}
bool comp(snow s1, snow s2)
{
	int a[12]; for (size_t i = 0; i < 6; i++) { a[i + 6] = a[i] = s1.f[i]; }

	//正序比较
	for (size_t i = 0; i < 6; i++)
	{
		int flag = 0;
		for (int j = 0; j < 6; j++)
		{
			if (s2.f[j] != a[i + j])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			return true;
	}
	//逆序比较
	for (size_t i = 0; i < 6; i++)
	{
		int flag = 0;
		for (int j = 0; j < 6; j++)
		{
			if (s2.f[5 - j] != a[i + j])//逆序比较只是把 j改成了 5-j就可以了
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			return true;
	}

	return false;
}
int insertIndex = 0;
bool tryToInsert(int *a)
{

	snow sn; for (size_t i = 0; i < 6; i++) sn.f[i] = a[i];

	int h = hashID(a);
	int node = head[h];
	while (node != -1)
	{
		if (comp(hashtable[node], sn))
		{
			return true;
		}
		else {
			node = hashtable[node].next;
		}
	}
	sn.next = head[h];
	head[h] = insertIndex;
	hashtable[insertIndex] = sn;
	insertIndex++;
	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);

	while (cin >> n&&n != 0)
	{
		memset(head, -1, sizeof(head));
		insertIndex = 0;
		bool flag = false;
		for (size_t i = 0; i < n; i++)
		{
			int a[6];
			for (size_t j = 0; j < 6; j++)
			{
				//				cin >> a[j];//这里会导致超时
				scanf("%d", &a[j]);
			}
			if (!flag)
			{
				flag = tryToInsert(a);
			}
		}
		if (flag)
		{
			cout << "Twin snowflakes found." << endl;
		}
		else {
			cout << "No two snowflakes are alike." << endl;
		}
	}


	return 0;

}