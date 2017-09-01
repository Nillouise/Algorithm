#include <cstdio>
#include <cstring>
#include <algorithm>
#include<iostream>
using namespace std;
int N;
int A[1000];

int dfs(int frags, int cur)
{
	if (cur >= N)
		return frags % 2 == 0 ? 0 : 1;
	if (A[cur] % 2 == 0)return 0;

	for (int i = cur; i < N; i += 2)
	{
		if (A[i] % 2 == 1)
			if (dfs(frags + 1, i + 1) == 1)
				return 1;
	}
	return 0;
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N;

	for (size_t i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	if (dfs(0, 0) == 0)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;


}