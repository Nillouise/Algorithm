//这题被字面值 不是long long坑死了
#include <iostream>
#include<vector>
#include<string>
#include<cstring>
#include <algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);

	long long a, b,c;
	while(cin>>a>>b>>c)
	{
		long long res = 0;
		res += a*b*c;
		cout << res << endl;//
	}


	return 0;
}
