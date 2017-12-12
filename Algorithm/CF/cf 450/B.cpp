#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
//    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    set<int> but;
    int a,b,c;
    cin>>a>>b>>c;
    int cnt = 0;
    int flag=1;
    a=a%b;
    a*=10;
    while(true)
    {

        // while(a<b)
        // {
        //     if(c==0)goto fin;
        //     cnt++;
        //     a*=10;
        // }
        if(a/b==c)break;
        if(a>=b)
        {
            a=a%b;
        }
        a*=10;
        cnt++;
        int d = a%b;
        if(but.find(d)!=but.end())
        {
            flag=0;
            break;
        }else{
            but.insert(d);
        }

    }
    
    fin:
    if(flag)
    {
        cout<<cnt+1<<endl;
    }else{
        cout<<-1<<endl;
    }


    return 0;
}
