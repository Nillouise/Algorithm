#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


int dat[1000000+10];

void add(int x,int gap)
{
    for (int i = x; i <= 1000000; i=i+(i&(-i))) {
        dat[i]+=gap;
    }
}

int get(int l,int r)
{
    if(l>r)return 0;
    if(l<1)l=1;
    int suf=0,pre = 0;
    for (int i = r; i >0; i=i-(i&(-i))) {
        suf+=dat[i];
    }
    for (int i = l-1; i >0; i=i-(i&(-i))) {
        pre+=dat[i];
    }
    return suf-pre;
}


int main()
{
    // freopen("I:\Project\acm\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> dat(n);
    for (int i = 0; i < n; i++) {
        cin>>dat[i];
        add(dat[i],1);
    }
    sort(dat.begin(),dat.end());
    
    int be=0,cut=0,cnt=0,prej=0;
    for (int i = 0; i < n; i++) {
        int a = get(dat[i]-m+1,dat[i]);
        if(a>=k)
        {
            add(dat[i],-1);
            cnt++;
        }
    }
    cout<<cnt<<endl;
    
    
    return 0;
}