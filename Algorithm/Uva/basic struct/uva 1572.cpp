#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
map<string,set<string> > G;
map<string,int> vis;
int topo(string s)
{
    vis[s]=-1;
    for(auto a:G[s])
    {
        if(vis[a]==-1)
        {
            return -1;
        }
        if(vis[s]==1)continue;
        if(topo(a)==-1)return -1;
    }
    vis[s]=1;
    return 0;
}
//这里要invert，替换一下，这是最难点了吧。
string invert(string s)
{
    string rs=s;
    //这里的不可以用'-'，这样会完全当成是整数,这里完全不行呀，会让s[0]是一个整数的。
//    if(s[1]=='+')rs=s[0]+"-";
//    if(s[1]=='-')rs=s[0]+"+";
    if(s[1]=='+')rs[1]='-';
    if(s[1]=='-')rs[1]='+';


 //   cout<<"s"<<s<<"rs"<<rs<<endl; //
    return rs;
}

int add(vector<string> vec)
{
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i]=="00")continue;
        for(int j=0;j<vec.size();j++)
        {
            if(vec[j]=="00")continue;
            if(i==j)continue;
            G[vec[i]].insert(invert(vec[j]));

        }
    }
    return 0;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(cin>>n)
    {
        vis.clear();
        G.clear();


    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        string s1=s.substr(0,2),s2=s.substr(2,2),s3=s.substr(4,2),s4=s.substr(6,2);
        vector<string> vec;
        vec.push_back(s1);
        vec.push_back(s2);
        vec.push_back(s3);
        vec.push_back(s4);
        add(vec);


    }
    int flag=0;

    //
//    for(auto a:G)
//    {
//        cout<<a.first<<" ";
//       for(auto b:a.second)
//        {
//            cout<<b<<" ";
//        }
//        cout<<endl;
//    }


    for(auto a:G)
    {
        //是a.first而不是a->first
        if(vis[a.first]==0)
        {
            if(topo(a.first)==-1)
            {
                flag=1;
                break;
            }
        }
    }
    if(flag==1)
    {
        cout<<"unbounded"<<endl;
    }else{
        cout<<"bounded"<<endl;
    }
    }
    return 0;
}
