#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
vector<string> d1,d2;
void verti()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            swap( d1[i][j],d2[n-i-1][j]);
        }
    }
}
    


void hor()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            swap(d1[i][j],d2[i][n-j-1]);
        }
    }
}


int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);

    cin>>n;
    d1.resize(n);d2.resize(n);
    for (int i = 0; i < n; i++) {
        cin>>d1[i];
    }
    for (int i = 0; i < n; i++) {
        cin>>d2[i];
    }
    for(int k = 0;k<8;k++)
    {
        if(k==1)verti();
        if(k==2)verti(),hor();
        if(k==3)verti();
        
        
        int flag = 1;
        //正常比
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(d1[i][j]!=d2[i][j]){
                    flag=0;
                    break;
                }
            }
            if(flag==0)break;
        }
        if(flag==1)
        {
            cout<<"Yes"<<endl;
            return 0;
        }
        //左右翻转
        flag=1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(d1[i][j]!=d2[i][n-j-1]){
                    flag=0;
                    break;
                }
            }
            if(flag==0)break;
        }
        if(flag==1)
        {
            cout<<"Yes"<<endl;
            return 0;
        }
        
        //上下翻转
        flag=1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(d1[i][j]!=d2[n-i-1][j]){
                    flag=0;
                    break;
                }
            }
            if(flag==0)break;
        }
        if(flag==1)
        {
            cout<<"Yes"<<endl;
            return 0;
        }
        //90度
        flag=1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(d1[i][j]!=d2[j][i]){
                    flag=0;
                    break;
                }
            }
            if(flag==0)break;
        }
        if(flag==1)
        {
            cout<<"Yes"<<endl;
            return 0;
        }
        //180度
        flag=1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(d1[i][j]!=d2[n-i-1][ n-j-1]){
                    flag=0;
                    break;
                }
            }
            if(flag==0)break;
        }
        if(flag==1)
        {
            cout<<"Yes"<<endl;
            return 0;
        }
        //270度
        flag=1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(d1[i][j]!=d2[n-j-1][i]){
                    flag=0;
                    break;
                }
            }
            if(flag==0)break;
        }
        if(flag==1)
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }

    cout<<"No"<<endl;//
    
    return 0;
}