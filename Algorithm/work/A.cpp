#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

void cal(int x)
{
    if(x==0)
    {
        cout<<"*";
    }else{
        cout<<"*";
        for(int i=0;i<(x-1)*2+1;i++)
        {
            cout<<".";
        }
        cout<<"*";
    }
    
    
}

int main()
{
    //freopen("I:\\Project\\acm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            cout<<".";
        }
        cal(i);
        cout<<endl;
    }
    for(int i=0;i<(2*n-1);i++)
    {
        cout<<"*";
    }
    cout<<endl;
    
    
    return 0;
}