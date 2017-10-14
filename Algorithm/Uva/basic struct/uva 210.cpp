#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<queue>
using namespace std;
typedef long long LL;

int N, A, O, B, E, S, Quan;
deque<int> readyQ;
queue<int> blockQ;
vector<string> vs;
int pe[1000];
int pc[1000];
int var[1000];
int mut[1000];
int lock = 0;
void run(int pid)
{
	int total = 0;

	while (total<Quan)
	{
		string cs = vs[pc[pid]];
		switch (cs[2])
		{
		case '=':
			var[cs[0]] = stoi(cs.substr(4));
			total += A;
			break;
		case 'i':
			cout << pid + 1 << ": " << var[cs[6]] << endl;
			total += O;
			break;
		case 'c':
			if (lock)
			{
				blockQ.push(pid);
				return;
			}
			lock = 1;
			total += B;
			break;
		case 'l':
			lock = 0;
			if (!blockQ.empty())
			{
				int cid = blockQ.front();
				blockQ.pop();//对队列有点生疏了，一开始都忘记了拿了数据就要删除掉他了
				readyQ.push_front(cid);
			}
			total += E;
			break;
		case 'd':
			return;
		}
		pc[pid]++;
	}
	readyQ.push_back(pid);
}


int main()
{
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		//忘记acm跟cf有点不一样，多样例要清空数据的
		memset(var, 0, sizeof(var));
		vs.clear();
		cin >> N >> A >> O >> B >> E >> S >> Quan;//这里留了一个空行，需要多一个getline吃掉
		string es;
		getline(cin, es);
		for (int i = 0; i<N; i++)
		{
			pc[i] = vs.size();
			for (string s; getline(cin, s);)//这里只需要个getline，只有cin>>数字等之后才会留一个空行
			{
				vs.push_back(s);
				pe[i] = vs.size();
				if (s[2] == 'd')break;
			}
			readyQ.push_back(i);
		}

		while (!readyQ.empty())
		{
			int p = readyQ.front();
			readyQ.pop_front();
			run(p);
		}
		if (T)cout << endl;

	}






	return 0;
}
