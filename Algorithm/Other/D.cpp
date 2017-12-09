#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

void ac(int n)
{
    // int n;
    // cin>>n;
    int ans=0;
    ans+=ceil(n*0.1)-floor(n*0.1);
    
    printf("%d ",ans);
    ans+=ceil(n*0.2)-floor(n*0.2);
    printf("%d ",ans);
    ans+=ceil(n*0.3)-floor(n*0.3);
    printf("%d\n",ans);
    
}

void wode(int n)
{
    string s;
       // int n;
       // cin>>n;
       int a = n%10;
       if(a)
       {
           cout<<"1 ";
       }else{
           cout<<"0 ";
       }
       if(a>5)
       {
           cout<<"2 ";
       }else if(a>0)
       {
           cout<<"1 ";
       }else{
           cout<<"0 ";
       }
       if(a>6)
       {
           cout<<"3"<<endl;
       }else if(a>3){
           cout<<"2"<<endl;
       }else if(a>0)
       {
           cout<<"1"<<endl;
       }else{
           cout<<"0"<<endl;
       }
}


int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    
    for (int i = 10; i <= 1000; i++) 
    {
        ac(i);
        wode(i);
        cout<<i<<endl;
    }


    return 0;
}
