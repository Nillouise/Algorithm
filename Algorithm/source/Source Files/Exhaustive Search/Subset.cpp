#include<iostream>
#include<stdio.h>
using namespace std;

void zengliang(int *a,int cur,int length)
{
	for (size_t i = 0; i < cur; i++)
		cout << a[i];
	cout << endl;
	int begin = cur ?a[ cur - 1]+1 : 0;
	for (size_t i = begin; i < length; i++)
	{
		a[cur] = i;
		zengliang(a, cur + 1, length);
	}
}

void wei(int *a,int cur,int length)
{
	if (cur == length)
	{
		for (size_t i = 0; i < length; i++)
			if (a[i])cout << i;
		cout << endl;
		return;
	}
	else {
		a[cur] = 0;
		wei(a, cur + 1, length);
		a[cur] = 1;
		wei(a, cur + 1, length);
		return;
	}
}

void print_binary(int b,int len)
{
	for (size_t i = 0; i < len; i++)
		if (b& (1<<i))
			cout << i;
	cout << endl;
}
void binary(int len	)
{
	for (int i = 0; i < (1<<len); i++)
	{
		print_binary(i,len);
	}
}



int main()
{
	int a[10];
	zengliang(a, 0, 4);
	system("pause");
}