#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
 
 
 
 
int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
  //  freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//
 
    ios::sync_with_stdio(false);
 
    int n;
    cin>>n;
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
     
    return 0;
}
