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
    set<int> but;
    for (int i = 0; i < n; i++) 
    {
        int a;
        int fri=0;
        cin>>a;
        while(a)
        {
            fri+=a%10;
            a/=10;
        }
        but.insert(fri);
    }
    cout<<but.size()<<endl;
    int i = 0;
    for(auto a:but)
    {
        cout<<a;
        if(i!=but.size()-1)cout<<" ";
        i++;
    }

    return 0;
}
