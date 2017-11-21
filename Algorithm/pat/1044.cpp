//暧昧之处很多的垃圾题目，不过至少教会我枚举时间去做这种题（还有就是同一时间可能有多个操作）
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m,mv;

struct Token
{
    int start;
    int ser;
    string s;
    int vip;
    int wait;
    bool operator < (const Token& t)const
    {

        return start<t.start;
    }
};

bool cmp(const Token &t1,const Token &t2)
{
    if(t1.start+t1.wait==t2.start+t2.wait)
    {
        return t1.wait<t2.wait;
    }else{
        return t1.start+t1.wait<t2.start+t2.wait;
    }
}
Token data[200];
int vip[200];
int nxt[200];//next 被stl用了
int num[200];
int cvt(string s)
{
    stringstream ss(s);
    int h,m,se;
    char c;
    ss>>h>>c>>m>>c>>se;
    
    return h*3600+m*60+se;
}

string cvt2(int x)
{
    int se = x%60;
    x/=60;
    int m= x%60;
    char cs[80];
    sprintf(cs,"%02d:%02d:%02d",x/60,m,se);
    string r(cs);
    return r;
}
deque<Token> Qori;//用deque是因为我代码用了push_front 去撤销一些操作
deque<Token> Qvip;

Token getQ()
{
    Token ct;
    if(Qori.empty())
    {
        ct=Qvip.front();Qvip.pop_front();
    }else if(Qvip.empty())
    {
        ct=Qori.front();Qori.pop_front();
    }else{
        if(Qori.front()<Qvip.front())
        {
            ct = Qori.front();
            Qori.pop_front();
        }else{
            ct = Qvip.front();
            Qvip.pop_front();
        }
    }
    return ct;
}

void pushQ(Token t)
{
    if(t.vip==1)
        Qvip.push_front(t);
    else
        Qori.push_front(t);
}
int myup(int x)
{
    int t= x/60;
    if(x%60)t++;
    return t;
}
int main()
{
    freopen("input.txt","r",stdin);//

    ios::sync_with_stdio(false);

    cin>>n;
    for (int i = 0; i < n; i++) 
    {
        string s;
        cin>>s;
        Token t;
        t.s=s;
        t.start = cvt(s);
        cin>>t.ser;
        t.ser*=60;//这里分钟转成秒
        cin>>t.vip;
        data[i]=t;
    }
    cin>>m>>mv;
    for (int i = 0; i < mv; i++) 
    {
        int a;
        cin>>a;
        a--;
        vip[a]=1;
    }
    sort(data,data+n);
    for (int i = 0; i < n; i++) 
    {
        if(data[i].vip==1)
            Qvip.push_back(data[i]);
        else
            Qori.push_back(data[i]);
    }
    
    vector<Token> ans;
    //九点整好像打不了球（看数据算的）
    //这样写有个陷阱就是，一个时间可以有同时几个人进场，而这里只假设了一个人进场。。。
    for (int i = 8*3600; i <21*3600; i++) 
    {
        if(Qvip.empty()&&Qori.empty())break;
        
        while(true)
        {
            int ni= -1;
            int flag=0;
            for (int j = 0; j < m; j++) 
            {
                if(nxt[j]<=i)
                {
                    ni=j;
                    flag=1;
                    break;
                }
            }
            if(flag==0)break;
            
            Token ct;
            if(vip[ni]==1)
            {
                if(!Qvip.empty()&&Qvip.front().start<=i)
                {
                    ct=Qvip.front();Qvip.pop_front();
                }else if(!Qori.empty()&&Qori.front().start<=i){
                    ct=Qori.front();Qori.pop_front();
                }else{
                    break;
                }
            }else{
                ct=getQ();
                if(ct.start>i){
                    pushQ(ct);
                    break;
                }
            }
    //        cout<<"ni"<<ni<<" "<<nxt[ni]<<endl;//
            
            num[ni]++;
            nxt[ni]=i+ct.ser;
            ct.wait=i-ct.start;
            ans.push_back(ct);            
        }

    }
    sort(ans.begin(),ans.end(),cmp);
    for(auto a:ans)
    {
        cout<<a.s<<" "<<cvt2(a.start+a.wait)<<" "<<myup(a.wait)<<endl;
    }
    
    for(int i=0;i<m;i++)
    {
        cout<<num[i];
        if(i!=m-1)cout<<" ";
    }
    cout<<endl;

    
    

    return 0;
}
