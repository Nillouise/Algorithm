#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
//居然忘记用前缀和思想解这题
LL n,m,S;
pair<LL,LL> ran[200000+100];
pair<LL,LL> nod[200000+100];

LL pval[200000+100];//val的前缀和
LL pn[200000+100];


LL cal(LL w)
{
    for(int i=1;i<=n;i++)
    {
        if(nod[i].first>=w)
        {
            pn[i]=pn[i-1]+1;
            pval[i] = pval[i-1]+nod[i].second;
        }else{
            pn[i] = pn[i-1];
            pval[i] = pval[i-1];
        }
    }
    LL res = 0;
    for (int i = 0; i < m; i++) {
        LL l=ran[i].first,r=ran[i].second;
        res += (pn[r] - pn[l-1])*(pval[r]-pval[l-1]);
    }
    return res;
}



int main()
{
    
    ios::sync_with_stdio(false);
    
    cin>>n>>m>>S;
    for (int i = 1; i <= n; i++) {
        cin>>nod[i].first>>nod[i].second;
    }
    for (int i = 0; i < m; i++) {
        cin>>ran[i].first>>ran[i].second;
    }
    
    LL l=1,r=1e6+100;
    LL ans = 1e18;
    while(l<r-1)
    {
        LL w = (l+r)/2;
        LL cur = cal(w);
        // cout<<w<<" "<<cur-S<<endl;//
        ans = min(ans,abs(cur-S));
        // ans = abs(cur-S);//这是错的，因为中间结果,也有可能是最终答案，也就是说，
        if(cur>S)
        {
            l = w;
        }else if(cur == S)
        {
            break;
        }else{
            r = w;
        }
        
    }
    
    cout<<ans<<endl;//
    
    
    return 0;
}