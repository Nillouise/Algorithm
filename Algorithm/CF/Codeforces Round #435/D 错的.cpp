#include <iostream>
using namespace std;
char s[1005];
int ans, pos0, pos1, n;
void send()
{
	printf("? %s\n", s);
	fflush(stdout);
	scanf("%d", &ans);
	ans = n - ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
		s[i] = '1';
	send();
	int mans = ans;
	s[0] = '0';
	send();
	if (mans>ans)
		pos1 = 1;
	else
		pos0 = 1;
	s[0] = '1';
	int st = 1, en = n;
	while (st != en)
	{
		int mid = (st + en) / 2;
		for (int i = 1; i <= mid; i++)
			s[i] = '0';
		send();
		if ((mans - ans)*(pos1 ? 1 : -1) == mid)
			st = mid + 1;
		else
			en = mid;
		for (int i = 1; i <= mid; i++)
			s[i] = '1';
	}
	if (!pos0)
		pos0 = st + 1;
	else
		pos1 = st + 1;
	printf("! %d %d", pos0, pos1);
	fflush(stdout);
}