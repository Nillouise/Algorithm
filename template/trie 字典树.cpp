#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxnode = 50000*100;
int ch[maxnode][2];
int val[maxnode];
int sz;//结点总数,就是记录ch的长度，要初始化为1!!!
void insert(string &s,int v)
{
    int u = 0;//0代表的是一个字符都没有的状态，也是代表结尾的状态。
    for(int i=0;i<s.size();i++){
        int cn = s[i] - 0;//注意这里要减去合适的前缀
        if(!ch[u][cn]){ 
            memset(ch[sz],0,sizeof(ch[sz]));
            val[sz] = 0; //这里存的是中间节点的信息
            ch[u][cn] = sz++;
        }
        u = ch[u][cn];
    }
    //注意这题可能会有重复的字符串。
    val[u] = v;//u这个node节点，应该代表的是字符串最后字母的结点
}

LL query(string &s)
{
    LL res = 0;
    int u = 0;
    for (int i = 0; i < s.size(); i++) {
        int cn = s[i] - 0;//注意这里要减去合适的前缀
        u = ch[u][cn];
        if(u==0){//这里是0代表无
            break;
        }
        res += val[u];//这里处理一段字符串的权。
    }
    //最后的判断式中的u，是代表字符串最后一个字符的节点。
    return res;
}