#include "Bracket.h"
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

char s[100];
int d[100][100];

int dfsBracket(int i,int j)
{
	if (i > j)
		return 0;
	if (i == j)
		return 1;
	if (d[i][j] != 10000)
		return d[i][j];

	if (s[j] == '(')
	{
		d[i][j] = dfsBracket(i, j-1) + 1;
		return d[i][j];
	}
	if (s[j] == ')')
	{
		for (int k = i; k < j; k++)
		{
			if(s[k]=='(')
				d[i][j] = min(d[i][j],dfsBracket(i , k-1)+dfsBracket(k+1,j-1) );
		}
		d[i][j] = min(d[i][j], dfsBracket(i,j-1) + 1);
		return d[i][j];
	}
	if (s[j] == '[')
	{
		d[i][j] = dfsBracket(i, j - 1) + 1;
		return d[i][j];
	}
	if (s[j] == ']')
	{
		for (int k = i; k < j; k++)
		{
			if (s[k] == '[')
				d[i][j] = min(d[i][j], dfsBracket(i, k - 1) + dfsBracket(k + 1, j-1));
		}
		d[i][j] = min(d[i][j], dfsBracket(i, j - 1) + 1);
		return d[i][j];
	}
	return 0;
}




int Bracket::run()
{
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			d[i][j] = 10000;
	string sBracket;
	cin >> sBracket;

	memcpy(s, sBracket.c_str(), sizeof(char)*sBracket.length());
	cout<< dfsBracket(0,sBracket.length()-1 );
	return 0;
}

