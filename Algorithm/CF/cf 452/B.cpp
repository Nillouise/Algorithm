#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int a[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int b[12] = {31,29,31,30,31,30,31,31,30,31,30,31};



int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int>dat(n);
    for (int i = 0; i < n; i++) 
    {
        cin>>dat[i];
    }
    int flag=0;
    for (int i = 0; i < 12; i++) 
    {
        int flag2 = 1;
        for (int j = i; j < 12&&j-i<n; j++) 
        {
            if(dat[j-i]!=a[j])
            {
                flag2=0;
                break;
            }
        }
        if(flag==1){
            flag=1;
            break;
        }
    }
    for (int i = 0; i < 12; i++) 
    {
        int flag2 = 1;
        for (int j = i; j < 12&&j-i<n; j++) 
        {
            if(dat[j-i]!=b[j])
            {
                flag2=0;
                break;
            }
        }
        if(flag2==1){
            flag=1;
            break;
        }
    }
    if(flag)
    {
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    return 0;
}
