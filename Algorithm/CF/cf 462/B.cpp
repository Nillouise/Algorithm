#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int data[10]={1,0,0,0,1,0,1,0,2,1};


int main()
{
    //freopen("D:\\Project\\Algorithm\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int k;
    cin>>k;
    string s;
    while(k)
    {
        if(k==1)
        {
            s+="6";
            k--;
        }else{
            s+="8";
            k-=2;
        }
        if(s.size()>=18)break;
    }
    if(k)
    {
        cout<<-1<<endl;
    }else{
        cout<<s<<endl;
    }
    
    
    return 0;
}
