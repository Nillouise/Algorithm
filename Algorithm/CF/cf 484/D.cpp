#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+100;
int L[maxn];
int R[maxn];
int n;
pair<int,int> dat[maxn];

int main()
{
    //freopen("I:\\Project\\acm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>dat[i].first;
        dat[i].second = i+1;
    }
    memset(L,-1,sizeof(L));
    memset(R,-1,sizeof(R));
    
    sort(dat,dat+n);
    
    map<int,int> cnt;
    int ans = 0;
    int MAX = 0;
    for (int i = 0; i < n; i++) {
        int w=dat[i].second;
        if(L[w-1]!=-1) {
            L[w]=L[w-1];
            int c = 1+R[w-1]-L[w-1];
            cnt[c]--;
            if(cnt[c]==0){
                auto it = cnt.find(c);
                cnt.erase(it);
            }
        }else{
            L[w]=w;
        }
        
        if(R[w+1]!=-1) {
            R[w] = R[w+1]; 
            int c = 1+R[w+1]-L[w+1];
            cnt[c]--;
            if(cnt[c]==0){
                auto it = cnt.find(c);
                cnt.erase(it);
            }
        }else{
            R[w] = w;
        }
        R[L[w]] = R[w];
        L[R[w]] = L[w]; 
        int c = R[w] - L[w]+1;
        cnt[c]++;
        if(cnt.size()==1){
            if(cnt.begin()->second>MAX){
                ans = dat[i].first+1;//这里我原本写成了ans = dat[i+1].first;这是误会了题意
                MAX = cnt.begin()->second;
            }
        }
        
    }
    cout<<ans<<endl;
    
    
    
    return 0;
}