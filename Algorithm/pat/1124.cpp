#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    
    int n,m,k;
    cin>>n>>m>>k;
    set<string> but;
    int cnt = 0;
    int pre = k;
    for (int i = 1; i <= n; i++) 
    {
        string s;
        cin>>s;
        if(i==k|| i-pre >=m)
        {
            if(but.find(s)==but.end())
            {
                but.insert(s);
                cout<<s<<endl;
                pre = i;
            }
        }
    }
    if(but.size()==0)
    {
        cout<<"Keep going..."<<endl;
    }
    


    return 0;
}
