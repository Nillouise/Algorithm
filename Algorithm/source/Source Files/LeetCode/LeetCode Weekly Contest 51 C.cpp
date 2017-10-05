#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;



int main()
{
	vector<vector<int>> edges;

	vector<vector<int>>fa(edges.size());
	for (size_t i = 0; i < edges.size(); i++)
	{
		fa[edges[i][1]].push_back(edges[i][0]);
	}
	int twofa = -1;

	for (int i = 0; i < fa.size(); i++)
	{
		if (fa[i].size() > 1)twofa = i;
	}

	if (twofa != -1)
	{
		vector<int> r;
		r.push_back(twofa);
		r.push_back(fa[twofa][0]);
		return r;
	}
	else {
		int pre = -1;
		int cur = edges[0][0];
		while (true)
		{
			int next = fa[fa[cur][0]][0];
			if (next == pre)
			{
				vector<int> r;
				r.push_back(cur);
				r.push_back(fa[cur][0]);
				return r;
			}
			else {
				pre = fa[cur][0];
			}
		}
	}



	return 0;
}