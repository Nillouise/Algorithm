//string.erase 的用法都不对。。
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

string cvt(string s,int wei)
{
    // cout<<s<<endl; //
    if(wei==0)return "0";
    while(s[0]=='0')
    {
        
        // cout<<"be"<<s<<endl;//
        s=s.erase(0,1);
        // cout<<"while"<<s<<endl;//
    }
    int pos = s.find('.');
    if(pos==s.npos){s=s+".";pos=s.size()-1;}
    
    int cnt = 0;
    while(pos>0)
    {
        swap(s[pos],s[pos-1]);
        pos--;
        cnt++;
    }
    // cout<<s<<endl;//
    while(s.size()<wei+200)s=s+"0";
    for(int i=1;i<s.size();i++)
    {
        if(s[i]!='0')
        {
            while(s.size()>wei&&s[1]=='0')
            {
                s.erase(1,1);
                cnt--;
            }
            break;
        }
    }
    
    // cout<<s<<endl;//
    // while(cnt<wei)
    // {
    //     cnt++;
    //     // s[0]=0;//这里写错了，不能这么写,搞得字符串都被截断了
    //     s[0]='0';
    //     s='.'+s;
    // }
    stringstream ss;
    ss<<cnt;
    string w;
    ss>>w;
    // cout<<w<<endl;//
    return "0."+s.substr(1,wei)+"*10^"+w;
}


int main()
{
    freopen("input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    int n;
    string s1,s2;
    cin>>n>>s1>>s2;
    string r1 = cvt(s1,n);
    string r2 = cvt(s2,n);
    if(r1!=r2)
    {
        cout<<"NO "<<r1<<" "<<r2<<endl;
    }else{
        cout<<"YES "<<r1<<endl;
    }
    // int pos1=0,pos2=0;
    // for(;pos1+1<s1.size();pos1++)if(s1[pos1+1]=='.')break;
    // for(;pos2+1<s2.size();pos2++)if(s2[pos2+1]=='.')break;
    // cout<<"pos1 "<<pos1<<" pos2 "<<pos2<<endl;//
    // 
    // if(pos1!=pos2)
    // {
    //     cout<<"NO "<<cvt(s1,n)<<" "<<cvt(s2,n)<<endl;
    //     return 0;
    // }
    // int flag=1;
    // int point=0;
    // for (int i = 0; i < n; i++) 
    // {
    //     if(s1[i]!=s2[i]){;flag=0;break;}
    // }
    // 
    // if(flag)
    // {
    //     cout<<"YES "<<cvt(s1,n)<<endl;
    // }else{
    //     cout<<"NO "<<cvt(s1,n)<<" "<<cvt(s2,n)<<endl;
    // }
        
    
    return 0;
}
