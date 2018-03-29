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
    vector<int> dat(3,0);
    for (int i = 0; i < n; i++) 
    {
        int a;
        cin>>a;
        dat[a]++;
    }
    if(dat[1]<=dat[2])
    {
        cout<<dat[1]<<endl;
    }else{
        cout<<dat[2] + (dat[1]-dat[2])/3<<endl;
    }
    

    return 0;
}
