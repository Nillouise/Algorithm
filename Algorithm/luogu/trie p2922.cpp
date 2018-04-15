#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL M,N;
vector<int> msg[50000+100];
vector<int> ser[50000+100];

const int maxnode = 50000*100;
int ch[maxnode][2];
int val[maxnode];
int suf[maxnode];
int sz;//结点总数,就是记录ch的长度，要初始化为1
void insert(vector<int> &s,int v)
{
    int u = 0;//0代表的是一个字符都没有的状态
    for(int i=0;i<s.size();i++){
        int cn = s[i] - 0;//注意这里要减去合适的前缀
        if(!ch[u][cn]){ 
            memset(ch[sz],0,sizeof(ch[sz]));
            val[sz] = 0; //这里存的是中间节点的信息
            ch[u][cn] = sz++;
        }
        u = ch[u][cn];
        suf[u]+=v;
    }
    //注意这题可能会有重复的字符串。
    val[u] += v;//u这个node节点，应该代表的是字符串最后字母，内部并没有偏向性
}

LL query(vector<int> &s)
{
    LL res = 0;
    int u = 0;
    for (int i = 0; i < s.size(); i++) {
        int cn = s[i] - 0;//注意这里要减去合适的前缀
        u = ch[u][cn];
        if(u==0){//这里是0代表无
            break;
        }
        if(i!=s.size()-1)
            res += val[u];
        // cout<<i<<"lon "<<longest<<" res "<<res<<endl;//
    }
    //最后的判断式中的u，是代表字符串最后一个字符的节点。
    return res+(u==0?0:suf[u]);
}


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    sz=1;
    ios::sync_with_stdio(false);
    cin>>M>>N;
    for (int i = 0; i < M; i++) {
        int num;cin>>num;
        for (int j = 0; j < num; j++) {
            int x;cin>>x;
            msg[i].push_back(x);
        }
        insert(msg[i],1);
    }
    // int u = ch[0][1];
    // while(u!=0)
    // {
    //     cout<<"val "<<val[u]<<endl;
    //     u = ch[u][1];
    // }
    
    
    // cout<<"suf"<<suf[0]<<endl;//
    for (int i = 0; i < N; i++) {
        int num;cin>>num;
        for (int j = 0; j < num; j++){
            int x;cin>>x;
            ser[i].push_back(x);
        } 
        cout<<query(ser[i])<<endl;//
        // getchar();
    }
    
    
    
    return 0;
}