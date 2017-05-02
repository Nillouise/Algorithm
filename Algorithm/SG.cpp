//喵哈哈村的代码传说 第五章 找规律
//发布时间 : 2017年3月11日 16 : 04   最后更新 : 2017年3月11日 16 : 04   时间限制 : 1000ms   内存限制 : 128M
//
//	描述
//	桌面上有n组牌，每组牌有a[i]个扑克，两个玩家轮流拿扑克，谁拿到最后一张扑克，谁就胜利了。
//
//	但是这个规矩有点奇怪：他们可以选择一堆拿任意多的扑克牌，或者选择使得某一堆扑克牌变成三堆任意大小的扑克牌。
//
//	请问如果两个人都非常机智的话，谁能获胜呢？
//
//	输入
//	第一行包括数据组数T，表示测试数据组数。
//	接下来T组测试数据：
//	第一行一个n，表示有n组牌。
//	第二行n个数字a[i]，表示每组牌的数量。
//
//	保证n <= 1000000, a[i] <= 1e9
//
//	输出
//	第一个人胜利输出First player wins.
//	第二个人胜利输出Second player wins.
//多校原题。Sg函数的裸题。
//
//sg[0] = 0
//
//当x = 8k + 7时sg[x] = 8k + 8，
//
//当x = 8k + 8时sg[x] = 8k + 7,
//
//其余时候sg[x] = x；（k >= 0）
//http://www.cnblogs.com/qscqesze/p/6537820.html
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
	int T, n;
	scanf("%d", &T);
	while (T--)
	{
		int ans = 0;
		scanf("%d", &n);
		for (int i = 0; i<n; i++)
		{
			int x, sg;
			scanf("%d", &x);
			if (x % 8 != 0 && x % 8 != 7)
				sg = x;
			else
				if (x % 8 == 0) sg = x - 1; else sg = x + 1;
			ans ^= sg;
		}
		if (ans) printf("First player wins.\n"); else printf("Second player wins.\n");
	}
	return 0;
}