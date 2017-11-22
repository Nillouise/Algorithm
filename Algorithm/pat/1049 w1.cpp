//
//正确的cmp解法，因为他们带有交换性质（交换可以贪心）

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
string data[10002];
vector<string> data2(10002);//不知道为啥测评不能通过这么大的vector,垃圾

//正确的cmp解法，因为他们带有交换性质（交换可以贪心）
bool cmp2(const string &a,const string &b) {
    return (a + b) < (b + a);
}


bool cmp(const string& s1,const string& s2)
{
    int len = min(s1.size(),s2.size());
    for (int i = 0; i < len; i++) 
    {
        if(s1[i]<s2[i])return true;
        else if(s1[i]>s2[i])return false;
    }
    if(s1.size()==s2.size())return true;
    if(s1.size()>s2.size())
    {
        if(s1[len]>s1[0])return false;
        else return true;
    }else{
        if(s2[len]>s2[0])return true;
        else return false;
    }
}

int main()
{
    freopen("input.txt","r",stdin);//

    // ios::sync_with_stdio(false);
    if(!(cin>>n))return 0;
    // data.resize(n);
    for (int i = 0; i < n; i++) 
    {
        cin>>data[i];
    }
    sort(data,data+n,cmp);
    string ans="";
    for (int i = 0; i < n; i++) 
    {
        if(data[i].size()>0)
        ans+=data[i];
    }
    // reverse(ans.begin(),ans.end());
    string ans2="";
    int flag=0;
    // cout<<ans<<endl; //
    for (int i = 0; i < ans.size(); i++) 
    {
        if(ans[i]=='0'&&flag==0)
        {
            continue;
        }
        flag=1;
        // ans2+=ans[i];//这里的方向要注意
        ans2=ans[i]+ans2;
    }
    
    if(ans2.size()==0)return cout<<"0"<<endl,0;
    reverse(ans2.begin(),ans2.end());
     cout<<ans2<<endl;
    
    
    return 0;
}
