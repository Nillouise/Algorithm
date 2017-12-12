#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int side1=0,side2=0;
    for (int i = 0; i < n; i++) 
    {
        int x,y;
        cin>>x>>y;
        if(x<0)
            side1++;
        if(x>0)side2++;
    }
    if(side1<=1||side2<=1)
    {
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    


    return 0;
}
