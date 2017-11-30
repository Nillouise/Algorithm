//卧槽要看输出要求呀，是Yes不是YES
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);

    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        stringstream ss(s.substr(0,s.size()/2));
        LL a;
        ss>>a;
        stringstream ss2(s.substr(s.size()/2,s.size()/2));
        LL b;
        ss2>>b;
        if(b==0)
        {
            cout<<"No"<<endl;
            continue;
        }
        LL z;
        stringstream ss3(s);
        ss3>>z;
        if(z%(a*b)==0)
        {
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
        
        
    }


    return 0;
}
