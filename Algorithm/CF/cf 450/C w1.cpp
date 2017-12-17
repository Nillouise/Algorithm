#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int dat[100000+10];
int tree[100000+10];
int n;
int get(int l,int r)
{
    if(l>r)return 0;
    int pre=0,suf=0;
    for (int i = l-1; i > 0; i=i-(i&(-i))) 
    {
        pre+=tree[i];
    }
    for (int i = r; i > 0; i=i-(i&(-i))) 
    {
        suf+=tree[i];
    }
    return suf-pre;
    
}
int add(int l)
{
    for (int i = l; i <= n; i=i+(i&(-i))) 
    {
        tree[i]++;
    }
}

int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    
    cin>>n;
    if(n==1||n==2)return cout<<1<<endl,0;
    for (int i = 1; i <= n; i++) 
    {
        cin>>dat[i];
    }
    int MAX=0;
    int flag=0;
    int maxi=0;
    for (int i = n; i >0; i--) 
    {
        int c = get(1,dat[i]-1);
        // cout<<dat[i]<<" "<<c<<endl;//
        if(c>MAX||flag==0)
        {
            flag=1;
            MAX=c;
            maxi=dat[i];
        }else if(c==MAX&&maxi>dat[i]){
            maxi=dat[i];
        }
        add(dat[i]);
    }
    cout<<maxi<<endl;

    return 0;
}
