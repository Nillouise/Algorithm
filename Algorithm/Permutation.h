#pragma once
//set permutation m 's number,and run it ,print the m permutation
class Permutation
{
public:
	Permutation();
	void run();
	int m;
	~Permutation();
};

int invoke()
{
	Bracket m;
	char a[10] = { ')','(','[',')',']' };
	cout << m.run(5, a);
	return 0;
}