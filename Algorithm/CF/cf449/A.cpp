#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for (int i = 0; i < k; i++) 
    {
        int l,r;
        char c1,c2;
        cin>>l>>r>>c1>>c2;
        l--,r--;
        for (int i = l; i <=r; i++) 
        {
            if(s[i]==c1)s[i]=c2;
        }
        //cout<<s<<endl;
    }
    cout<<s<<endl;


    return 0;
}
