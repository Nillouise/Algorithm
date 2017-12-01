#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);

    string s;
    cin>>s;
    vector<string> vec;
    vec.push_back("Danil");
    vec.push_back("Olya");
    vec.push_back("Slava");
    vec.push_back("Ann");
    vec.push_back("Nikita");
    int cnt=0;
    for(auto a:vec)
    {
        string ss = s;
        int pos=0;//while的判断头不能声明变量，一定要在这里声明
        while((pos=ss.find(a))!=s.npos)
        {

                 ss=ss.substr(pos+a.size(),s.size());//这里要ss=ss才会更新ss的值
                 cnt++;
        }

    }
    if(cnt==1)
    {
        cout<<"YES"<<endl;
    }else{
    cout<<"NO"<<endl;
    }

    return 0;
}
