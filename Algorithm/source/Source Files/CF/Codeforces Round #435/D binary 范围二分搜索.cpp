#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;
int n;
int s[1005];
int send(int begin, int end, int zero)
{
	for (size_t i = 0; i < 1005; i++)
	{
		s[i] = !zero;
	}


	for (int i = begin; i < end; i++)
	{
		s[i] = zero;
	}
	cout << "? ";
	for (int i = 0; i < n; i++)
	{
		cout << s[i];
	}
	cout << endl;
	fflush(stdout);
	int r = 0;
	cin >> r;
	r = n - r;
	return r;
}



int main()
{
	cin >> n;
	int cnt0 = send(0, n, 0);
	int cnt1 = n - cnt0;
	int i1 = send(1, n, 0);//i1用pos1代替会比较好

	if (i1 < cnt0)
	{
		i1 = 0;
	}
	else
	{
		i1 = 1;
		cnt0 = n - cnt0;
		cnt1 = n - cnt0;
	}

	int bg = 0, end = n;
	while (bg<end - 1)//结尾是合法元素后一个位置的二分
	{
		int mid = bg + (end - bg) / 2;
		int cur = send(bg, mid, !i1);
		//cnt0-cur 代表前半段全是0
		if (cnt0 - cur == mid - bg)
		{
			bg = mid;
		}
		else {
			end = mid;
		}
	}
	if (i1)
	{
		cout << "! " << bg + 1 << " " << 1 << endl;
	}
	else {
		cout << "! " << 1 << " " << bg + 1 << endl;
	}



	return 0;
}