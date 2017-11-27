//放弃这题吧，用来理解的材料质量太低了

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


int main()
{
    // freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    int a[10] = {6 ,7, 4, 5, 0, 1, 8, 9 ,2 ,3};
    
    int b[10];
    for (int i = 0; i < 10; i++) {
        b[a[i]]=i;
    }
    for (int i = 0; i < 10; i++) {
        cout<<b[i]<<" ";
    }
    cout<<endl;
    
    for (int i = 0; i < 10; i++) {
        cout<<(a[0]^b[i])<<" ";
    }
    cout<<endl;
    for (int i = 0; i < 10; i++) {
        cout<<(b[0]^a[i])<<" ";
    }
    cout<<endl;
    

    return 0;
}
