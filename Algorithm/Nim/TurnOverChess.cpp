﻿//翻棋子游戏：
//
//
//题意：一个棋盘上每个格子有一个棋子，每次操作可以随便选一个朝上的棋子(x, y)，代表第i行第j列的棋子，选择一个形
//如(x, b)或(a, y)(其中b < y，a < x)的棋子，然后把它和(x, y)一起翻转，无法操作的人输。
//
//
//	分析：把坐标为(x, y)的棋子看成大小分别为x和y的两堆石子，则本题转化为了经典的Nim游戏，如果难以把棋子看作石
//	子，可以先把Nim游戏中的一堆石子看成一个正整数，则Nim游戏中的每次操作是把其中一个正整数减小或者删除。
//
//
//	抱歉貌似看错题目了....
//	刚才YY的貌似只有将反面的翻成正面的...如果将正面的翻成反面的话，设这个正面的是(a, y)((x, b)类似)。
//	将(x, y)和(a, y)翻下去，我们就失去了 石子数分别为 x, y, y, a的四个石子堆。
//	设原来所有石子堆的异或和是W，那么操作之后的异或和应该是 W xor a xor y xor x xor y = W xor a xor x, 也就是说翻(x, y) (a, y)会使 异或和W 变成 W xor a xor x，而原来 翻一个正面翻一个反面 异或和的变化值 显然也是 W xor a xor x，也就是说确定(x, y)和(a, y)之后，无论(a, y)是正面还是反面，它对异或和的影响都是相同的，所以选定一个 （x, y）之后，另外一个棋子的正反是不影响结果的....
//	所以全部正面朝上的情况，就是 把所有的坐标都看作石子堆就可以了....