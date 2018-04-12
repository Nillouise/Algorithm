#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL game[10000+100][4];
LL dat[10000+100];

int getm(int x)
{
    int res=0;
    for(int i=0;i<3;i++)if((1<<i)&x)res++;
    return res;
}





int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    for (int i = 0; i < N; i++) {
        cin>>dat[i];
    }
    int ans = 0 ;
    int flag = 1;
    int prec = 0,c = 0;
    for (int i = 1; i < N; i++) {
        int nc = dat[i-1]-prec-c;
        if(nc!=0&&nc!=1){
            flag= 0;
            break;
        }
        prec = c;
        c = nc;
    }
    if(flag==1&&prec+c == dat[N-1])ans++;//注意，有头尾两端的话，特例也要想一想头尾两端
    flag=1;
    
    prec = 0,c = 1;
    for (int i = 1; i < N; i++) {
        int nc = dat[i-1]-prec-c;
        if(nc!=0&&nc!=1){
            flag= 0;
            break;
        }
        prec = c;
        c = nc;
    }
        if(flag==1&&prec +c==dat[N-1])ans++;
        cout<<ans<<endl;
    
    return 0;
}