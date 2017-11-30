#include<bits/stdc++.h>
using namespace std;
typedef long long LL;




int main()
{
    //freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\output.txt","w",stdout);//
    freopen("C:\\Users\\37\\Documents\\project\\atom\\Algorithm\\Algorithm\\input.txt","r",stdin);//

    ios::sync_with_stdio(false);

    LL n,m,a,d;
    
    cin>>n>>m>>a>>d;
    vector<LL> data(m);
    for (int i = 0; i < m; i++) 
    {
        cin>>data[i];
    }
    sort(data.begin(),data.end());
    m = unique(data.begin(),data.end())-data.begin();
    
    LL e=1,c=0;
    LL mod = d/a +1;
    LL cnt = 0;
    while(e<=n&&c<m)
    {
        // cout<<"e "<<e<<" c "<<c<<" cnt "<<cnt<<endl;
        if(a*e<data[c])
        {
            LL pre =  data[c]/a;
            pre = min(n,pre);//这里拉升 employee 是需要看是不是到底的
            LL curcnt = (pre-e)/mod+1;//注意pre-e 是要比正确数量少1的
            cnt+=curcnt;
            LL begin =a*(e + (curcnt-1)*mod);
            while(c<m&&begin+d>=data[c])c++;
            e = curcnt*mod+e;
        }else{
            cnt++;
            
            LL y = (data[c]+d)/a;
            LL j = c;
            while(j<m&&data[j]<=data[c]+d)j++;
            c=j;
            e=y+1;    
        }
    }    
    if(e<=n)
    {
        cnt+=(n-e)/mod+1;
    }
    while(c<m)
    {
        cnt++;
        LL j = c;
        while(j<m&&data[c]+d>=data[j])j++;
        c=j;
    }
    cout<<cnt<<endl;

    return 0;
}
