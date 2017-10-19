#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n;
vector<int> vec;
const int maxn=2e5+10;
int L[maxn];
int R[maxn];

int main()
{
    freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    memset(L,-1,sizeof(L));
    cin>>n;
    vec.resize(n);
    for (int i = 0; i < n; i++) {
        R[i]=n;
        cin>>vec[i];
    }
    
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        while(!stk.empty()&&vec[stk.top()]<vec[i])//这里是<，所以就是前面有数等于，也会停下扩展，也就是说，本位置的数是第一个最大的数（后面可能有数跟他一样大的）
        {
            stk.pop();
        }
        if(!stk.empty())L[i] = stk.top();
        stk.push(i);
    }
    
    int pre[50];//pre里储存着最近的对应bit是1的位置，这是因为题目的or的性质（以及最大数就是最大的覆盖范围）决定了可以这么做
    memset(pre,-1,sizeof(pre));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 30; j++) {
            if((1<<j)&vec[i])pre[j] = i;
            else L[i] = max(L[i],pre[j]);
        }
    }
    int suf[50];
    memset(suf,0x3f,sizeof(suf));
    
    for (int i = n-1; i >=0; i--) {
        for (int j = 0; j < 30; j++) {
            if((1<<j)&vec[i])suf[j] = i;
            else R[i] = min(R[i],suf[j]);
        }
    }
    LL ans = n*(n-1)/2;
    for (int i = 0; i < n; i++) {
        ans -= 1LL*(i-L[i])*(R[i]-i); // 这里要小心overflow！！！！
        ans++;//上面多减了（i,i)这个对。
    }
    cout<<ans<<endl;
    
    
    return 0;
}
