//这是错的

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int a[100000 + 5];
int one[100000 + 5];

int dfs(int b, int e, int curbit, vector<int> arr, int inverse)
{
	if (curbit >= arr.size())return 0;
	if (b == e)return 0;
	//if (b == e - 1)return 0; 错的

	if (inverse == 0)
	{
		for (size_t i = b; i < b + arr[curbit]; i++)
		{
			a[i] = a[i] | (1 << curbit);
		}
	}
	else {
		//for (size_t i = b + arr[curbit]-1; i >= b ; i--)
		for (int i = b + arr[curbit] - 1; i >= b; i--)
		{
			a[i] = a[i] | (1 << curbit);
		}
	}

	vector<int> arr1(arr);
	vector<int> arr2(arr);

	for (size_t i = 0; i < arr.size(); i++)
	{
		if (inverse == 0)
		{
			arr1[i] = arr1[i] / 2;
			arr2[i] = arr2[i] / 2 + arr[i] % 2;
		}
		else {
			arr1[i] = arr1[i] / 2 + arr[i] % 2;
			arr2[i] = arr2[i] / 2;
		}

		//arr2[i] /= 2 + arr[i] % 2;//这里错了
	}
	int mid = b + (e - b) / 2;
	dfs(b, mid, curbit + 1, arr1, !inverse);
	//dfs(mid + 1, e, curbit + 1, arr2);错的
	if (mid == b)return 0;
	dfs(mid, e, curbit + 1, arr2, !inverse);
	return 0;
}


int main()
{
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	int n, x;
	cin >> n >> x;
	int t = x;
	vector<int> arr;
	for (int i = 0; t; i++)
	{
		t /= 2;
		if ((1 << i)&x)
		{
			one[i] = n / 2 - (n / 2) % 2 + 1;
		}
		else {
			one[i] = n / 2 - (n / 2) % 2;
			//one[i] = n / 2+ n%2;
			//one[i] = n / 2;
		}
		arr.push_back(one[i]);
	}
	dfs(0, n, 0, arr, 0);
	sort(a, a + n);
	for (size_t i = 1; i < n; i++)
	{
		if (a[i] == a[i - 1])
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	for (size_t i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}