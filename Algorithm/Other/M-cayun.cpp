// https://www.nowcoder.com/acm/contest/51/M
//不知道为啥错了。
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL A[100000+10];
LL B[100000+10];
LL A3[10];
LL B3[10];
LL A7[10];
LL B7[10];
LL A21[30];
LL B21[20];

int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        for (int i = 0; i < n; i++) 
        {
            cin>>A[i];
            A3[A[i]%3]++;
            A7[A[i]%7]++;
            A21[A[i]%21]++;
        }
        for (int i = 0; i < m; i++) 
        {
            cin>>B[i];
            B3[B[i]%3]++;
            B7[B[i]%7]++;
            B21[B[i]%21]++;
        }
        LL total = 0;
        for (int i = 0; i < 3; i++) 
        {
            total+=A3[i]*B3[(3-i)%3];
        }
        for (int i = 0; i < 7; i++) 
        {
            total+=A7[i]*B7[(7-i)%7];
        }
        for (int i = 0; i < 21; i++) 
        {
            total -= A21[i]*B21[(21-i)%21];
        }
        cout<<total<<endl;
    }


    return 0;
}
