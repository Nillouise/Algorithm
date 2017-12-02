#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int G1[2300];
int G2[2300];
int C[2300];

int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    
    int T;
    cin>>T;
    while(T--)
    {
        memset(C,0,sizeof(C));
        memset(G1,0,sizeof(G1));
        memset(G2,0,sizeof(G2));
        int n;
        cin>>n;
        int flag=1;
        for (int i = 0; i < n; i++) 
        {
            int a;
            cin>>a;//这里负责吃光所有数据
            if(C[a]==1 || G1[i+a+1]==1||G2[((i+1)-(a)+n)]==1)
            {
                flag=0;
                // break;//这里不能break，因为要吃光自己的数据才行的
            }
            C[a] = 1;
            G1[i+a+1]=1;
            G2[((i+1)-(a)+n)]=1;
        }
        if(flag)
        {
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    
    


    return 0;
}
