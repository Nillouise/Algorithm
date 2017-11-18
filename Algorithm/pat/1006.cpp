//这题我犯了一个很耗时间debug的错误，我把吃字符的char错写成int了，导致转出来的时间不正确（太大），导致读out of bound，而且吊诡的是，out of bound
//居然没有输出溢出，只是像正常一样退出（在outofbound 时退出）。不知道ide能不能提出这种out of bound 的错误
//还有一个问题时我没看数据就写题，理解错了题意。
//这是一辆车最多会停留多久的时间，而不是一次停留多久。
//这题感觉也挺有病，不做了
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int vis[3600*25+100];
struct Token
{
    string name;
    string stime;
    int rtime;
    string status;
    bool operator < (const Token &t)const
    {
//        cout<<"compare";//
        return rtime<t.rtime;
    }
};
int cvt(string s)
{
    stringstream ss(s);
    int h,m,se;
    char c;
    ss>>h>>c>>m>>c>>se;

    
    return h*3600+m*60+se;
    
}

int main()
{
    freopen("input.txt","r",stdin);//
    ios::sync_with_stdio(false);
    
    
    int n,m;
//    cout<<"ok";//
    cin>>n>>m;
//    cout<<"OK";//
    vector<Token> vec;
    
    for (int i = 0; i < n; i++) {
        Token t;
        cin>>t.name>>t.stime>>t.status;
        t.rtime = cvt(t.stime);
        vec.push_back(t);
//                cout<<"i"<<i;//
//        cout<<t.rtime<<endl;//
        
        sort(vec.begin(),vec.end());//
    }
    sort(vec.begin(),vec.end());
    
    map<string,int> gap;
    map<string,int> pre;
    map<string,bool> noig;//noignore
    for(auto a:vec)
    {
        if(a.status=="in")
        {
            pre[a.name]=a.rtime;
        }else
        {
            if(pre.find(a.name)!=pre.end())
            {
                gap[a.name] = a.rtime-pre[a.name];
                noig[a.name]=1;
            }
        }
    }
    
    int ct =0;
    int ccnt=0;
    for(auto a:vec)
    {
        if(noig[a.name]==1)
        {
            if(a.status=="in")
            {
                ccnt++;
            }else{
                ccnt--;
            }
            int j;
            for(j=ct;j<a.rtime;j++)
            {
                vis[j]=vis[ct];
            }
            vis[a.rtime]=ccnt;
            ct=a.rtime;
        }
    }
    for(int i=ct;i<25*3600;i++)
    {
        vis[i]=vis[ct];
    }
    
    for(int i=0;i<m;i++)
    {
        string s;
        cin>>s;
        int t = cvt(s);
        cout<<vis[t]<<endl;
        
    }
    
    
    
    int MAX=0;
    for(auto a:gap)
    {
        if(a.second>MAX)MAX=a.second;
    }
    vector<string> ans;
    for(auto a:gap)
    {
        if(a.second==MAX)
            ans.push_back(a.first);
    }
    
    for(auto a:ans)
    {
        cout<<a<<" ";
    }
    cout<<MAX/3600<<":";
    MAX%=3600;
    cout<<MAX/60<<":";
    cout<<MAX%60<<endl;
    
    return 0;
}
