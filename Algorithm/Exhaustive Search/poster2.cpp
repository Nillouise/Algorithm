/**
 * vijos.org
 * Problem#1179
 * Accepted
 * Time:107ms
 * Memory:568k
 */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
int buf[45];
int ans[45];
int f[1001];
int n ,k;
int maxv = 0;
int cale(int count){
    if(!count)    return 0;
    memset(f, 0x7f, sizeof(f));
    f[0] = 0;
    int i = 1;
    do{
        for(int j = 1;j <= count && buf[j] <= i;j++)
            f[i] = min(f[i - buf[j]] + 1, f[i]);
    }while(f[i++] <= n);
    return i - 2;
}
void search(int sec){
    if(sec >= k){
        int c = cale(k);
        if(c <= maxv)    return;
        for(int i = 1;i <= k; i++)
            ans[i] = buf[i];
        maxv = c;
        return;
    }else{
        int temp = cale(sec);
        for(int i = temp + 1;i > buf[sec]; i--){
            buf[sec + 1] = i;
            search(sec + 1);
        }
    }
}
int main(){
    cin >> n >> k;
    search(0);
    for(int i = 1;i <= k;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    cout<<"MAX="<<maxv;
    return 0;
}
