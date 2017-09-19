#include<iostream>  
using namespace std;

int n;     //��������  
int m;     //�һ�������  
int s;     //���е�s�ֻ���  
double v;  //���е�s���ҵı���  

int all;  //������  
double dis[101];  //s�������Ȩֵ  

class exchange_points
{
public:
	int a;      //����a  
	int b;      //����b  
	double r;   //rate  
	double c;   //������  
}exc[202];

bool bellman(void)
{
	memset(dis, 0, sizeof(dis));      //������bellman��Ŀ�ĸպ��෴����ʼ��ΪԴ�㵽�����������С  
	dis[s] = v;                       //��bellman�������Ҹ���������С·��������������ͬ����˼���������������·��  

									  /*relax*/

	bool flag;
	for (int i = 1; i <= n - 1; i++)
	{
		flag = false;
		for (int j = 0; j<all; j++)
			if (dis[exc[j].b] < (dis[exc[j].a] - exc[j].c) * exc[j].r)         //Ѱ���·��  
			{                                                                 //���бȽϵ���"ĳ�㵽�����Ȩֵ"��"ĳ�㵽��һ���Ȩֵ"  
				dis[exc[j].b] = (dis[exc[j].a] - exc[j].c) * exc[j].r;
				flag = true;
			}
		if (!flag)
			break;
	}

	/*Search Positive Circle*/

	for (int k = 0; k<all; k++)
		if (dis[exc[k].b] < (dis[exc[k].a] - exc[k].c) * exc[k].r)           //�����ܹ������ɳ�  
			return true;

	return false;
}

int main(void)
{
	int a, b;
	double rab, cab, rba, cba;   //��ʱ����  

	while (cin >> n >> m >> s >> v)
	{
		all = 0;    //ע���ʼ��  
		for (int i = 0; i<m; i++)
		{
			cin >> a >> b >> rab >> cab >> rba >> cba;
			exc[all].a = a;
			exc[all].b = b;
			exc[all].r = rab;
			exc[all++].c = cab;
			exc[all].a = b;
			exc[all].b = a;
			exc[all].r = rba;
			exc[all++].c = cba;
		}

		/*Bellman-form Algorithm*/

		if (bellman())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}