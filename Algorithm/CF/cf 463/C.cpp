#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    //freopen("D:\\Project\\Algorithm\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int N,A,B;
    cin>>N>>A>>B;
    int x=0,y=0;
    int flag= 0;
    for(int i=0;;i++)
    {
        if(N-i*A<0)break;
        if(((N-i*A)%B)==0)
        {
            x = i;
            y = (N-i*A)/B;
            flag=1;
            break;
        }
    }
    // cout<<"A "<<x<<" B "<<y<<endl;
    if(!flag)return cout<<-1<<endl,0;
    
    for(int i=0;i<x;i++)
    {
        for(int j=1;j<A;j++)
        {
            cout<<i*A+j+1<<" ";
        }
        cout<<i*A+1<<" ";
    }
    for(int i=0;i<y;i++)
    {
        for(int j= 1;j<B;j++)
        {
            cout<<x*A + i*B+j+1<<" ";
        }
        cout<<x*A+i*B+1<<" ";
    }
    
    
    return 0;
}
